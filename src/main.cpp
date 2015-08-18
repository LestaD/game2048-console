//
//  main.cpp
//  Game2048-console
//
//  Created by LestaD on 18.08.15.
//  Copyright (c) 2015 LestaD. All rights reserved.
//

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdio>

#include "game/game.h"
#include "render/engine.h"


int main(int argc, const char * argv[])
{
  struct winsize win;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

  printf("lines %d, columns %d\n", win.ws_row, win.ws_col);

  Render::Engine *render = new Render::Engine(win.ws_row, win.ws_col);
  Game::IGame *game = new Game::G2048(render);

  game->openMenu();
  int ch = '0';
  for (;;)
  {
    ch = std::getchar();
    game->sendKey(ch);
    game->tick();
    if (ch == 'q') break;
  }
  game->closeGame();
  game->destroyAll();
  return 0;
}

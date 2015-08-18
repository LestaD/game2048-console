#include "game.h"
#include <iostream>

namespace Game
{

G2048::G2048(Render::Engine * rendr) :
  m_Render(rendr)
{
  m_Render->emptyScreen();
  changeState(GAME_INIT);
}

G2048::~G2048()
{
  // ... Need to run destroy() or destroyAll()
}

void G2048::startSession()
{
  m_Render->emptyScreen();
  changeState(GAME_PLAY);
}

void G2048::endSession()
{
  if (m_State != GAME_PLAY) return;

  changeState(GAME_END);
}

void G2048::openMenu()
{
  changeState(GAME_MENU);
}

void G2048::closeGame()
{
  endSession();
  changeState(GAME_EXIT);
}

void G2048::destroy()
{
  delete this;
}

void G2048::destroyAll()
{
  m_Render->destroy();
  delete this;
}

void G2048::sendKey(int key)
{
  // ... run command
}

void G2048::tick()
{
  // ... run game logic
}

void G2048::changeState(GameState newstate)
{
  if (newstate != m_State)
  {
    char* state;
    switch (newstate) {
      case GAME_INIT:     state = "init";   break;
      case GAME_MENU:     state = "menu";   break;
      case GAME_PLAY:     state = "play";   break;
      case GAME_END:      state = "end";    break;
      case GAME_EXIT:     state = "exit";   break;

      default: state = "undefined"; break;
    }

    std::cout << "\rstate: " << state << std::endl;
    m_State = newstate;
    // run actions
    // ex.: rerender and game tick
  }
}

}




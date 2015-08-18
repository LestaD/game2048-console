#include "engine.h"
#include <iostream>

namespace Render
{


Engine::Engine(int lines, int columns) :
  win_width(columns), win_height(lines)
{
  std::system("stty raw");
  screen = new char[win_width * win_height];
}

Engine::~Engine()
{
  std::system("stty cooked");
  delete[] screen;
}

int Engine::getWidth()
{
  return win_width;
}

int Engine::getHeight()
{
  return win_height;
}

void Engine::emptyScreen()
{
  std::system("clear");
}

void Engine::destroy()
{
  delete this;
}


}
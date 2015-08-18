#include <iostream>
#include "engine.h"

namespace Render
{


Engine::Engine(int lines, int columns)
          : win_width(columns), win_height(lines)
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

void Engine::writeCenterLine(const char * text)
{
  std::cout << "\r";
  unsigned len = strlen(text);
  unsigned startFrom = getWidth() / 2 - len / 2;
  for (unsigned s = 0; s < startFrom; s++)
  {
    std::cout << " ";
  }
  std::cout << text;
  for (unsigned s = 0; s < startFrom; s++)
  {
    std::cout << " ";
  }
  std::cout << "\r\n";
}


}
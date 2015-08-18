#ifndef ENGINE_H
#define ENGINE_H

namespace Render
{

class Engine
{
public:
  Engine(int lines, int columns);
  ~Engine();

  int getWidth();
  int getHeight();

  void writeScreen();
  void emptyScreen();

  void destroy();

private:
  int win_width;
  int win_height;
  char * screen;
};

}

#endif // ENGINE_H
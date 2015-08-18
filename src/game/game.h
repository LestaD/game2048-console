#include "../render/engine.h"


namespace Game
{

enum GameState {
  GAME_INIT = 0,
  GAME_MENU,
  GAME_PLAY,
  GAME_END,


  GAME_EXIT = 99
};

class IGame
{
public:
  virtual void sendKey(int key) = 0;
  virtual void destroy() = 0;
  virtual void destroyAll() = 0;
  virtual void tick() = 0;
  virtual void openMenu() = 0;
  virtual void closeGame() = 0;
};


class G2048 : public IGame
{
public:
  G2048(Render::Engine * rendr);
  ~G2048();

  void startSession();
  void endSession();

  virtual void destroy();
  virtual void destroyAll();

  virtual void sendKey(int key);
  virtual void tick();

  virtual void openMenu();
  virtual void closeGame();

protected:

  void changeState(GameState newstate);

private:
  Render::Engine* m_Render;
  GameState m_State;
};




}
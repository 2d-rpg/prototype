#ifndef _GAME_H
#define _GMAE_H

enum GameState {
  GAME_MAINMENU, // main menu
};

class Game{
public:
  // game state
  GameState state;
  GLboolean keys[1024];
  GLuint width, height;

  // constructor/destructor
  Game(GLuint width, GLuint height);
  ~Game();

  // initialize game
  void init();

  // game loop
  void process_input(GLfloat dt);
  void update(GLfloat dt);
  void render();
}

#endif

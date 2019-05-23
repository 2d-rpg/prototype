#pragma once

// game states
enum GameState { GAME_MAIN_MENU, GAME_2D_MAP };

class Game {
private:
    // game state
    GameState state;
    GLboolean keys[1024], processed_keys[1024];
    GLuint    width, height;

public:
    // constructor/destructor
    Game(GLuint width, GLuint height);
    ~Game();

    // initialize game
    void init();

private:
    // game loop
    void process_input(GLfloat dt);
    void update(GLfloat dt);
    void render();
};

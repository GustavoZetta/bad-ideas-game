#pragma once

#include <chrono>
#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include "spriterenderer.hpp"
#include "window.hpp"

class Game {
  public:
    const std::chrono::nanoseconds NANOSECOND = std::chrono::nanoseconds(1000000000i64);
    const std::chrono::nanoseconds ONE_NANO = std::chrono::nanoseconds(1);
    int fps = 0;

    const bool debug;

    float value = 0.0f;

  public:
    // Starts the default variables and sets the
    // window title and the debug variable in the constructor.
    Game(bool debug);

    // Initializes window and renderer.
    void init();
    // Starts the game loop.
    // When game loop ends, it does not necessarily
    // sets m_running to false.
    void run();
    // Stops the engine
    // Sets m_running to false
    void stop();

    bool isRunning();

    // Setting anything below 1 will set the framerate to unlimited
    void setFramerate(int framerate);

  private:
    std::unique_ptr<Window> window;
    std::unique_ptr<SpriteRenderer> renderer;

    int m_framerate = 60;
    std::chrono::nanoseconds m_frametime = NANOSECOND / m_framerate;

    bool m_running;
    bool m_wireframe;

  private:
    void processInput();
    void update(float deltaTime);
    void render();
};
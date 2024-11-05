#pragma once

#include "SFML/Graphics.hpp"

class Window {
  public:
    Window();
    ~Window();

    void render();

    void pollEvents();

    sf::RenderWindow *getWindow();

  private:
    sf::Event event;
    sf::RenderWindow *window;
    sf::VideoMode videoMode;

    void initWindow();
};

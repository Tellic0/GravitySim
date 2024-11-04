#pragma once

#include "SFML/Graphics.hpp"

class Window {
private:
  sf::RenderWindow *window;
  sf::VideoMode videoMode;

  void initWindow();

public:
  Window();
  ~Window();

  void render();

  sf::RenderWindow *getWindow();
};

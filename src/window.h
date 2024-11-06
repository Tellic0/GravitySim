#pragma once

#include "SFML/Graphics.hpp"

class Window {
public:
  Window();
  ~Window();

  void pollEvents();

  bool isRunning();
  sf::RenderWindow *getWindow();

private:
  sf::Event event;
  sf::RenderWindow *window;
  sf::VideoMode videoMode;

  void initWindow();
};

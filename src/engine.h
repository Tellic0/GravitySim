#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "window.h"

class Engine {
public:
  // Initialization
  void initWindow();
  void TESTRECT();
  // Constructors and Destructors
  Engine();
  ~Engine();

  // Functions
  void update();
  void render();
  void run();

private:
  Window window;
  sf::RectangleShape TEST;
};

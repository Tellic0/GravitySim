#pragma once

#include <mutex>

#include "SFML/Graphics.hpp"

class Window {
public:
  void pollEvents();

  bool isRunning();

  static Window *getInstance();

  sf::RenderWindow *getWindow();

private:
  sf::Event event;
  sf::RenderWindow *window;
  sf::VideoMode videoMode;

  void initWindow();

  Window();
  ~Window();

  static Window *instancePtr;
  static std::mutex mtx;

  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;
};

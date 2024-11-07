#include "window.h"

Window *Window::instancePtr = nullptr;
std::mutex Window::mtx;

void Window::initWindow() {
  this->videoMode = sf::VideoMode(800, 800);
  this->window = new sf::RenderWindow(this->videoMode, "GravitySim");
}

Window::Window() : window(nullptr) { initWindow(); }

void Window::pollEvents() {
  while (this->window->pollEvent(this->event)) {
    switch (this->event.type) {
    case sf::Event::Closed:
      this->window->close();
      break;
    case sf::Event::KeyPressed:
      if (this->event.key.code == sf::Keyboard::Escape) {
        window->close();
      }
      break;
    }
  }
}

Window *Window::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mtx);
    if (instancePtr == nullptr) {
      instancePtr = new Window();
    }
  }
  return instancePtr;
}

sf::RenderWindow *Window::getWindow() { return this->window; }

bool Window::isRunning() { return window->isOpen(); }

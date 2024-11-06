#include "window.h"

void Window::initWindow() {
  this->videoMode = sf::VideoMode(800, 800);
  this->window = new sf::RenderWindow(this->videoMode, "GravitySim");
}

Window::Window() { this->initWindow(); }

Window::~Window() {}

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

bool Window::isRunning() { return this->window->isOpen(); }

sf::RenderWindow *Window::getWindow() { return this->window; }

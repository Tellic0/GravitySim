#include "window.h"

void Window::initWindow() {
  this->videoMode = sf::VideoMode(800, 800);
  this->window = new sf::RenderWindow(this->videoMode, "GravitySim");
}

Window::Window() { this->initWindow(); }

Window::~Window() {}

void Window::render() {
  this->window->clear();
  this->window->display();
}

sf::RenderWindow *Window::getWindow() { return this->window; }

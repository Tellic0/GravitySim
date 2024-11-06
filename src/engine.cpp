#include "engine.h"

void Engine::TESTRECT() {
  TEST.setSize(sf::Vector2f(20, 20));
  TEST.setPosition(sf::Vector2f(0, 0));
  TEST.setFillColor(sf::Color::Black);
}

Engine::Engine() { TESTRECT(); }

Engine::~Engine() {}

void Engine::update() {}

void Engine::render() {
  window.getWindow()->clear(sf::Color::Blue);
  window.getWindow()->draw(TEST);
  window.getWindow()->display();
}

void Engine::run() {
  while (window.isRunning()) {
    render();
    window.pollEvents();
  }
}

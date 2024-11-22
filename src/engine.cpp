//
// Created by tellico on 11/22/24.
//

#include "engine.h"

Engine *Engine::instance_ptr = nullptr;
std::mutex Engine::mtx;

void Engine::init_window() {
    window_class = Window::get_instance();
    window = window_class->get_window();
    if (window == nullptr) {
        std::cout << "nptr" << std::endl;
    }
}

Engine::Engine() { init_window(); }

Engine *Engine::get_instance() {
    if (instance_ptr == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance_ptr == nullptr) {
            instance_ptr = new Engine;
        }
    }
    return instance_ptr;
}

void Engine::update() {}

void Engine::render() { window->clear(sf::Color::Black); }

void Engine::run() {
    while (window_class->is_open()) {
        update();
        render();
    }
}

//
// Created by tellico on 11/22/24.
//

#include "window.h"

#include "window.h"

#include "globals.h"

Window *Window::instance_ptr = nullptr;
std::mutex Window::mtx;

void Window::init_window() {
    video_mode = sf::VideoMode(1920, 1080);
    window.create(video_mode, "GravitySim");
    window.setFramerateLimit(FRAMERATE);
}

Window::Window() { init_window(); }

void Window::poll_events() {
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            break;
        }
    }
}

Window *Window::get_instance() {
    if (instance_ptr == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance_ptr == nullptr) {
            instance_ptr = new Window();
        }
    }
    return instance_ptr;
}

sf::RenderWindow *Window::get_window() { return &window; }

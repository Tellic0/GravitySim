//
// Created by tellico on 11/22/24.
//

#include "engine.h"

Engine *Engine::instance_ptr = nullptr;
std::mutex Engine::mtx;

void Engine::init_classes() {
    window_class = Window::get_instance();
    window = window_class->get_window();
    object_manager_class = Object_Manager::get_instance();
}

Engine::Engine() {
    init_classes();
    test_game_container();
}

Engine *Engine::get_instance() {
    if (instance_ptr == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance_ptr == nullptr) {
            instance_ptr = new Engine;
        }
    }
    return instance_ptr;
}

void Engine::test_game_container() {
}


void Engine::update() {
    const std::chrono::microseconds frame_duration(1000000 / FRAMERATE);
    while (window->isOpen()) {
        auto frame_start = std::chrono::steady_clock::now();

        // Game updates

        // Checking if the frame took longer than expected to update
        auto frame_end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(frame_end - frame_start);
        if (elapsed < frame_duration) {
            std::this_thread::sleep_for(frame_duration - elapsed);
            break;
        } else {
            std::cout << "Frame took longer than expected!" << std::endl;
            break;
        }
    }
}

void Engine::render() {
    window->clear(sf::Color::Black);
    window->display();
}

void Engine::run() {
    while (window->isOpen()) {
        update();
        render();
        window_class->poll_events();
    }
}

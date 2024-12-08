//
// Created by tellico on 11/22/24.
//

#include "engine.h"
#include <vector>

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

// TEMPORARY
void Engine::test_game_container() {
}

void Engine::update() {
    const std::chrono::microseconds frame_duration(1000000 / FRAMERATE);
    while (window->isOpen()) {
        auto frame_start = std::chrono::steady_clock::now();

        // Game updates TEMP
        std::vector<unsigned long long int> to_delete;
        test_game_container();
        for (const auto &[id, obj] : *object_manager_class->get_game_container()) {
            if (obj) {
                obj->update_object();
                to_delete.push_back(obj->id);
            }
        }
        for (auto e : to_delete) {
            delete object_manager_class->get_objects_by_id(e);
        }
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

// Needs change !!!! TEMP
void Engine::render() {
    window->clear(sf::Color::Black);

    std::unordered_map<unsigned long long int, Object *> *game_container = object_manager_class->get_game_container();
    //const auto &[id, obj] : *game_container
    for (std::unordered_map<unsigned long long int, Object *>::iterator obj = game_container->begin();
         obj != game_container->end(); ++obj) {
        if (obj->second->should_be_drawn) {
            obj->second->draw_object(window);
        }
    }

    window->display();
}

void Engine::run() {
    while (window->isOpen()) {
        update();
        render();
        window_class->poll_events();
    }
}

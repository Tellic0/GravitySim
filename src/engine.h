//
// Created by tellico on 11/22/24.
//

#ifndef GRAVITYSIM_SRC_ENGINE_H
#define GRAVITYSIM_SRC_ENGINE_H

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "window.h"
#include "globals.h"
#include "objectmanager.h"
#include "object.h"

class Engine {
private:
    // Private constructors and destructors
    Engine();
    ~Engine() = default;

    // Thread safety
    static std::mutex mtx;

    // Pointer to an instance of the class
    static Engine *instance_ptr;

public:
    Engine(const Engine &obj) = delete;
    Engine &operator=(const Engine &) = delete;

    Window *window_class;
    Object_Manager *object_manager_class;

    sf::RenderWindow *window;

    static Engine *get_instance();

    // Initialization
    void init_classes();

    void update();
    void render();
    void run();
};

#endif//GRAVITYSIM_SRC_ENGINE_H

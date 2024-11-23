//
// Created by tellico on 11/22/24.
//

#ifndef GRAVITYSIM_SRC_WINDOW_H
#define GRAVITYSIM_SRC_WINDOW_H

#include <mutex>

#include <SFML/Graphics.hpp>

class Window {
private:
    sf::Event event;
    sf::RenderWindow window;
    sf::VideoMode video_mode;

    void init_window();

    Window();
    ~Window() = default;

    static Window *instance_ptr;
    static std::mutex mtx;

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

public:
    void poll_events();

    bool is_running();

    static Window *get_instance();

    sf::RenderWindow *get_window();
};

#endif//GRAVITYSIM_SRC_WINDOW_H

//
// Created by tellico on 11/22/24.
//

#ifndef GRAVITYSIM_SRC_OBJECT_H
#define GRAVITYSIM_SRC_OBJECT_H

#include <SFML/Graphics.hpp>

class Object_Manager;

class Object {
private:
    Object_Manager *object_manager;

public:
    virtual void update_object() = 0;
    virtual void draw_object(sf::RenderWindow *window) = 0;

    // Constructor and destructor
    Object();
    virtual ~Object();

    virtual const std::type_info &get_type();

    // Id in the game container
    unsigned long long int id;

    // Variables
    sf::Vector2f position;
    sf::Vector2f size;
    bool should_be_drawn = true;
    // TODO: add orientation
};

#endif//GRAVITYSIM_SRC_OBJECT_H

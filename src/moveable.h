//
// Created by tellico on 11/23/24.
//

#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <SFML/Graphics.hpp>

class Moveable {
public:
    virtual void move_object() = 0;

    float gravity = 0;

    float get_gravity() { return gravity; }

    void set_gravity(float i) { gravity = i; }

    sf::Vector2f movement_vector;
};

#endif//MOVEABLE_H

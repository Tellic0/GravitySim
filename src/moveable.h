//
// Created by tellico on 11/23/24.
//

#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <SFML/Graphics.hpp>

class Moveable {
public:
    virtual ~Moveable();

    virtual void move_object() = 0;

    bool is_moveable = true;

    sf::Vector2f movement_vector;
};

#endif //MOVEABLE_H

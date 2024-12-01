//
// Created by tellico on 11/23/24.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include "objectmanager.h"

class Drawable {
public:
    Drawable() {

    }

    virtual void draw_object(sf::RenderWindow *window) = 0;

    bool is_drawable = true;
};



#endif //DRAWABLE_H

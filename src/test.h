//
// Created by tellico on 11/23/24.
//

#ifndef TEST_H
#define TEST_H
#include "drawable.h"
#include "moveable.h"
#include "object.h"
#include "objectmanager.h"


class Test : public Object, public Drawable, public Moveable {
public:
    Object_Manager *object_manager_class;

    Test();
    ~Test();

    void draw_object(sf::RenderWindow *window) override;

    void update_object() override;

    void move_object() override;

    sf::RectangleShape rect;

    bool is_test;

};



#endif //TEST_H

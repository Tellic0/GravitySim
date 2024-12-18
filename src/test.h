//
// Created by tellico on 11/23/24.
//

#ifndef TEST_H
#define TEST_H
#include "moveable.h"
#include "object.h"
#include "objectmanager.h"

class Test final : public Object, public Moveable {
public:
    Object_Manager *object_manager_class;

    Test();

    void init_variables();

    void draw_object(sf::RenderWindow *window) override;

    void update_object() override;

    void move_object() override;

    sf::RectangleShape rect;

    bool is_test;
};

#endif//TEST_H

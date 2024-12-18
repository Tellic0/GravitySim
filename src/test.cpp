//
// Created by tellico on 11/23/24.
//

#include "test.h"

Test::Test() {
}

void Test::init_variables() {
    object_manager_class = Object_Manager::get_instance();
    rect.setSize(sf::Vector2f(200, 200));
    rect.setPosition(sf::Vector2f(0, 0));
    rect.setFillColor(sf::Color::Blue);
    movement_vector = sf::Vector2f(1, 0);
    is_test = true;
}

void Test::draw_object(sf::RenderWindow *window) {
    window->draw(rect);
}

void Test::move_object() {
    rect.move(movement_vector);
    rect.move(0, gravity);
}

void Test::update_object() {
    move_object();
}

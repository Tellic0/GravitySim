//
// Created by tellico on 11/23/24.
//

#include "test.h"

Test::Test() {
    object_manager_class = Object_Manager::get_instance();
    rect.setSize(sf::Vector2f(200, 200));
    rect.setPosition(sf::Vector2f(0, 0));
    rect.setFillColor(sf::Color::Blue);
    movement_vector = sf::Vector2f(1, 0);
    is_test = true;
}

Test::~Test() {
}

void Test::draw_object(sf::RenderWindow *window) {
    window->draw(rect);
}

void Test::move_object() {
    sf::Vector2f pos = rect.getPosition();
    pos += movement_vector;
    pos.y += gravity;
    rect.setPosition(pos);
}
void Test::update_object() {
    move_object();
}

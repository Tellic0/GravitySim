//
// Created by tellico on 11/22/24.
//

#include "objectmanager.h"
Object_Manager *Object_Manager::instance_ptr = nullptr;
std::mutex Object_Manager::mtx;

Object_Manager::Object_Manager() {
    object_count = 1;
}

Object_Manager::~Object_Manager() {
    for (auto &pair : game_container) {
        delete pair.second; // Clean up each dynamically allocated Object
    }
    game_container.clear();
}


Object_Manager *Object_Manager::get_instance() {
    if (instance_ptr == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance_ptr == nullptr) {
            instance_ptr = new Object_Manager;
        }
    }
    return instance_ptr;
}

unsigned long long int Object_Manager::get_current_id() {
    return object_count;
}

unsigned long long int Object_Manager::get_object_count() {
    return game_container.size();
}

Object *Object_Manager::get_object_by_id(unsigned long long id) {
    try {
        return game_container.at(id);
    } catch (std::out_of_range) {
        std::cout << "Could not find the object : out_of_range" << std::endl;
        return nullptr;
    }
}

void Object_Manager::add_object(Object *object) {
    game_container.emplace(object_count, object);
    increment_object_count();
}

void Object_Manager::delete_object(unsigned long long id) {
    Object *object = get_object_by_id(id);
    if (object != nullptr) {
        game_container.erase(id);
    }
}

void Object_Manager::increment_object_count() { object_count++; }
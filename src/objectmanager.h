//
// Created by tellico on 11/22/24.
//

#ifndef GRAVITYSIM_SRC_OBJECTMANAGER_H
#define GRAVITYSIM_SRC_OBJECTMANAGER_H

#include <iostream>
#include <map>
#include <mutex>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "object.h"

// A class that holds and manages the game_container an unordered_map of all the object in the game
class Object_Manager {
private:
    // Unordered map that holds all the objects in the game
    std::unordered_map<unsigned long long int, Object *> game_container;
    std::unordered_multimap<std::type_index, unsigned long long int> game_container_by_categories;

    unsigned long long int object_count;

    Object_Manager();
    ~Object_Manager();

    static Object_Manager *instance_ptr;

    static std::mutex mtx;

public:
    Object_Manager(const Object_Manager &obj) = delete;
    Object_Manager &operator=(const Object_Manager &) = delete;

    // Getters
    unsigned long long int get_current_id();
    unsigned long long int get_object_count();
    Object *get_objects_by_id(unsigned long long int object_id);
    static Object_Manager *get_instance();

    // Temp
    std::unordered_map<unsigned long long int, Object *> *get_game_container();

    // Add object to the container
    void add_object(Object *object);

    // Add object to the multimap
    template<typename T>
    void add_by_categories(T, unsigned long long int id);

    // Remove object from the container
    void delete_object(unsigned long long int id);

    // Increments object_count count by 1
    void increment_object_count();

    // Synchronizes the game_container and game_container by categories
    void update();
};

#endif//GRAVITYSIM_SRC_OBJECTMANAGER_H

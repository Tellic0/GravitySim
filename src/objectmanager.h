//
// Created by tellico on 11/22/24.
//

#ifndef GRAVITYSIM_SRC_OBJECTMANAGER_H
#define GRAVITYSIM_SRC_OBJECTMANAGER_H

#include <iostream>
#include <mutex>
#include <typeindex>
#include <unordered_map>

#include "object.h"

// A class that holds and manages the game_container an unordered_map of all the object in the game
class Object_Manager {
private:
    // Unordered map that holds all the objects in the game
    std::unordered_map<unsigned long long int, Object *> game_container;

    //boost::unordered_map<unsigned long long int, Object*> game_container;

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

    // Remove object from the container
    void delete_object(unsigned long long int id);

    // Increments object_count count by 1
    void increment_object_count();

    // Synchronizes the game_container and game_container by categories
    void update();
};

#endif//GRAVITYSIM_SRC_OBJECTMANAGER_H

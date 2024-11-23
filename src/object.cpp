//
// Created by tellico on 11/22/24.
//

#include "object.h"
#include "objectmanager.h"

Object::Object() {
    object_manager = Object_Manager::get_instance();
    id = object_manager->get_current_id();
    object_manager->add_object(this);
}

Object::~Object() {
    object_manager->delete_object(id);
}


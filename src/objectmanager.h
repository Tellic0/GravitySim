#pragma once

#include "object.h"

#include <iostream>
#include <iterator>
#include <unordered_map>

// Class for managing objects (id and map)
class ObjectManager {
public:
  // Constructor
  ObjectManager();

  // Getters
  static unsigned int getObjectCount();
  Object *getObjectById(unsigned int id);

  // Add a new object to the container
  void addObjectToContainer(Object *);

  // Delete an object to the container
  void deleteObject(unsigned int id);

  // increments objectCount by 1
  void incrementObjectCount();

private:
  // Unordered_map that holds all of the game objects
  static std::unordered_map<unsigned int, Object *> gameContainer;

  // Object count
  static unsigned int objectCount;
};

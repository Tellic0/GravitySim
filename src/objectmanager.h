#pragma once

#include "object.h"

#include <iostream>
#include <iterator>
#include <mutex>
#include <unordered_map>

// Class for managing objects (id and map)
class ObjectManager {
public:
  // Getters
  unsigned long long int getObjectCount();
  Object *getObjectById(unsigned int id);
  static ObjectManager *getInstance();

  // Add a new object to the container
  void addObjectToContainer(Object *);

  // Delete an object to the container
  void deleteObject(unsigned int id);

  // increments objectCount by 1
  void incrementObjectCount();

private:
  ObjectManager() = default;

  static ObjectManager *instancePtr;

  static std::mutex mtx;

  // Unordered_map that holds all of the game objects
  std::unordered_map<unsigned int, Object *> gameContainer;

  // Object count
  unsigned long long int objectCount;
};

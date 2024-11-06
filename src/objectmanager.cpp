#include "objectmanager.h"

unsigned int ObjectManager::getObjectCount() { return objectCount; }

Object *ObjectManager::getObjectById(unsigned int id) {
  for (auto i : gameContainer) {
    if (i.first == id) {
      return i.second;
    }
  }
  std::cout << "No object found in game container" << std::endl;
  return 0;
}

void ObjectManager::incrementObjectCount() { objectCount++; }

void ObjectManager::addObjectToContainer(Object *object) {
  gameContainer.insert({objectCount, object});
  incrementObjectCount();
}

void ObjectManager::deleteObject(unsigned int id) {
  auto iter = gameContainer.find(id);
  if (iter != gameContainer.end()) {
    gameContainer.erase(id);
  }
}

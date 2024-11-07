#include "objectmanager.h"

ObjectManager *ObjectManager::instancePtr;
std::mutex ObjectManager::mtx;

unsigned long long int ObjectManager::getObjectCount() { return objectCount; }

Object *ObjectManager::getObjectById(unsigned int id) {}

ObjectManager *ObjectManager::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mtx);
    if (instancePtr == nullptr) {
      instancePtr = new ObjectManager();
    }
  }
  return instancePtr;
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

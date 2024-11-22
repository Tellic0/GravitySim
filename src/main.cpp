#include "engine.h"

#include <iostream>

int main() {
    Engine *engine = Engine::get_instance();
    engine->run();
}
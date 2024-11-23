#include "engine.h"

int main() {
    Engine *engine = Engine::get_instance();
    engine->run();
}
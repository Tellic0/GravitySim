#include "engine.h"

int main() {
    Window window;

    while (window.getWindow()->isOpen()) {
        window.render();
        window.pollEvents();
    }
}

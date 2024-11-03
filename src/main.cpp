#include "SFML/Graphics.hpp"

int main() {
  sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 800), "SFML");

  while (window.isOpen()) {

    sf::Event event;

    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed)
        window.close();
    }
    // dsafdsfsfs
    window.clear(sf::Color::Black);
    window.display();
  }

  return 0;
}

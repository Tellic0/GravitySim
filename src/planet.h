#include "SFML/Graphics.hpp"
#include "math.h"
#include "object.h"

// The celestial body that the objects will gravitate towards
class Planet : public Object {
    double radius;
    double mass;
    sf::CircleShape circle;

    double calculate_grav_force() {
        double gravitational_constant = 6.67430e-11;
        return (gravitational_constant * mass) / std::pow(radius, 2);
    }
};

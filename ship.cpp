#include "ship.h"

Ship::Ship() {
    //set origin for sprite
    if(!sTexture.loadFromFile("Pictures/boat_sprite.png"))
        std::cout << "Could not load boat_sprite.png" << std::endl;

    ship_image.setTexture(sTexture);
    ship_image.setOrigin(10, 100);  //guesses for origin

    position.x = 0;
    position.y = 0;
    speed = 1000.0;
    rotation_speed = 500;
    brotation_speed = -500;
    health = 100;
    direction = 0;

    Gun gun1();
}

sf::Vector2f Ship::get_position()
{
    return position;
}

float Ship::get_speed()
{
    return speed;
}

float Ship::get_rotation_speed()
{
    return rotation_speed;
}

int Ship::get_health()
{
    return health;
}

float Ship::get_direction()
{
    return ship_image.getRotation();
}

void Ship::move_forward(float elapsed)
{
    float angle = ((ship_image.getRotation() * M_PI ) / 180) - M_PI;
    ship_image.move(-speed * elapsed * std::sin(angle), speed * elapsed * std::cos(angle));
    position = ship_image.getPosition();
}

void Ship::rotate_cw(float elapsed)
{
    ship_image.rotate(rotation_speed * elapsed);
}
void Ship::rotate_ccw(float elapsed)
{
    ship_image.rotate(brotation_speed * elapsed);
}
void Ship::move_backwards(float elapsed)
{
    float angle = ((ship_image.getRotation() * M_PI ) / 180) - M_PI;
    ship_image.move((speed * elapsed * std::sin(angle) ) / 5, (-speed * elapsed * std::cos(angle)) / 5);
    position = ship_image.getPosition();
}

void Ship::fire_gun()
{
    gun1.fire();
}

void Ship::refresh_gun()
{
    gun1.set_positions(ship_image.getPosition().x, ship_image.getPosition().y);
}

void Ship::change_guns_direction(float new_angle)
{
    gun1.change_direction(new_angle);
}

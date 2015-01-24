#include "gun.h"
Gun::Gun()
{
    if(!gun_texture.loadFromFile("Pictures/cannon1.jpg"))
        std::cout << "Error loading cannon1.jpg from file" << std::endl;

    gun_sprite.setTexture(gun_texture);
    gun_sprite.setOrigin(15, 50);
    gun_sprite.setPosition(50, 0);
    position.x = 50;
    position.y = 0;
    ammo = 10;
}


sf::Vector2f Gun::get_position()
{
    return position;
}
float Gun::get_direction()
{
    return direction;
}

int Gun::get_ammo()
{
    return ammo;
}

void Gun::fire()
{
    projectiles.push_back(new Bullet(position, direction));
}

void Gun::set_positions(float x, float y)
{
    gun_sprite.setPosition(x, y);
    position.x = x;
    position.y = y;
    gun_sprite.setRotation(direction);

}

void Gun::change_direction(float angle)
{
    direction = (angle / M_PI) * 180 + 270;
}

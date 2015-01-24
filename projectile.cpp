#include "projectile.h"

#define PROJECTILE_SPEED 2000
Projectile::Projectile()
{
    position.x = 0;
    position.y = 0;
    speed = PROJECTILE_SPEED;
    direction = 0;
    range = 100000;
    lifetime = 0;
}

Projectile::Projectile(sf::Vector2f pposition, float pdirection)
{
    position.x = pposition.x;
    position.y = pposition.y;
    speed = PROJECTILE_SPEED;
    direction = pdirection;
    range = 100000;
    lifetime = 0;
}


Projectile::~Projectile()
{

}



float Projectile::get_speed()
{
    return speed;
}
float Projectile::get_direction()
{
    return direction;
}
float Projectile::get_range()
{
    return range;
}

void Projectile::refresh(float elapsed)
{
    position.x = position.x + std::cos(direction) * speed * elapsed;
    position.y = position.y + std::sin(direction) * speed * elapsed;
    lifetime++;
}

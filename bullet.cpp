#include "bullet.h"
Bullet::Bullet() : Projectile()//check this
{
    bullet_sprite.setRadius(10);
    bullet_sprite.setFillColor(sf::Color(100, 250, 50));
}


Bullet::Bullet(sf::Vector2f bposition, float bdirection) : Projectile(bposition, bdirection)
{
    bullet_sprite.setRadius(10);
    bullet_sprite.setPosition(bposition.x, bposition.y);
    bullet_sprite.setFillColor(sf::Color(255, 50, 0));
}

//destructor
Bullet::~Bullet()
{

}



void Bullet::refresh_this(float elapsed)
{

    position.x = position.x + std::cos(get_direction() * M_PI / 180 + (3 * M_PI / 2)) * get_speed() * elapsed;
    position.y = position.y + std::sin(get_direction() * M_PI / 180 + (3 * M_PI / 2)) * get_speed() * elapsed;
    bullet_sprite.setPosition(position.x, position.y);
    lifetime++;

}

sf::CircleShape Bullet::get_sprite()
{

    return bullet_sprite;
}

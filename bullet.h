#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include "projectile.h"
class Bullet: public Projectile
{
public:
    Bullet();
    Bullet(sf::Vector2f bposition, float bdirection);
    sf::CircleShape bullet_sprite;
    sf::CircleShape get_sprite();
    ~Bullet();

    void refresh_this(float elapsed);

private:

};


#endif // BULLET_H_INCLUDED

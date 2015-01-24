#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

class Projectile{
public:
    Projectile();
    Projectile(sf::Vector2f pposition, float pdirection);
    virtual ~Projectile();
    virtual float get_speed();
    virtual float get_direction();
    virtual float get_range();
    virtual void refresh(float elapsed);
    virtual sf::CircleShape get_sprite() = 0;
    sf::Vector2f position;
    sf::CircleShape bullet_sprite;
    unsigned long lifetime;

private:
    float speed;
    float direction;
    unsigned long range;



};

#endif // PROJECTILE_H_INCLUDED

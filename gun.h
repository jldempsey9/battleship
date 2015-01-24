#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED
#include <vector>
#include "bullet.h"
#include "projectile.h"
#include <iostream>


class Gun{
public:
    Gun();      //draw gun on ship, set origin for sprite

    sf::Vector2f get_position();
    float get_direction();
    int get_ammo();
    sf::Texture gun_texture;
    sf::Sprite gun_sprite;
    void set_positions(float x, float y);

    void fire();
    void deploy_shield();
    void change_direction(float angle);

    std::vector<Bullet*> projectiles;

private:
    sf::Vector2f position;
    float direction;
    int ammo;


};


#endif // GUN_H_INCLUDED

#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "gun.h"

class Ship{
public:
    Ship(); //set the origin for sprite
    sf::Vector2f get_position();
    float get_speed();
    float get_rotation_speed();
    int get_health();
    float get_direction();
    sf::Sprite ship_image;
    sf::Texture sTexture;
    void move_forward(float elapsed);   //elapsed time as seconds
    void rotate_cw(float elapsed);
    void rotate_ccw(float elapsed);
    void move_backwards(float elapsed);
    void teleport();
    void fire_gun();
    void refresh_gun();
    void change_guns_direction(float new_angle);
    Gun gun1;


private:

    sf::Vector2f position;
    float speed;
    float rotation_speed;
    int health;
    float direction;
    float brotation_speed;

};


#endif // SHIP_H_INCLUDED

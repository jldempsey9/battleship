#ifndef SHIELD_H_INCLUDED
#define SHIELD_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
class Shield{
public:
    Shield();
    float get_angle();
    sf::Vector2i get_position();
    int get_time_left();
private:
    //sprite;
    float angle;
    sf::Vector2i position;
    int time_left;



};

#endif // SHIELD_H_INCLUDED

#ifndef PACKET_OVERLOADS_H_INCLUDED
#define PACKET_OVERLOADS_H_INCLUDED
#include <SFML/Network.hpp>

//ship overloads
sf::Packet& operator <<(sf::Packet& packet, const Ship& ship)
{
    return packet << ship.get_position().x << ship.get_position().y <<
        ship.get_health() << ship.get_direction();
}

sf::Packet& operator >>(sf::Packet& packet, Ship& ship)
{
    return packet >> ship.get_position().x >> ship.get_position().y >>
        ship.get_health() >> ship.get_direction();
}


//bullet overloads
sf::Packet& operator <<(sf::Packet& packet, const Bullet& bullet)
{
    return packet << bullet.position.x << bullet.position.y << bullet.get_speed() << bullet.get_direction();

}


sf::Packet& operator >> (sf::Packet& packet, Bullet& bullet)
{
    return packet >> bullet.position.x >> bullet.position.y >> bullet.get_speed() >> bullet.get_direction();

}






#endif // PACKET_OVERLOADS_H_INCLUDED

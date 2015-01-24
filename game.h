#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "ship.h"
#include "menu.h"
//#include "packet_overloads.h"


class Game
{
public:
    Game();
    void play();
    void refresh(float elapsed);    //elapsed time
    bool is_running();
    void connect_to_server();
    void unpause();
    void send_server_ships();
    void send_server_bullet(Bullet* b);


private:
    sf::Vector2f screenDimensions;
    sf::RenderWindow window;
    std::vector<Ship*> player_list;

    sf::Texture game_map_texture;
    sf::Sprite game_map;
    sf::Event event;
    Ship* player;
    sf::Clock clock_main;
    float elapsed_time;

    sf::View players_view;
    sf::Vector2f delta; //for players view camera movement
    Menu pause_menu;
    bool paused;

    //sf::UdpSocket usocket;
    //sf::IpAddress server_address;
    unsigned short port;

};


#endif // GAME_H_INCLUDED

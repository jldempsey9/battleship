#include "game.h"


Game::Game()
{
    paused = true;
    clock_main.restart();

    sf::Vector2f screenDimensions(800.0f, 600.0f);
    //window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Battleship");
    window.setVerticalSyncEnabled(true);

    players_view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));    //view centered on players position and 200, 200 dimensions
    sf::Vector2f delta(0, 0);       //for players view camera movement

    player_list.push_back(new Ship());
    player = player_list[0];

    if(!game_map_texture.loadFromFile("Pictures/oceanmap.png"))
    {
        std::cout << "Error loading map";
    }
    game_map.setTexture(game_map_texture);

    Menu pause_menu(screenDimensions.x, screenDimensions.y);



    //bind socket
    /*
    usocket.setBlocking(false);
    if(usocket.bind(7551) != sf::Socket::Done)
    {
        std::cout << "Could not bind to socket 7551" << std::endl;
    }

    port = 7551;
    */
}

void Game::play()
{
    	// Start the game loop
    sf::Vector2f screenDimensions(800.0f, 600.0f);
    window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Battleship");
    players_view.setSize(2500, 2500);
    while (window.isOpen())
    {
            //start basic window operations
        window.clear();
        window.setView(players_view);

            //draw the map
        window.draw(game_map);

            //main clock
        elapsed_time = clock_main.restart().asSeconds();











        refresh(elapsed_time);      //live keyboard input, keeping gun on top of ship









        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();

                break;

            case sf::Event::KeyPressed:

                switch (event.key.code)
                {

                    //debugging (mouse positions when \)
                case sf::Keyboard::BackSlash:

                    std::cout << "Mouse position  (Window:) " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y
                     << "  " << "(Global:)  " << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl;

                    /*
                    //screen dimensions:

                    std::cout << "Screen dimensions x: " << screenDimensions.x << " y: " << screenDimensions.y << std::endl;


                    //screen views center

                    std::cout << "players view x: " << players_view.getCenter().x << " y : " << players_view.getCenter().y << std::endl;

                    */
                    std::cout << "player's position (x:) " << player->ship_image.getPosition().x << " (y:) " << player->ship_image.getPosition().y << std::endl;
                    break;




                case sf::Keyboard::Escape:
                    paused = true;
                    window.close();
                    break;


                    //menu commands
                case sf::Keyboard::Down:
                    pause_menu.MoveDown();
                    break;

                case sf::Keyboard::Up:
                    pause_menu.MoveUp();
                    break;

                case sf::Keyboard::Return:
                    switch(pause_menu.GetPressedItem())
                    {
                    case 0:
                        paused = false;
                        break;

                    case 1:
                        std::cout << "Not implemented yet" << std::endl;
                        break;

                    case 3:
                        std::cout << "Game now closing" << std::endl;
                        window.close();
                        break;

                    default:
                        std::cout << "Not implemented yet" << std::endl;
                        break;
                    }
                    break;





                default:
                    break;

                }
                break;

            case sf::Event::MouseButtonPressed:
                switch(event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    player->fire_gun();
                    std::cout << "gun fired" << std::endl;
                    //send_server_bullet(player->gun1.projectiles.back());

                    break;


                    //method for moving the camera
                case sf::Mouse::Middle:
                    delta = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    players_view.setCenter(delta);
                    break;

                default:
                    break;
                }
                break;


            default:
                break;


            }
        }





        //draw all objects here
    for (unsigned int i = 0; i < player_list.size(); i++)
    {
        window.draw(player_list[i]->ship_image);
        window.draw(player_list[i]->gun1.gun_sprite);
        for (unsigned int j = 0; j < player_list[i]->gun1.projectiles.size(); j++)
        {
            window.draw(player_list[i]->gun1.projectiles[j]->bullet_sprite);
        }

    }




    if(paused)
    {
        pause_menu.draw(window);
    }





        window.display();


    }
}





void Game::refresh(float elapsed)    //manages movement, gui, bullet movement
{
    //handling live keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player->move_forward(elapsed);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player->rotate_ccw(elapsed);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player->move_backwards(elapsed);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player->rotate_cw(elapsed);
    }



        //recenter the camera on player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        players_view.setCenter(player->ship_image.getPosition().x, player->ship_image.getPosition().y);

    }






        //rotate the gun by changing player position to pixels and trig between mouse position
        //and player position
        //cannot divide by zero,
    sf::Vector2i playerPixelPos = window.mapCoordsToPixel(player->ship_image.getPosition());
    sf::Vector2f deltagun((playerPixelPos.x - sf::Mouse::getPosition(window).x), (playerPixelPos.y - sf::Mouse::getPosition(window).y));

    if (deltagun.x < 0) //domain of tangent is pi to -pi
    {
        player->change_guns_direction(M_PI -(std::atan(deltagun.y / -deltagun.x)));
    }
    else
        player->change_guns_direction(std::atan(deltagun.y / deltagun.x));






        //refreshing bullets
    for (unsigned int i = 0; i < player_list.size(); i++)
    {
        for (unsigned int j = 0; j < player_list[i]->gun1.projectiles.size(); j++)
        {
            player_list[i]->gun1.projectiles[j]->refresh_this(elapsed);

            if(player_list[i]->gun1.projectiles[j]->lifetime > player_list[i]->gun1.projectiles[j]->get_range())
            {
                player_list[i]->gun1.projectiles.pop_back();
            }
        }

    }








    for (unsigned int i = 0; i < player_list.size(); i++)
    {
        player_list[i]->refresh_gun();
    }

}

void Game::unpause()
{
    paused = false;
}

/*
void Game::connect_to_server()
{
    sf::Packet packet;
    packet << *player;
    usocket.send(packet, server_address, port);
}



void Game::send_server_ships()
{
    sf::Packet packet;
    packet << *player;  //ships
    usocket.send(packet, server_address, port);
}

void Game::send_server_bullet(Bullet* b)
{
    sf::Packet packet;
    packet << *b;
    usocket.send(packet, server_address, port);
}
*/

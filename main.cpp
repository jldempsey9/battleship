#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    Game game;
    //sf::Thread thread(&Game::play, &game);
    //thread.launch();
    game.play();

    return EXIT_SUCCESS;
}

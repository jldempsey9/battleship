#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <string>
class Button{
public:
    Button();

private:
    sf::Vector2i position;
    std::string text;
    //collision box


};

#endif // BUTTON_H_INCLUDED

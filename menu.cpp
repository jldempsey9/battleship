#include "menu.h"

Menu::Menu()
{

}

Menu::Menu(float width, float height)
{
    selector_iterator = 0;

    //load font
    if(!font.loadFromFile("Fonts/TlwgMono-Bold.otf"))
    {
        //throw error
    }
    text[0].setFont(font);
    text[1].setFont(font);
    text[2].setFont(font);
    text[3].setFont(font);
    text[0].setString("Play");
    text[1].setString("Options");
    text[2].setString("Connect");
    text[3].setString("Exit");
    text[0].setColor(sf::Color::Red);
    text[1].setColor(sf::Color::White);
    text[2].setColor(sf::Color::White);
    text[3].setColor(sf::Color::White);

    //sets position of menu items
    text[0].setPosition(sf::Vector2f(width/2, height / 5 * 1));
    text[1].setPosition(sf::Vector2f(width/2, height / 5 * 2));
    text[2].setPosition(sf::Vector2f(width/2, height / 5 * 3));
    text[3].setPosition(sf::Vector2f(width/2, height / 5 * 4));


}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 4; i ++)
    {
        window.draw(text[i]);
    }
}
void Menu::MoveUp()
{
    if (selector_iterator > 0 )
    {
        text[selector_iterator].setColor(sf::Color::White);
        selector_iterator--;
        text[selector_iterator].setColor(sf::Color::Red);

    }

}

void Menu::MoveDown()
{
    if (selector_iterator <= 2)
    {
        text[selector_iterator].setColor(sf::Color::White);
        selector_iterator++;
        text[selector_iterator].setColor(sf::Color::Red);
    }

}
int Menu::GetPressedItem()
{
    return selector_iterator;
}
Menu::~Menu()
{

}

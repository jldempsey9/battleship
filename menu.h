#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SFML/Graphics.hpp>

class Menu{
public:
    Menu();
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow &window);

    void MoveUp();
    void MoveDown();
    int GetPressedItem();
private:
    sf::Font font;
    sf::Text text[4];
    int selector_iterator;

};

#endif // MENU_H_INCLUDED

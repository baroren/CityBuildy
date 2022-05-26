#pragma once

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Window.h"
#include <string>
#include <iostream>
#include "Resources.h"
class SideMenu {
public:
    SideMenu();
    void createButton(string ,int x,int y,int,int);
    int handleClick(const sf::Vector2f position,sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
private:
    vector <sf::Sprite> m_buttons;
    sf::Sprite test;
    //  sf::Texture m_helpTex;
    sf:: Font m_font;
    bool m_helpPressed;
    sf:: Sprite m_help ; //need to make vector
};
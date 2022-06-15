#pragma once

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Window.h"
#include <string>
#include <iostream>
#include "Resources.h"
#include <string>

using std::string;
class SideMenu {
public:
    SideMenu();
    void createButton(string ,int x,int y,int,int);
    int handleClick(const sf::Vector2f position);
    void draw(sf::RenderWindow& window);
    string getPrice(int id);
    int getSize(){return m_buttons.size();};
private:
    vector <sf::Sprite> m_buttons;
    sf::Sprite test;

    //  sf::Texture m_helpTex;
    sf:: Font m_font;
  // bool m_helpPressed;
    sf:: Sprite m_help ; //need to make vector
};
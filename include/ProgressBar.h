#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "PlacebleObject.h"

class ProgressBar{
public:
    ProgressBar(float x=0,float y=0,float width=0, float height=0,bool bg=false,sf::Color color=sf::Color::Red,int m_rate=10);
    ~ProgressBar();
    void progressBarDraw(sf::RenderWindow &window);
    void pgUpdate(){m_barInner.setSize(sf::Vector2f(m_width-=m_rate,30));};
private:
    sf::RectangleShape m_barBack;
    sf::RectangleShape m_barInner;
    std::string barString;
    sf::Text text;
    float m_width;
    int m_rate;


};
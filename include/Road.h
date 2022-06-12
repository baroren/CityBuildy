#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
class Road: public Conectors {
public:
  using Conectors::Conectors;

  /*  bool checkClick(sf::Vector2f pos){return m_obj.getGlobalBounds().contains(pos);}
    void rotate() ;
    void show(sf::RenderWindow &window);
    void setPos(int x,int y);
    int returnID();
    void print();
    bool checkIfContained(sf::FloatRect  bound );
    sf::FloatRect  bound();*/

private:
 //   sf::Sprite m_obj;

    std::pair<int,int>pos;

};
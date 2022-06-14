#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
#include "Area.h"

class Residence :public Area {
public:
   /* Residence(sf::Vector2f pos, int row, int col, gameObjectId id) :Area(pos, row, col, id) {
        m_obj = *Resources::instance().getSprite(gameObjectId::resPlace);
        m_obj.setPosition(pos);
        m_obj.scale(PlacebleObjectFactor, PlacebleObjectFactor);
    }

    bool checkClick(sf::Vector2f pos) { return m_obj.getGlobalBounds().contains(pos); }
    void rotate() { m_obj.setRotation(90.f); };
    void show(sf::RenderWindow& window) { window.draw(m_obj); };
    void setPos(int x, int y) { m_obj.setPosition(x, y); };
    int returnID() { return id; };
    void print() { std::cout << "roads"; };
    bool checkIfContained(sf::FloatRect  bound ){std::cout<<"#######\n";return  m_obj.getGlobalBounds().intersects(bound);};
    sf::FloatRect  bound(){return m_obj.getGlobalBounds();};*/
   using Area::Area;
    // int residanceCount() override{return residanceRegHouse;};
     void updateRes();
     int getResNum(){return 30;};


private:
    //sf::Sprite m_obj;
    int m_ressidance=30;
    // sf::Sprite m_obj;
   // int id = 1;
    std::pair<int, int>pos;

};
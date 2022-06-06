#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"

class PlacebleObject {
public:
    PlacebleObject(sf::Vector2f pos,int row,int col,gameObjectId id){}
    virtual   ~PlacebleObject(){}
    virtual void show(sf::RenderWindow &window) =0;
    virtual void setPos(int x,int y)=0;
    virtual void print()=0;
    virtual int returnID()=0;
    virtual void rotate() = 0;
     virtual bool checkClick(sf::Vector2f pos)=0;
   virtual bool checkIfContained(sf::FloatRect  bound )=0;
  virtual  sf::FloatRect  bound()=0;

   // bool checkIfContained(sf::FloatRect  bound ){return  m_obj.getGlobalBounds().intersects(bound);};
  //  sf::FloatRect  bound(){return m_obj.getGlobalBounds();};
private:
    sf::Sprite m_obj;
    std::pair<int,int>index;
};
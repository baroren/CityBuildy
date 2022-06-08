#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
class Ground:public PlacebleObject {
public:
    /*Ground(sf::Vector2f pos,int row,int col,gameObjectId id):PlacebleObject(pos ,row,col,id) {
         m_obj=*Resources::instance().getSprite(gameObjectId::TileSheet);
         m_obj.setPosition(pos);
     m_obj.scale(FACTOR,FACTOR);}
     */
    using PlacebleObject::PlacebleObject;

    
  /*  void rotate() {
        std::cout << "test"; };
    bool checkClick(sf::Vector2f pos){return m_obj.getGlobalBounds().contains(pos);}
    void show(sf::RenderWindow &window) {window.draw(m_obj);}
    void print(){std::cout<<"test";};
    void setPos(int x,int y){m_obj.setPosition(x,y);};
    int returnID(){return id;};
   bool checkIfContained(sf::FloatRect  bound ){return  m_obj.getGlobalBounds().intersects(bound);};
    sf::FloatRect  bound(){return m_obj.getGlobalBounds();};

*/
private:
    //sf::Sprite m_obj;
  //  int id=0;
    std::pair<int,int>pos;

};
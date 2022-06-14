#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "PlacebleObject.h"

class Player {
public:
    Player(){}
    int getMoney(){return m_money;};
    int getRes(){return m_ressidance;};

    void transaction(int amount){m_money+=amount;};
    bool gameOver(){return m_money<=0;};
    void ressidanceAdd(int amount){

        if(m_ressidance<60*m_numOfTotalBuildings)//100 tonst (max per building )
            m_ressidance+=amount;
    };
    void numOfTotalBuildings(int amount,int res){m_numOfTotalBuildings+=amount;
    m_ressidance-=res;};
    // Conectors(const sf::Vector2f &pos,) : PlacebleObject(pos) {}

private:
    int m_money=10000;
    int m_ressidance=0;
    int m_numOfTotalBuildings=0;
    int m_taxes;
    int m_happyRes=100;
    int m_happyCom;

};
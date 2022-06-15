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
    int getBuilding(playerData id){return m_building[int(id)];};
    void transaction(int amount){m_money+=amount;};
    bool gameOver(){return m_money<=0;};
    bool gameWin(){if(m_money>=30 && m_ressidance>=30) return true;
   else  return false;};
    void ressidanceAdd(int amount){

        if(m_building[int(playerData::resBuilsing)]>visted) {
            if (m_building[int(playerData::resBuilsing)] < 60 * m_building[int(playerData::resBuilsing)])//100 tonst (max per building )
                m_ressidance += amount;
            if(m_building[int(playerData::resBuilsing)]==0)
                m_ressidance=0;
            visted++;
        }

    };
    void numOfTotalBuildings(int amount,int res,playerData id){m_building[int(id)]+=amount;
    if(id==playerData::resBuilsing &&m_ressidance>0)m_ressidance-=res;}
    void setMoney(int amount ){m_money=amount;std::cout<<"in player "<<amount;};
    void setRes(int amount){m_ressidance=amount;};


    void noPoweredHouse(){
        if(m_ressidance>m_building[int(playerData::resBuilsing)]*2 && m_happyRes>0)
            m_ressidance-=1;
        m_happyRes-=1;};

    // Conectors(const sf::Vector2f &pos,) : PlacebleObject(pos) {}

private:
    int m_money=49900;
    int m_ressidance=500;
std::array<int,3> m_building ={0,0,0};
int m_taxes;
    int m_happyRes=1000;
    int m_happyCom;
    int visted=0;

};
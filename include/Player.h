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
    void transaction(int amount){m_money+=amount;};
    bool gameOver(){return m_money<=0;};
    // Conectors(const sf::Vector2f &pos,) : PlacebleObject(pos) {}

private:
    int m_money=100;
    int m_taxes;
    int m_happyRes;
    int m_happyCom;

};
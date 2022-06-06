#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
class Commercial :public Area {
public:
    Commercial(sf::Vector2f pos, int row, int col, gameObjectId id) :Area(pos, row, col, id) {
        m_obj = *Resources::instance().getSprite(gameObjectId::comPlace);
        m_obj.setPosition(pos);
        m_obj.scale(FACTOR/1.5, FACTOR/1.5);
    }

    bool checkClick(sf::Vector2f pos) { return m_obj.getGlobalBounds().contains(pos); }
    void rotate() { m_obj.setRotation(90.f); };
    void show(sf::RenderWindow& window) { window.draw(m_obj); };
    void setPos(int x, int y) { m_obj.setPosition(x, y); };
    int returnID() { return id; };
    void print() { std::cout << "roads"; };
private:
    sf::Sprite m_obj;
    int id = 1;
    std::pair<int, int>pos;

};
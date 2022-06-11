#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Animation.h"
class PlacebleObject {
public:
    PlacebleObject(sf::Vector2f pos, int row, int col, gameObjectId id,
                   int factor, int idN, int rate, int cost, int maint) {
        m_obj = *Resources::instance().getSprite(id);

        m_animation =new Animation(Resources::instance().getTexture(id)
              ,sf::Vector2u(Resources::instance().getImageCount(id),Resources::instance().getImageCount(id)),
                            2);

        m_obj.setPosition(pos);
        m_obj.scale(factor, factor);
        m_id = idN;
        m_rate = rate;
        m_buildCost = cost;
        m_maintance = maint;

    }

    virtual   ~PlacebleObject() {}

    virtual void show(sf::RenderWindow &window,int animState,float deltaTime) {
        m_animation->update(currAnim,deltaTime);
        m_obj.setTextureRect((m_animation->getRect()));

        window.draw(m_obj); };

    virtual void setPos(int x, int y) { m_obj.setPosition(x, y); };

    virtual void print() { std::cout << "roads"; };

    virtual int returnID() { return m_id; };

    virtual void rotate() { m_obj.setRotation(90.f); };

    virtual bool checkClick(sf::Vector2f pos) { return m_obj.getGlobalBounds().contains(pos); };

    virtual bool checkIfContained(sf::FloatRect bound) { return m_obj.getGlobalBounds().intersects(bound); };

    virtual sf::FloatRect bound() { return m_obj.getGlobalBounds(); };

    virtual int calcRate() { return m_rate; };

    virtual int buildCost() { return m_buildCost; };

    virtual int maintanceCost() { return m_maintance; };

    virtual void connectRoad(bool connect){m_roadConnected = connect;};

    virtual void connectPower(bool connect){m_powerConnected = connect;
                                            currAnim=2;};


protected:
    sf::Sprite m_obj;
    int m_id;
    int m_rate;
    int m_buildCost;
    int m_maintance;
    bool m_roadConnected;
    bool m_powerConnected;
    Animation*  m_animation;
    int currAnim=0;

private:

    std::pair<int, int> index;
};
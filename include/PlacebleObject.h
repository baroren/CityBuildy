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
                   int factor, int idN, int rate, int cost, int maint,bool power=false) {
        m_obj = *Resources::instance().getSprite(id);
        m_numAnimations = Resources::instance().getImageCount(id);

        m_animation = new Animation(Resources::instance().getTexture(id),
                                    sf::Vector2u(m_numAnimations,
                                                 m_numAnimations),0.3f);
        m_obj.setPosition(pos);
        m_obj.scale(factor, factor);
        m_id = idN;
        m_rate = rate;
        m_buildCost = cost;
        m_maintance = maint;
        m_powerConnected=power;
        if(m_powerConnected)
            connectPower(true);


    }

    virtual   ~PlacebleObject() {}

    virtual void show(sf::RenderWindow &window, int animState, float deltaTime) {
        m_animation->update(currAnim, deltaTime);
        m_obj.setTextureRect((m_animation->getRect()));

        window.draw(m_obj);
    };

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

    virtual bool isPowerConnected() { return m_powerConnected; };

    virtual bool isRoadConnected() { return m_roadConnected; };

    virtual bool isPowerLineConnect() { return m_powerLineConnected; }

   // virtual void connectRoad(bool connect) { m_roadConnected = connect; };

    virtual bool isResConnected() { return m_roadToResconnected; };

    virtual void roadToResconnected(bool connect) { m_roadToResconnected = connect; };

    virtual void connectPowerSource(bool connect) { m_powerLineConnected = connect; }

    virtual void connectPower(bool connect) {
        m_powerConnected = connect;
        if (connect && m_numAnimations > 1 && currAnim == 0)
            currAnim = 1;
        else if (!connect) {
            currAnim = 0;

        }
    };

    virtual bool changeAnim(int money) {
        if (time >= 3) {
            if (currAnim < m_numAnimations - 1 && currAnim > 0 ){
                currAnim++;
                time = 0;
                m_upgradeMoney =m_upgradeMoney*2;

                return true;
            }
        } else if (m_powerConnected)
            time++;
        return false;
    }
    virtual void updateRes(){;};
    virtual int getResNum(){;};
    virtual void roadpLine(bool connect) { std::cout << "test"; };

    virtual bool isroadpLineConnected() { return false; };
    virtual int getCurrAnim(){return currAnim;};
    //virtual int residanceCount(){;};
    virtual void happy(int amount){m_happy=amount;};
    virtual void money(){;};
    virtual void changeTexture(gameObjectId id){m_obj.setTexture(*Resources::instance().getTexture(id));
    };
    virtual void changeId(int id){m_id=id;};
protected:

    sf::Sprite m_obj;
    //int m_residanceCount=0;
    int time = 0;
    int m_id;
    int m_numAnimations;
    int m_rate;
    int m_buildCost;
    int m_maintance;
    //int m_resRate=0;
    bool m_roadLineConnected = false;
    bool m_roadConnected = false;
    bool m_powerConnected = false;
    bool m_powerLineConnected = false;
    bool m_roadToResconnected = false;
    bool m_roadAndLine=false;
    int m_happy =100;
    Animation *m_animation;
    int currAnim = 0;
    int groundConnection = 4;
    int m_upgradeMoney=5000;
private:

    std::pair<int, int> index;
};
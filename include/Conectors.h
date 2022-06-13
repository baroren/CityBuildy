#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "PlacebleObject.h"

class Conectors:public PlacebleObject {
public:
    using PlacebleObject::PlacebleObject;

    virtual void connectPower(bool connect) {
        m_powerConnected = connect;
        // currAnim=2;
    };
    virtual void roadpLine(bool connect) {
        if(connect)
        {
            m_roadLineConnected=true;
            currAnim=1;
        } else
        {
            m_roadLineConnected=false;
            currAnim=0;
        }
    }
   virtual bool isroadpLineConnected(){return m_roadLineConnected;};

protected:

// Conectors(const sf::Vector2f &pos,) : PlacebleObject(pos) {}



};
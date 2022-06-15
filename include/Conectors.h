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

    void connectPower(bool connect) override {
        m_powerConnected = connect;
    };
    void roadpLine(bool connect) override {
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
   bool isroadpLineConnected() override{return m_roadLineConnected;};

protected:




};
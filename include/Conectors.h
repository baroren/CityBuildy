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


   // Conectors(const sf::Vector2f &pos,) : PlacebleObject(pos) {}

    virtual void show(sf::RenderWindow &window)  =0;

private:
    sf::Sprite m_obj;

};
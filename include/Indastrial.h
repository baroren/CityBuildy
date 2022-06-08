#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"

class Indastrial : public Area {
public:

    using Area::Area;
private:
    // sf::Sprite m_obj;
    std::pair<int, int> pos;

};
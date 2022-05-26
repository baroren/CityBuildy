#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"

class Mouse {

public:
    Mouse();
    void trackMouse(sf::Vector2f mousePos,sf::RenderWindow& window,
                    int size);

private:
    sf::RectangleShape m_mouse;
};
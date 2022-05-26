//
// Created by Bar Oren on 23/05/2022.
//

#include "Mouse.h"
Mouse::Mouse()
{

    m_mouse.setOutlineThickness(3);
    m_mouse.setOutlineColor(sf::Color(255, 255, 255));
    m_mouse.setFillColor(sf::Color(255,255,255,128));
}

void Mouse::trackMouse(sf::Vector2f mousePos,sf::RenderWindow& window,
                       int size)
{
    m_mouse.setSize(sf::Vector2f(size, size));
    m_mouse.setOrigin(sf::Vector2f(size/2.f, size/2.f));

    m_mouse.setPosition(mousePos);
    window.draw(m_mouse);

}

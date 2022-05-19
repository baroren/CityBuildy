//
// Created by Bar Oren on 14/05/2022.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
    // m_window = Window(sf::Vector2u(600,500),"test");
    m_bg = *Resources::instance().getSprite(gameObjectId::MainMenuBG);
    sf::Vector2f targetSize(1000, 500);
    m_bg.setPosition(sf::Vector2f(500, 250));
    m_bg.setScale(
            targetSize.x / m_bg.getLocalBounds().width,
            targetSize.y / m_bg.getLocalBounds().height);
}

bool MainMenu::run(){

    while (m_window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (m_window.getWindow().pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                return true;
            }

        }

        // clear the window with black color

        // draw everything here...
        // window.draw(...);
m_window.getWindow().draw(m_bg);
        // end the current frame
        m_window.display();
    }

}
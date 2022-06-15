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
    m_menu.createButton("start ", 330, 275, 250, 50);
    m_menu.createButton("Settings ", 660, 275, 250, 50);
    m_menu.createButton("Quit ", 500, 350, 250, 50);

    m_menuSave.createButton("open Saved City ", 330, 350, 250, 50);
    m_menuSave.createButton("create New City", 660, 350, 250, 50);
    m_text.setFont(*Resources::instance().getFont());

}

bool MainMenu::run(bool &file) {
    m_text.setPosition(250, 200);//temp for clock pos
    m_text.setCharacterSize(48);

    m_text.setFillColor(sf::Color::White);

    while (m_window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (m_window.getWindow().pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {

                if (m_menuSave.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 0) {
                    file = true;
                    return true;
                    //    return true;
                }
                if (m_menuSave.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 1) {
                    file = false;
                    return true;
                    //    return true;
                }
                if (m_menu.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 0) {
                    m_startClicked = true;
                    //    return true;
                }
                if (m_menu.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 2) {


                    return false;
                }

            }
            if (event.type == sf::Event::Closed) {


                return false;
            }

        }

        // clear the window with black color

        // draw everything here...
        // window.draw(...);
        m_window.getWindow().draw(m_bg);
        if (m_startClicked)
            m_menuSave.updateBt(m_window.getWindow());
        else
            m_menu.updateBt(m_window.getWindow());
        // end the current frame
        m_window.display();
    }
    return true;
}
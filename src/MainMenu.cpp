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
    m_menuNew.createButton("Continue ", 330, 350, 250, 50);
    m_menuNew.createButton("return", 660, 350, 250, 50);

}

bool MainMenu::run(bool &file, std::string &cityName) {
    m_text.setPosition(350, 200);//temp for clock pos
    m_text.setCharacterSize(32);

    m_text.setFillColor(sf::Color::White);
    while (m_window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;


        while (m_window.getWindow().pollEvent(event)) {

            if (m_newWorld && event.type == sf::Event::TextEntered && m_cityName.length() < 8) {
                if (event.text.unicode >= 33 && event.text.unicode <= 126) {
                    m_cityName += (char) event.text.unicode;
                } else if (event.text.unicode == 8)
                    m_cityName = m_cityName.substr(0, m_cityName.length() - 1);
                std::cout << m_cityName << std::endl;
                m_text.setString("enter Name : " + m_cityName);
            }
            // "close reque
            //
            // sted" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (m_menu.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 0) {
                    m_startClicked = true;
                } else if (m_menuSave.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 0 && !m_newWorld) {
                    file = true;
                    return true;

                } else if (m_menuNew.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 0 && !m_startClicked) {
                    file = false;
                    cityName = m_cityName;
                    return true;


                }

                if (m_menu.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 1) {


                }
                if (m_menuNew.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 1&& !m_startClicked) {
                    std::cout << "m_menuNew";

                    m_startClicked=false;

                    m_newWorld = true;
                }
                else  if (m_menuSave.handleClick(
                        m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                        m_window.getWindow()) == 1 &&m_startClicked) {
                    file = false;
                     std::cout << "test";

                    m_startClicked = false;
                    m_newWorld = true;

                    m_text.setString("enter Name : ");

                }
            }

        }




        // clear the window with black color

        // draw everything here...
        // window.draw(...);

        m_window.getWindow().draw(m_bg);
        if (level==1) {
            m_text.setString(m_fileSave);

            m_menuSave.updateBt(m_window.getWindow());

        }
        if (level ==2) {

            m_menuNew.updateBt(m_window.getWindow());
        } else
            m_menu.updateBt(m_window.getWindow());


        m_window.getWindow().draw(m_text);
        // end the current frame
        m_window.display();
    }


}
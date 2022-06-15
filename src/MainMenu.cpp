//
// Created by Bar Oren on 14/05/2022.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
    init();


}


bool MainMenu::run(bool &file, std::string &cityName) {
    m_text.setPosition(350, 200);//temp for clock pos
    m_text.setCharacterSize(32);

    m_text.setFillColor(sf::Color::White);
    while (m_window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;


        while (m_window.getWindow().pollEvent(event)) {

            if (level == 2 && event.type == sf::Event::TextEntered && m_cityName.length() < 8) {
                if (event.text.unicode >= 33 && event.text.unicode <= 126) {
                    m_cityName += (char) event.text.unicode;
                } else if (event.text.unicode == 8)
                    m_cityName = m_cityName.substr(0, m_cityName.length() - 1);
                std::cout << m_cityName << std::endl;
                m_text.setString("enter Name : " + m_cityName);
            }

            if (event.type == sf::Event::Closed)
                m_window.getWindow().close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (level == 4) {
                    level = 3;
                }else {
                    if (m_menu.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 0 && level == 0) {
                        level = 1;
                    } else if (m_menuSettings.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 0 && level == 3) {
                        level = 3;
                        Resources::instance().stopMusic(gameObjectId::bg);


                    } else if (m_menuSave.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 0 && level == 1) {
                        file = true;
                        level = 2;
                        return true;
                    } else if (m_menuNew.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 0 && level == 2) {
                        file = false;
                        cityName = m_cityName;
                        return true;
                    }


                    if (m_menu.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 1 && level == 0) {
                        level = 3;

                    } else if (m_menuNew.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 1 && level == 2) {
                        level = 1;
                    } else if (m_menuSave.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 1 && level == 1) {
                        file = false;

                        level = 2;

                        m_text.setString("enter Name : ");

                    } else if (m_menuSettings.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 1 && level == 3) {
                        Resources::instance().playMusic(gameObjectId::bg);

                        level = 3;


                    }

                    if (m_menuSettings.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 2 && level == 3) {
                        level = 0;

                    } else if (m_menuSave.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 2 && level == 1) {
                        level = 0;

                    } else if (m_menuSave.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 2 && level == 0) {
                        exit(EXIT_SUCCESS);

                    }
                    if (m_menuSettings.handleClick(
                            m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),
                            m_window.getWindow()) == 3 && level == 3)
                        level = 4;
                }
            }

        }




        // clear the window with black color

        // draw everything here...
        // window.draw(...);
        handleDraw();



        // end the current frame
        m_window.display();
    }


}

void MainMenu::handleDraw() {
    if (level != 4)
        m_window.getWindow().draw(m_bg);
    if (level == 1) {
        m_text.setString(m_fileSave);

        m_menuSave.updateBt(m_window.getWindow());
        m_window.getWindow().draw(m_text);

    } else if (level == 2) {

        m_menuNew.updateBt(m_window.getWindow());
        m_window.getWindow().draw(m_text);

    } else if (level == 3) {
        m_menuSettings.updateBt(m_window.getWindow());
    } else if (level == 4) {
        m_window.getWindow().draw(m_help);

    } else
        m_menu.updateBt(m_window.getWindow());
}


void MainMenu::init() {
    m_bg = *Resources::instance().getSprite(gameObjectId::MainMenuBG);
    sf::Vector2f targetSize(1000, 500);
    m_bg.setPosition(sf::Vector2f(500, 250));
    m_bg.setScale(
            targetSize.x / m_bg.getLocalBounds().width,
            targetSize.y / m_bg.getLocalBounds().height);

    m_help = *Resources::instance().getSprite(gameObjectId::help);
    m_help.setPosition(sf::Vector2f(500, 250));

    m_menu.createButton("start ", 330, 275, 250, 50);
    m_menu.createButton("Settings ", 660, 275, 250, 50);
    m_menu.createButton("Quit ", 500, 350, 250, 50);

    m_menuSave.createButton("open Saved City ", 330, 300, 250, 50);
    m_menuSave.createButton("create New City", 660, 300, 250, 50);
    m_menuSave.createButton("return ", 500, 375, 250, 50);

    m_text.setFont(*Resources::instance().getFont());
    m_menuNew.createButton("Continue ", 330, 350, 250, 50);
    m_menuNew.createButton("return", 660, 350, 250, 50);

    m_menuSettings.createButton("mute ", 330, 275, 250, 50);
    m_menuSettings.createButton("unmute ", 660, 275, 250, 50);
    m_menuSettings.createButton("return ", 330, 350, 250, 50);
    m_menuSettings.createButton("Help ", 660, 350, 250, 50);
}

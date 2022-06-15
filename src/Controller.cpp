//
// Created by Bar Oren on 14/05/2022.
//

#include "Controller.h"

Controller::Controller() {
    m_music = Resources::instance().getMusic(gameObjectId::bg);
    m_testTemp.setFont(*Resources::instance().getFont());
    m_timeTemp.setFont(*Resources::instance().getFont());
    m_cityNameText.setFont(*Resources::instance().getFont());
    m_bg = *Resources::instance().getSprite(gameObjectId::bg);
    m_bg.setScale(2., 2);
    if (!m_mainMenu.run(m_readFromFile))
        m_window.close();
    m_tileMap = TileMap(m_readFromFile);

}

//--------------------------------------------------------------------------3
void Controller::run() {
    m_music->play();

    //move to constructor maybe move
//------------------------------------------
    auto viewSize = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y);
    m_views[0] = sf::View(sf::FloatRect(0.f, 0.f, 1920 * 0.2f, 1080.f));
    m_views[0].setViewport(sf::FloatRect(0.f, 0.f, 0.2f, 1.f));
    m_views[1] = sf::View(sf::FloatRect(float(MARGINX + 25 * 16), float(MARGINX + 25 * 16), 800.f, 600.f));
    m_views[1].setViewport({0.2f, 0.f, 0.8f, 1.f});

    m_testTemp.setPosition(50, 990);//temp for clock pos
    m_testTemp.setCharacterSize(48);
    m_timeTemp.setPosition(50, 100);//temp for clock pos
    m_timeTemp.setCharacterSize(48);
    m_cityNameText.setPosition(50, 10);//temp for clock pos
    m_cityNameText.setCharacterSize(48);
    m_cityNameText.setString(m_cityName);
    m_testTemp.setFillColor(sf::Color::Black);
    m_cityNameText.setFillColor(sf::Color::Black);
    m_timeTemp.setFillColor(sf::Color::Black);


    m_window.create(sf::VideoMode(1920, 1080), "City Buildy");
    m_dims.first = sf::VideoMode::getDesktopMode().width;
    m_dims.second = sf::VideoMode::getDesktopMode().height;
//----------------------------------


    while (m_window.isOpen()) {
        sf::Time time1 = m_clock.getElapsedTime();
        sf::Time timeForAnim = m_clockAnim.getElapsedTime();

        m_testTemp.setString("test");
        m_bg.setScale(2, 2);

        m_bg.setPosition(m_window.getSize().x / 2, m_window.getSize().y / 2);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (m_window.pollEvent(event)) {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                // m_views[1].zoom(3);
                sf::Vector2i mouse = sf::Mouse::getPosition(m_window);
                int temp = m_sideMenu.handleClick(translateMouse(mouse));
                // std::cout<<"temp"<<temp<<std::endl;
                if (clicked == -1 || temp >= 1 && temp < m_sideMenu.getSize() + 1) {//TODO make const

                    clicked = m_sideMenu.handleClick(translateMouse(mouse));
                    handleView();


                } else {
                    std::cout << "clicked from side menud : " << clicked << std::endl;
                    m_tileMap.update(translateMouse(mouse), clicked);
                }

            }

        }
        handleTimeAndDate(time1);

        // clear the window with black color
        // std::cout<<time1.asSeconds()<<std::endl;
        // draw everything here...
        // window.draw(...);
        // m_clock.restart()
        m_window.clear(sf::Color(123, 200, 249));
        m_window.setView(m_views[0]);
        m_window.draw(m_bg);
        m_tileMap.drawMoney(m_window);
        draw();
        m_window.setView(m_views[1]);
        m_bg.setPosition(2000, 2200);
        m_bg.setScale(3.5, 3.5);
        m_window.draw(m_bg);

        if (m_tileMap.draw(m_window, m_dims, m_deltaTime))
            std::cout << "gameOver" << std::endl;
        draw();

        // draw();

        m_deltaTime = m_clockAnim.restart().asSeconds();


        m_window.display();


    }
}

void Controller::handleView() {
    if (clicked == 8)
        m_tileMap.saveLevel();
    else if (clicked == 9) {
        m_views[1].zoom(1 - m_zoomRate);

        std::cout << m_views[1].getSize().x << " " << m_views[1].getSize().y << std::endl;
    } else if (clicked == 10) {
        if (m_views[1].getSize().x < maxSize.x && m_views[1].getSize().y < maxSize.y)
            m_views[1].zoom(1 + m_zoomRate);


    } else if (clicked == 11) {
        std::cout << m_views[1].getCenter().x << " " << m_views[1].getCenter().y << std::endl;
        if (m_views[1].getCenter().x > 1400)
            m_views[1].move(sf::Vector2f(-MOVE, 0));

    } else if (clicked == 12) {
        if (m_views[1].getCenter().y > 1800)
            m_views[1].move(sf::Vector2f(0, -MOVE));

    } else if (clicked == 13) {
        std::cout << m_views[1].getCenter().x << " " << m_views[1].getCenter().y << std::endl;
        if (m_views[1].getCenter().y < 2000)
            m_views[1].move(sf::Vector2f(0, MOVE));

    } else if (clicked == 14) {
        if (m_views[1].getCenter().x < 2300)

            m_views[1].move(sf::Vector2f(MOVE, 0));

    }
}
//--------------------------------------------------------------------------


sf::Vector2f Controller::translateMouse(sf::Vector2i mouseLocation) const {
    /* for (const auto &view: m_views) {
         if (m_window.getViewport(view).contains(mouseLocation)) {
             std::cout<<"test \n";
             return m_window.mapPixelToCoords(mouseLocation, view);
         }
     }*/
    for (int i = 0; i < m_views.size(); ++i) {
        if (m_window.getViewport(m_views[i]).contains(mouseLocation)) {
            std::cout << "test :" << i << std::endl;
            return m_window.mapPixelToCoords(mouseLocation, m_views[i]);
        }
    }

    // if it isn't inside one of them, translate based on the active one
    return m_window.mapPixelToCoords(mouseLocation);
}

//--------------------------------------------------------------------------
void Controller::draw() {


    m_window.draw(m_testTemp);
    m_window.draw(m_cityNameText);
    m_mouse.trackMouse(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)), m_window, 16 * FACTOR);
    m_sideMenu.draw(m_window);
    m_window.draw(m_timeTemp);
    // end the current frame
}

//--------------------------------------------------------------------------
void Controller::handleTimeAndDate(sf::Time &time1) {
    m_testTemp.setString(m_sideMenu.getPrice(clicked));
    m_timeTemp.setString(m_dates[m_currDate] + "  " + std::to_string(m_year));
    if (time1.asSeconds() > float(month) && m_payday) {
        m_clock.restart();
        //   m_payday=false;
        cout << "month past";
        m_tileMap.updateMoney();
        m_tileMap.updateAnim();
        date();

    }


}

//--------------------------------------------------------------------------

void Controller::date() {

    if (m_currDate >= 11) {
        m_currDate = 0;
        m_year++;
    }

    m_currDate++;
}
//
// Created by Bar Oren on 14/05/2022.
//

#include "Controller.h"

Controller::Controller() {
    m_testTemp.setFont(*Resources::instance().getFont());
    m_timeTemp.setFont(*Resources::instance().getFont());
    m_cityNameText.setFont(*Resources::instance().getFont());

}

//--------------------------------------------------------------------------3
void Controller::run() {

      if( !m_mainMenu.run())
      return;

    //move to constructor maybe move
//------------------------------------------
    auto viewSize = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y);
    m_views[0] = sf::View(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
    m_views[0].setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    m_views[1] = sf::View(sf::FloatRect(200.f, 200.f, 800.f, 800.f));
    m_views[1].setViewport({0.2f, 0.2f, 1.f, 0.8f});
    m_testTemp.setPosition(100, 900);//temp for clock pos
    m_testTemp.setCharacterSize(48);
    m_timeTemp.setPosition(1600, 10);//temp for clock pos
    m_timeTemp.setCharacterSize(48);
    m_cityNameText.setPosition(800, 10);//temp for clock pos
    m_cityNameText.setCharacterSize(48);
    m_cityNameText.setString(m_cityName);
    m_testTemp.setFillColor(sf::Color::Black);
    m_window.create(sf::VideoMode(1920, 1080), "City Buildy");
    m_dims.first = sf::VideoMode::getDesktopMode().width;
    m_dims.second = sf::VideoMode::getDesktopMode().height;
//----------------------------------





    while (m_window.isOpen()) {
        sf::Time time1 = m_clock.getElapsedTime();
        sf::Time timeForAnim=m_clockAnim.getElapsedTime();
        m_testTemp.setString("test");

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (m_window.pollEvent(event)) {


            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                 m_views[1].zoom(3.f);

                int temp = m_sideMenu.handleClick(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)));
                // std::cout<<"temp"<<temp<<std::endl;
                if (clicked == -1 || temp >= 1 && temp < 9) {
                    clicked = m_sideMenu.handleClick(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)));
                    std::cout << "clicked from side menud in if  : " << clicked << std::endl;
                    //   cout<<"X: "<<m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window),m_views[0]).x<<std::endl;
                    //   m_views[1].zoom(3.f);



                } else {
                    std::cout << "clicked from side menud : " << clicked << std::endl;
                    m_tileMap.update(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)), clicked);
                }

            }

        }
        handleTimeAndDate(time1);

        // clear the window with black color
        // std::cout<<time1.asSeconds()<<std::endl;
        // draw everything here...
        // window.draw(...);
        // m_clock.restart()
        m_window.clear(sf::Color(0, 170, 250));
        m_window.setView(m_views[0]);

         //draw();
       //  m_window.setView(m_views[1]);
        if (m_tileMap.draw(m_window, m_dims,m_deltaTime))
            std::cout << "gameOver" << std::endl;

        draw();
        m_deltaTime = m_clockAnim.restart().asSeconds();

        // m_window.setView(view1);
        //  draw();
        m_window.display();


    }
}//--------------------------------------------------------------------------


sf::Vector2f Controller::translateMouse(sf::Vector2i mouseLocation) const {
    for (const auto &view: m_views) {
        if (m_window.getViewport(view).contains(mouseLocation)) {
            return m_window.mapPixelToCoords(mouseLocation, view);
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
    if (int(time1.asSeconds()) > float(month) && m_payday) {
        m_clock.restart();
        //   m_payday=false;
        cout << "month past";
        m_tileMap.updateMoney();
        date();

    } else if (int(time1.asSeconds()) % (month + 1) == 0)//11 will be set accotding to game speed
    {
        // m_payday = true;
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
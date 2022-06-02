//
// Created by Bar Oren on 14/05/2022.
//

#include "Controller.h"

Controller::Controller(){

}
void Controller::run(){

    if( !m_mainMenu.run())
       return;


    m_window.create(sf::VideoMode(1920,1080),"City Buildy");
    m_dims.first=sf::VideoMode::getDesktopMode().width;
    m_dims.second=sf::VideoMode::getDesktopMode().height;

    while (m_window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (m_window.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                int temp= m_sideMenu.handleClick(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)));
                std::cout<<"temp"<<temp<<std::endl;
                if(clicked ==-1 || temp>1 &&temp <5) {
                    clicked = m_sideMenu.handleClick(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)));
                    std::cout << "clicked from side menud in if  : " << clicked << std::endl;


                }
                else {
                    std::cout << "clicked from side menud : " << clicked << std::endl;
                    m_tileMap.update(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)), clicked);
                }

            }

        }

        // clear the window with black color

        // draw everything here...
        // window.draw(...);
// activate it



        m_window.clear(sf::Color(103, 230, 210));

        m_tileMap.draw(m_window,m_dims);
        m_mouse.trackMouse(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)),m_window,16*FACTOR);
        m_sideMenu.draw(m_window);
        // end the current frame
        m_window.display();
    }
}
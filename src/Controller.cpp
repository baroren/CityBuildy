//
// Created by Bar Oren on 14/05/2022.
//

#include "Controller.h"

Controller::Controller(){

}
void Controller::run(){
   if( !m_mainMenu.run())
       return;
    m_window.create(sf::VideoMode(1920,1080),"City Buildy",sf::Style::Fullscreen);
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
                return;
            }

        }

        // clear the window with black color

        // draw everything here...
        // window.draw(...);

        // end the current frame
        m_window.display();
    }
}
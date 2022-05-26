#include "SideMenu.h"

SideMenu::SideMenu() {
    for (int i = 2; i < 10; i++) {
        m_buttons.push_back(*Resources::instance().getSprite(gameObjectId(i)));
    }

    for(int i = 0; i <m_buttons.size() ; ++i) {
        m_buttons[i].setScale(2, 2);

        m_buttons[i].setPosition(100, 100 + 55 * i);
    }
}

void SideMenu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i <m_buttons.size() ; ++i) {
        window.draw(m_buttons[i]);
    }

}

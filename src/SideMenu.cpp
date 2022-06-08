#include "SideMenu.h"

SideMenu::SideMenu() {
    for (int i = 2; i < 9; i++) {
        m_buttons.push_back(*Resources::instance().getSprite(gameObjectId(i)));
    }
    for (int i = 0; i < m_buttons.size(); ++i) {
        m_buttons[i].setScale(2, 2);

        m_buttons[i].setPosition(100, 100 + 55 * i);
    }
}

void SideMenu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < m_buttons.size(); ++i) {
        window.draw(m_buttons[i]);
    }

}

int SideMenu::handleClick(const sf::Vector2f position) {

    for (int i = 0; i < m_buttons.size(); i++) {
        if (m_buttons[i].getGlobalBounds().contains(position)) {
            std::cout << "clicked";
            return i + 1;


        }


    }
    return -1;
}

string SideMenu::getPrice(int id) {

    //exception if 0 or grater then 7 ?

    switch (id) {
        case 1 :
            return "Road "+std::to_string(c_road);
        case 2 :
            return "Commercial "+std::to_string(c_commercial);
        case 3 :
            return "Delete "+std::to_string(c_delete);
        case 4 :
            return "Industrial "+std::to_string(c_indastrial);
        case 5 :
            return "Residence "+std::to_string(c_ressidance);
        case 6 :
            return "Power line "+std::to_string(c_powerline);
        case 7 :
            return "PowerSource "+std::to_string(c_powerSource);
        default:
            return "0";

    }

}
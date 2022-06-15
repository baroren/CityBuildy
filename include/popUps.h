#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
#include "Macros.h"
#include "Area.h"
#include "ProgressBar.h"


class PopUps {
public:
    PopUps() {
        m_popUps.push_back(*Resources::instance().getSprite(gameObjectId::gameover));
        m_popUps.push_back(*Resources::instance().getSprite(gameObjectId::start));
        m_popUps.push_back(*Resources::instance().getSprite(gameObjectId::win));

        for (auto &popUp: m_popUps){

            popUp.setPosition(960,540);
        }
    }


    void draw(sf::RenderWindow& window, popUps id){
        window.draw(m_popUps[int(id)]);};
    //void CRIdraw(sf::RenderWindow &window){progressBar.progressBarDraw(window);};

private:

    // ProgressBar progressBar;

    vector<sf::Sprite> m_popUps;

};



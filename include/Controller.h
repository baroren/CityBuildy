//
// Created by Bar Oren on 14/05/2022.
//

#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include "MainMenu.h"
#include "Window.h"
#include "MainMenu.h"
#include "TileMap.h"
#include "Mouse.h"
#include "SideMenu.h"
#include "Roads.h"
#include <string>
using std::vector;
using std::unique_ptr;
using std::make_unique;


class Controller {
public:
  Controller();
  void run();
private:
    sf::Text m_testTemp;
    sf::Text m_timeTemp;

    sf::Clock m_clock;
    int clicked =-1;
    SideMenu m_sideMenu;
    std::pair<int,int> m_dims;
    MainMenu m_mainMenu;
    TileMap m_tileMap;
    Mouse m_mouse;
    sf::RenderWindow m_window;

};
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

using std::vector;
using std::unique_ptr;
using std::make_unique;

class Controller {
public:
  Controller();
  void run();
private:
    MainMenu m_mainMenu;
    TileMap m_tileMap;

    sf::RenderWindow m_window;

};
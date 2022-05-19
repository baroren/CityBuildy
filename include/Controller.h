//
// Created by Bar Oren on 14/05/2022.
//

#pragma once
#include <SFML/Audio.hpp>
#include "MainMenu.h"
#include "Window.h"
#include <vector>
#include <memory>
#include "MainMenu.h"
using std::vector;
using std::unique_ptr;
using std::make_unique;

class Controller {
public:
  Controller();
  void run();
private:
    MainMenu m_mainMenu;
    sf::RenderWindow m_window;
};
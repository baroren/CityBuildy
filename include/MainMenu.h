//
// Created by Bar Oren on 14/05/2022.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Macros.h"
using std::vector;
using std::make_unique;
using std::unique_ptr;

class MainMenu {
public:
    MainMenu();
    bool run();


private :
    Window m_window;
    sf::Sprite m_bg;


};
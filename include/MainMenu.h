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
#include "Menu.h"
using std::vector;
using std::make_unique;
using std::unique_ptr;

class MainMenu {
public:
    MainMenu();
    bool run(bool& file,std::string &cityName);


private :
    int level=0;
    bool m_startClicked=false;
    bool m_newWorld=false;
    std::string m_cityName;
    std::string m_fileSave="Would you like  to\n  open a saved city";
    sf::Text m_text;
    Window m_window;
    sf::Sprite m_bg;
    Menu m_menu;
    Menu m_menuNew;
    Menu m_menuSave;
    Menu m_menuSettings;

};
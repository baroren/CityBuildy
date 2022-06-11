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
using std::cout;
using std::string;

class Controller {
public:
  Controller();
  void run();
  void draw();
  void handleTimeAndDate(sf::Time& time1);
private:
    void date();
    sf::Vector2f translateMouse(sf::Vector2i mouseLocation) const;
    std::array<sf::View,2> m_views;
    std::array<string, 12> m_dates = { "Jan","Feb","Mar","Apr"
        ,"May","June","July","aug","Sep","Oct","Nov","Dec" };
    int m_currDate = 0;
    int m_year = 1920;
    int clicked =-1;
    float m_deltaTime;


    sf::Text m_testTemp;
    sf::Text m_cityNameText;
    sf::Text m_timeTemp;
    bool m_payday=true;
    sf::Clock m_clock;
    sf::Clock m_clockAnim;

    SideMenu m_sideMenu;
    std::pair<int,int> m_dims;
    MainMenu m_mainMenu;
    TileMap m_tileMap;
    Mouse m_mouse;
    sf::RenderWindow m_window;

    string m_cityName="nahariya ";
};
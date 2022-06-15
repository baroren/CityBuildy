#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include "Resources.h"
#include "PlacebleObject.h"
#include <Road.h>
#include "Ground.h"
#include "Area.h"
#include "Commercial.h"
#include "Residence.h"
#include "Player.h"
#include "Indastrial.h"
#include "PowerLines.h"
#include "PowerSource.h"
#include "CollisionHandling.h"
#include "CRI.h"
#include <random>
#include "Factory.h"


class TileMap {

public:
    explicit TileMap(bool file=false,std::string cityName="defualt");

    bool draw(sf::RenderWindow &window,std::pair<int,int>,float deltaTime);
    void drawMoney(sf::RenderWindow &window);

    void update(sf::Vector2f mousePos,int &id);

    void check(int row, int col);

    void updateMoney();
    int CRIup();

    void updateAnim();
    void saveLevel();

 std::string getCityName(){return m_cityName;};

private:
// STL-like algorithm to run over all pairs
    void del(int row, int col) ;
    vector<std::pair<int, int>> assertNum(int size, int a ,int b);
    void loadLevel();

    Player m_player;

    sf::Text m_playerMoney;
    sf::Text m_playerResidance;

    void createRoad(int& row, int& col);

    void diraction(int& row, int& col);

    void initIntRect();

    // In the constructor, specify these constants
    // They are important


    // This textures holds the textures for the tiles
    // It should be a single image with multiple tiles (like a spritesheet)
    //sf::Texture *tileSheet;
std::string m_cityName;
    sf::Sprite tile;
    vector<std::pair<int,int>> vect;
    vector<vector<std::unique_ptr<PlacebleObject>>> m_obj;
    // Add / remove these in order to add more tiles
    // This depends on the amount of tiles in your texture
    int m_rows=50;
    int m_cols=50;
    sf::IntRect m_grass;
    sf::IntRect m_ground;
    CRIclass m_CRI;
    void handleClick(sf::Vector2f &mousePos, const int &id, int &row, int &col);
bool firstRun=true;
};
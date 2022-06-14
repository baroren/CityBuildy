#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
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
class TileMap {

public:
    TileMap();

    bool draw(sf::RenderWindow &window,std::pair<int,int>,float deltaTime);

    void update(sf::Vector2f mousePos,int &id);

    void check(int row, int col);

    void updateMoney();

    void updateAnim();

 

private:
// STL-like algorithm to run over all pairs
    void del(int row, int col) ;

    Player m_player;

    sf::Text m_playerMoney;
    sf::Text m_playerResidance;

    void createRoad(int& row, int& col);

    void diraction(int& row, int& col);

    void initIntRect();

    // In the constructor, specify these constants
    // They are important
    const int tileWidth;
    const int tileHeight;

    // This textures holds the textures for the tiles
    // It should be a single image with multiple tiles (like a spritesheet)
    //sf::Texture *tileSheet;

    sf::Sprite tile;
    vector<vector<std::unique_ptr<PlacebleObject>>> m_obj;
    // Add / remove these in order to add more tiles
    // This depends on the amount of tiles in your texture
    int m_rows=17;
    int m_cols=30;
    sf::IntRect m_grass;
    sf::IntRect m_ground;

    void handleClick(sf::Vector2f &mousePos, const int &id, int &row, int &col);
};
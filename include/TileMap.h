#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "PlacebleObject.h"
#include <Roads.h>
#include "Ground.h"
#include "Area.h"
#include "Commercial.h"

class TileMap {

public:
    TileMap();

    void draw(sf::RenderWindow &window,std::pair<int,int>);

    void update(sf::Vector2f mousePos,int &id);

    void factor2Check(int row, int col, int& retflag);

 

private:



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
    int m_rows=20;
    int m_cols=20;
    sf::IntRect m_grass;
    sf::IntRect m_ground;

};
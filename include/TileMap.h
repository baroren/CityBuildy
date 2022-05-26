#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"

class TileMap {

public:
    TileMap();

    void draw(sf::RenderWindow &window,std::pair<int,int>);

    void update(sf::Vector2f mousePos);

private:

    static const int mapRows = 10;//TODO
    static const int mapColumns = 10;
    int map[mapRows][mapColumns] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};// TODO change to arrray or vector
    void initIntRect();

    // In the constructor, specify these constants
    // They are important
    const int tileWidth;
    const int tileHeight;

    // This textures holds the textures for the tiles
    // It should be a single image with multiple tiles (like a spritesheet)
    //sf::Texture *tileSheet;

    sf::Sprite tile;

    // Add / remove these in order to add more tiles
    // This depends on the amount of tiles in your texture

    sf::IntRect m_grass;
    sf::IntRect m_ground;

};
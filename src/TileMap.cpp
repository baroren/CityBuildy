#include "TileMap.h"

TileMap::TileMap()
// Change the values when using tiles other than 30x30
        : tileWidth(30)
        , tileHeight(30)
{
    // Load the texture which contains the tiles

   // tileSheet=Resources::instance().getTexture(gameObjectId::TileSheet);
    tile = *Resources::instance().getSprite(gameObjectId::TileSheet);


    // Set the tiles
   // tile.setTexture(*tileSheet);

    // Assign the tiles to the IntRect
    initIntRect();
}

void TileMap::draw(sf::RenderWindow &window)
{
    // This is the map (20x20 tiles)
    // Change when needed
    const int mapRows = 20;
    const int mapColumns = 20;

    /*
    The codes with their corresponding tiles

        - 0	=	pink path
        - 1	=	stone wall
        - 2	=	wooden box
        - 3	=	grass
    */

    int map[mapRows][mapColumns] =
            {
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 1
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 2
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 3
                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // row 4
            };

    // IntRect placeholder
    sf::IntRect placeHolder;

    // Loop through the rows
    for (int row = 0; row < mapRows; row++)
    {
        // Loop through the columns
        for (int column = 0; column < mapColumns; column++)
        {
            // Add / remove cases when tiles are added / removed
            switch (map[row][column])
            {
                case 0:
                    placeHolder = m_grass;
                    break;
                case 1:
                    placeHolder = m_ground;
                    break;
            }

            // Set the correct part of the spritesheet
            tile.setTextureRect(placeHolder);

            // Set the position
            tile.setPosition((row * tileWidth), (column * tileHeight));

            // Draw the sprite to the screen
            window.draw(tile);
        }
    }
}

// Check the SFML documentation about intrect if you do not know what is going on here
// Add / remove some when needed (if you use less or more tiles in the texture)
// The value of 30 is the width / height of a tile
// Change if the tiles should be bigger / smaller
void TileMap::initIntRect()
{
    m_grass.left = 0;
    m_grass.top = 0;
    m_grass.width = tileWidth;
    m_grass.height = tileHeight;

    m_ground.left = 30;
    m_ground.top = 0;
    m_ground.width = tileWidth;
    m_ground.height = tileHeight;


}
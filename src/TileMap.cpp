#include "TileMap.h"

TileMap::TileMap()
// Change the values when using tiles other than 30x30
        : tileWidth(16*FACTOR)
        , tileHeight(16*FACTOR)
{
    // Load the texture which contains the tiles

   // tileSheet=Resources::instance().getTexture(gameObjectId::TileSheet);
    tile = *Resources::instance().getSprite(gameObjectId::TileSheet);

    tile.setScale(FACTOR,FACTOR);
    // Set the tiles
   // tile.setTexture(*tileSheet);

    // Assign the tiles to the IntRect
    initIntRect();
}

void TileMap::draw(sf::RenderWindow &window,std::pair<int,int> dims)
{
    // This is the map (20x20 tiles)
    // Change when needed


    /*
    The codes with their corresponding tiles

        - 0	=	pink path
        - 1	=	stone wall

    */



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
            tile.setPosition((row * tileWidth+MARGINX), (column * tileHeight+MARGINY));

            // Draw the sprite to the screen
            window.draw(tile);
        }
    }
}
void TileMap::update(sf::Vector2f mousePos) {
    std::cout<<mousePos.x<<"y"<<mousePos.y<<std::endl;

    for (int row = 0; row < mapRows; row++) {
        // Loop through the columns
        for (int col = 0; col < mapColumns; col++) {
            if ((mousePos.x> ((row) * (tileWidth)-tileWidth/2 + MARGINX) &&mousePos.x <((row) * tileWidth)+tileWidth/2+MARGINX) &&
                    (mousePos.y>(((col) * (tileHeight)-tileWidth/2+MARGINY))&&mousePos.y<(((col) * tileHeight)+tileWidth/2+MARGINY)))
            {
                if (map[row][col] == 0)
                    map[row][col] = 1;
                else
                    map[row][col] = 0;
            }
        }
    }
}
// Check the SFML documentation about intrect if you do not know what is going on here
// Add / remove some when needed (if you use less or more tiles in the texture)
// The value of 30 is the width / height of a tile
// Change if the tiles should be bigger / smaller
void TileMap::initIntRect()
{
    m_grass.left = 16;
    m_grass.top = 0;
    m_grass.width = tileWidth/FACTOR;
    m_grass.height = tileHeight/FACTOR;

    m_ground.left = 0;
    m_ground.top = 0;
    m_ground.width = tileWidth/FACTOR;
    m_ground.height = tileHeight/FACTOR;


}
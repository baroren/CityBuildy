#include "TileMap.h"

TileMap::TileMap()
// Change the values when using tiles other than 30x30
        : tileWidth(16*FACTOR)
        , tileHeight(16*FACTOR) {
    for (int row = 0; row < m_rows ; ++row) {
        vector<std::unique_ptr<PlacebleObject>> temp;
        for (int col= 0; col < m_cols; col++) {

                temp.push_back(std::make_unique<Ground>(sf::Vector2f(
                        row * tileWidth+MARGINX  ,col * tileWidth+MARGINX),row,col,gameObjectId::TileSheet));
        }
        m_obj.push_back(std::move(temp));
    }
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
    for (int row = 0; row < m_rows; row++)
    {
        // Loop through the columns
        for (int column = 0; column < m_cols; column++)
        {
            // Add / remove cases when tiles are added / removed


            m_obj[row][column]->show(window);

            // Set the correct part of the spritesheet

        }
    }
}

void TileMap::update(sf::Vector2f mousePos,int &id) {
    std::cout<<mousePos.x<<"y"<<mousePos.y<<std::endl;

    for (int row = 0; row < m_rows; row++) {
        // Loop through the columns
        for (int col = 0; col < m_cols; col++) {
            if (m_obj[row][col]->checkClick(mousePos))
            {
                std::cout<<row<<col<<" "<<id;
                if(m_obj[row][col]->returnID()==0)
                {
                    if (id==1) {
                       std::unique_ptr<Roads> roads = std::make_unique<Roads>(sf::Vector2f(
                                row * tileWidth + MARGINX, col * tileWidth + MARGINX), row, col, gameObjectId::road);

                       m_obj[row][col] = std::move(roads);
                    }
                }

            }
        }
    }
    //id=-1;
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
#include "TileMap.h"

TileMap::TileMap()
// Change the values when using tiles other than 30x30
        : tileWidth(16*FACTOR)
        , tileHeight(16*FACTOR) {
    for (int row = 0; row < m_rows ; ++row) {
        vector<std::unique_ptr<PlacebleObject>> temp;
        for (int col= 0; col < m_cols; col++) {

                temp.push_back(std::make_unique<Ground>(sf::Vector2f(
                       col * tileWidth+MARGINX, row * tileWidth + MARGINY),row,col,gameObjectId::TileSheet));
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

            if(m_obj[row][column]->returnID()==0)
                m_obj[row][column]->show(window);

            // Set the correct part of the spritesheet

        }
    }
    for (int row = 0; row < m_rows; row++)
    {
        // Loop through the columns
        for (int column = 0; column < m_cols; column++)
        {
            // Add / remove cases when tiles are added / removed

            if (m_obj[row][column]->returnID() 
                != 0)
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
              //  int retflag;
                //factor2Check(row, col, retflag);
                //if (retflag == 2) break;

                if (m_obj[row][col]->returnID() == 0) {

                    // if(m_obj[row-1][col]->returnID() == 0)
                    std::cout << id << std::endl;
                    if (id == 1) {
                        createRoad(row, col);
                    } else if (id == 2) {
                        int retflag;
                        //   factor2Check(row, col, retflag);
                        //  if (retflag == 2) break;


                        std::cout << "comm";
                        std::unique_ptr<Commercial> commercial = std::make_unique<Commercial>(sf::Vector2f(
                                                                                                      col * tileWidth + MARGINX + 12, row * tileWidth + MARGINY), row, col,
                                                                                              gameObjectId::comPlace);

                        m_obj[row][col] = std::move(commercial);
                        factor2Check(row, col, retflag);
                    }
                 else if (id == 5)
                {
                    int retflag;

                    std::cout << "comm";
                    std::unique_ptr<Residence> residence = std::make_unique<Residence>(sf::Vector2f(
                                                                                                  col * tileWidth + MARGINX + 12, row * tileWidth + MARGINY), row, col,
                                                                                          gameObjectId::resPlace);

                    m_obj[row][col] = std::move(residence);
                    factor2Check(row, col, retflag);
                }
                }
                else if (id == 3) {
                    int retflag;

                    std::cout << "delete";
                    std::unique_ptr<Ground> ground = std::make_unique<Ground>(sf::Vector2f(
                        col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col, gameObjectId::TileSheet);

                    m_obj[row][col] = std::move(ground);
                    factor2Check(row, col, retflag);

                }

            }
        }
    }
    //id=-1;
}
void TileMap::factor2Check(int row, int col, int& retflag)
{
    retflag = 1;
    /*if (row > 2 || row < m_rows - 2 || col >2 || col < m_cols - 2)
    {
        if (m_obj[row - 1][col]->returnID() == 1 ||
            (m_obj[row + 1][col]->returnID() == 1) ||
            (m_obj[row][col + 1]->returnID() == 1) ||
            (m_obj[row][col - 1]->returnID() == 1) ||
            (m_obj[row - 1][col - 1]->returnID() == 1) ||
            (m_obj[row + 1][col + 1]->returnID() == 1))
            //for size*2 factor
        {//ugly as hell need to change asap
            std::cout << "not goodd";
            { retflag = 2; return; };
    */
    for (int i = 0; i < m_rows; i++) {
        // Loop through the columns
        for (int j = 0; j < m_cols; j++) {
            if(m_obj[i][j]->returnID() != 0) {
                if (!(i == row && j == col)) {
                    if (m_obj[i][j]->checkIfContained(m_obj[row][col]->bound())) {
                        if (m_obj[i][j]->bound().left + 144 - m_obj[row][col]->bound().left < 0)
                            std::cout << "containes \n\n";
                        std::cout << "touching.\n";
                        std::cout << m_obj[i][j]->bound().left << ".\n";

                        std::cout << m_obj[row][col]->bound().left << ".\n";

                    }

                }
            }

        }
    }

}
void TileMap::createRoad(int& row, int& col)
{
  
    
    std::unique_ptr<Roads> roads = std::make_unique<Roads>(sf::Vector2f(
         col * tileWidth + MARGINX+ 12, row * tileHeight + MARGINY ), row, col, gameObjectId::road);

    m_obj[row][col] = std::move(roads);
    diraction(row, col);

}
void TileMap::diraction(int& row, int& col )
{//make gengeric
    if (row>0 && row<m_rows)
        if (m_obj[row - 1][col]->returnID() == 1 ||
            m_obj[row + 1][col]->returnID() == 1)
        {
            std::cout << "rotate";
            m_obj[row][col]->rotate();
            if (m_obj[row - 1][col]->returnID() == 1 &&
                m_obj[row + 1][col]->returnID() == 1)
            {
                m_obj[row - 1][col]->rotate();
                m_obj[row + 1][col]->rotate();
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
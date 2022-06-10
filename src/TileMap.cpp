#include "TileMap.h"

TileMap::TileMap()
// Change the values when using tiles other than 30x30
        : tileWidth(16*FACTOR)
        , tileHeight(16*FACTOR) {

    m_playerMoney.setFont(*Resources::instance().getFont());

    for (int row = 0; row < m_rows ; ++row) {
        vector<std::unique_ptr<PlacebleObject>> temp;
        for (int col= 0; col < m_cols; col++) {

                temp.push_back(std::make_unique<Ground>(sf::Vector2f(
                       col * tileWidth+MARGINX, row * tileWidth + MARGINY),row,col,gameObjectId::TileSheet,FACTOR,0,0,0,0));
        }
        m_obj.push_back(std::move(temp));
    }
}
//---------------------------------------------
bool TileMap::draw(sf::RenderWindow &window,std::pair<int,int> dims)
{

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
    m_playerMoney.setString("funds " +std::to_string(m_player.getMoney()));
    m_playerMoney.setPosition(50,25);
    window.draw(m_playerMoney);
    return (m_player.gameOver());


}
void TileMap::updateMoney() {
    for (int row = 0; row < m_rows; row++) {
        // Loop through the columns
        for (int col = 0; col < m_cols; col++) {
           m_player.transaction(m_obj[row][col]->calcRate());
           m_player.transaction(-m_obj[row][col]->maintanceCost());


        }

    }
}
//---------------------------------------------

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

                        std::unique_ptr<Commercial> commercial = std::make_unique<Commercial>(sf::Vector2f(
                                                                                                      col * tileWidth + MARGINX + 12,
                                                                                                      row * tileWidth + MARGINY), row, col,
                                                                                              gameObjectId::comPlace,PlacebleObjectFactor,id,r_commercial,c_commercial,m_commercial);

                        m_obj[row][col] = std::move(commercial);
                        m_player.transaction( -m_obj[row][col]->buildCost());

                        factor2Check(row, col, retflag);
                    }
                 else if (id == 5)
                {
                    int retflag;

                    std::cout << "comm";
                    std::unique_ptr<Residence> residence = std::make_unique<Residence>(sf::Vector2f(
                                                                                                  col * tileWidth + MARGINX + 12, row * tileWidth + MARGINY), row, col,
                                                                                          gameObjectId::resPlace,PlacebleObjectFactor,id,r_ressidance,c_ressidance,m_ressidance);

                    m_obj[row][col] = std::move(residence);
                    m_player.transaction( -m_obj[row][col]->buildCost());

                    factor2Check(row, col, retflag);
                }
                    else if (id == 4)
                    {
                        int retflag;

                        std::cout << "comm";
                        std::unique_ptr<Indastrial> indastrial =  std::make_unique<Indastrial>(sf::Vector2f(
                                                                                                   col * tileWidth + MARGINX + 12, row * tileWidth + MARGINY), row, col,
                                                                                           gameObjectId::inPlace,PlacebleObjectFactor,id,r_indastrial,c_indastrial,m_indastrial);

                        m_obj[row][col] = std::move(indastrial);
                        m_player.transaction( -m_obj[row][col]->buildCost());

                        factor2Check(row, col, retflag);
                    }
                    else if (id == 6)
                    {
                        int retflag;

                        std::cout << "comm";
                        std::unique_ptr<PowerLines> powerLines = std::make_unique<PowerLines>(sf::Vector2f(
                                col * tileWidth + MARGINX+ 12, row * tileHeight + MARGINY ), row, col, gameObjectId::psLines,PlacebleObjectFactor,id,r_powerline,c_powerline,m_powerline);

                        m_obj[row][col] = std::move(powerLines);
                        m_player.transaction( -m_obj[row][col]->buildCost());
                        diraction(row, col);

                        factor2Check(row, col, retflag);
                    }
                    else if (id == 7)
                    {
                        int retflag;

                        std::cout << "comm";
                        std::unique_ptr<PowerSource> powerSource = std::make_unique<PowerSource>(sf::Vector2f(
                                                                                                       col * tileWidth + MARGINX + 12, row * tileWidth + MARGINY), row, col,
                                                                                               gameObjectId::psSource,PlacebleObjectFactor,id,r_powerSource,c_powerSource,m_powerSource);

                        m_obj[row][col] = std::move(powerSource);
                        m_player.transaction( -m_obj[row][col]->buildCost());

                        factor2Check(row, col, retflag);
                    }
                }
                else if (id == 3) {
                    int retflag;

                    std::cout << "delete";
                    std::unique_ptr<Ground> ground = std::make_unique<Ground>(sf::Vector2f(
                        col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col, gameObjectId::TileSheet,FACTOR,id,r_delete,c_delete,m_delete);

                    m_obj[row][col] = std::move(ground);
                    m_player.transaction( -m_obj[row][col]->buildCost());

                    factor2Check(row, col, retflag);

                }

            }
        }
    }
    //id=-1;
}

//--------------------------------------------------------------------------
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

//--------------------------------------------------------------------------
void TileMap::createRoad(int& row, int& col)
{
  
    
    std::unique_ptr<Roads> roads = std::make_unique<Roads>(sf::Vector2f(
         col * tileWidth + MARGINX+ 12, row * tileHeight + MARGINY ), row, col, gameObjectId::roadHor,PlacebleObjectFactor,1,r_road,c_road,m_road);

    m_obj[row][col] = std::move(roads);
    m_player.transaction( -m_obj[row][col]->buildCost());
    diraction(row, col);

}

//--------------------------------------------------------------------------
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
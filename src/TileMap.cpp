#include "TileMap.h"

TileMap::TileMap()
// Change the values when using tiles other than 30x30
        : tileWidth(16 * FACTOR), tileHeight(16 * FACTOR) {

    m_playerMoney.setFont(*Resources::instance().getFont());//move it to Controller
    m_playerResidance.setFont(*Resources::instance().getFont());//move it to Controller

    m_playerMoney.setFillColor(sf::Color::Black);
    m_playerResidance.setFillColor(sf::Color::Black);

    for (int row = 0; row < m_rows; ++row) {
        vector<std::unique_ptr<PlacebleObject>> temp;
        for (int col = 0; col < m_cols; col++) {

            temp.push_back(std::make_unique<Ground>(sf::Vector2f(
                                                            col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col, gameObjectId::TileSheet, FACTOR, 0,
                                                    0, 0, 0));
        }
        m_obj.push_back(std::move(temp));
    }
}

//---------------------------------------------
bool TileMap::draw(sf::RenderWindow &window, std::pair<int, int> dims, float deltaTime) {

    // Loop through the rows
    for (auto &row: m_obj) {
        // Loop through the columns
        for (auto &col: row) {
            // Add / remove cases when tiles are added / removed

            if (col->returnID() == 0)
                col->show(window, 0, deltaTime);

            // Set the correct part of the spritesheet

        }
    }
    for (auto &row: m_obj) {
        // Loop through the columns
        for (auto &col: row) {
            // Add / remove cases when tiles are added / removed

            if (col->returnID()
                != 0)
                col->show(window, 0, deltaTime);

            // Set the correct part of the spritesheet

        }
    }

    for (int row = 0; row < m_rows; row++) {
        // Loop through the columns
        for (int col = 0; col < m_cols; col++) {

            check(row, col);
        }
    }


    m_playerMoney.setString("funds " + std::to_string(m_player.getMoney()));
    m_playerResidance.setString("residence " + std::to_string(m_player.getRes()));

    m_playerMoney.setPosition(50, 8);
    m_playerResidance.setPosition(50, 25);

    window.draw(m_playerMoney);
    window.draw(m_playerResidance);// maybe add to conteoller

    return (m_player.gameOver());


}

void TileMap::updateMoney() {
    for (auto &row: m_obj) {
        // Loop through the columns
        for (auto &col: row) {
            if (col->isResConnected()) {
                if (col->returnID() != 5)
                    m_player.transaction(col->calcRate());


            }

            m_player.transaction(-col->maintanceCost());


        }

    }
}


void TileMap::updateAnim() {
    for (auto &row: m_obj) {
        // Loop through the columns
        for (auto &col: row) {

            if (col->changeAnim())
                m_player.ressidanceAdd(30);


        }

    }
}
//---------------------------------------------

void TileMap::update(sf::Vector2f mousePos, int &id) {


    for (int row = 0; row < m_rows; row++) {
        // Loop through the columns
        for (int col = 0; col < m_cols; col++) {


            handleClick(mousePos, id, row, col);

        }
    }
    //id=-1;
}

void TileMap::handleClick(sf::Vector2f &mousePos, const int &id, int &row, int &col) {
    if (m_obj[row][col]->checkClick(mousePos)) {
        //  int retflag;
        //factor2Check(row, col, retflag);
        //if (retflag == 2) break;

        if (m_obj[row][col]->returnID() == 0) {

            // if(m_obj[row-1][col]->returnID() == 0)
            if (id == 1) {
                createRoad(row, col);
            } else if (id == 2) {


                std::__1::unique_ptr<Commercial> commercial = std::__1::make_unique<Commercial>(sf::Vector2f(
                                                                                                        col * tileWidth + MARGINX,
                                                                                                        row * tileWidth + MARGINY), row, col,
                                                                                                gameObjectId::comPlace,
                                                                                                PlacebleObjectFactor,
                                                                                                id,
                                                                                                r_commercial,
                                                                                                c_commercial,
                                                                                                m_commercial);

                m_obj[row][col] = std::move(commercial);
                m_player.transaction(-m_obj[row][col]->buildCost());

            } else if (id == 5) {


                std::__1::unique_ptr<Residence> residence = std::__1::make_unique<Residence>(sf::Vector2f(
                                                                                                     col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col,
                                                                                             gameObjectId::resPlace,
                                                                                             PlacebleObjectFactor, id,
                                                                                             r_ressidance, c_ressidance,
                                                                                             m_ressidance);
                m_player.numOfTotalBuildings(1, 0);
                m_obj[row][col] = std::move(residence);
                m_player.transaction(-m_obj[row][col]->buildCost());

                //  check(row, col, 1);
            } else if (id == 4) {


                std::__1::unique_ptr<Indastrial> indastrial = std::__1::make_unique<Indastrial>(sf::Vector2f(
                                                                                                        col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col,
                                                                                                gameObjectId::inPlace,
                                                                                                PlacebleObjectFactor,
                                                                                                id,
                                                                                                r_indastrial,
                                                                                                c_indastrial,
                                                                                                m_indastrial);

                m_obj[row][col] = std::move(indastrial);
                m_player.transaction(-m_obj[row][col]->buildCost());

                // check(row, col, retflag);
            } else if (id == 6) {
                int retflag;

                std::__1::unique_ptr<PowerLines> powerLines = std::__1::make_unique<PowerLines>(sf::Vector2f(
                                                                                                        col * tileWidth + MARGINX, row * tileHeight + MARGINY), row, col, gameObjectId::psLines,
                                                                                                PlacebleObjectFactor,
                                                                                                id,
                                                                                                r_powerline,
                                                                                                c_powerline,
                                                                                                m_powerline);

                m_obj[row][col] = std::move(powerLines);
                m_player.transaction(-m_obj[row][col]->buildCost());
                diraction(row, col);
                //check(row, col, id);
            } else if (id == 7) {
                int retflag;

                std::__1::unique_ptr<PowerSource> powerSource = std::__1::make_unique<PowerSource>(sf::Vector2f(
                                                                                                           col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col,
                                                                                                   gameObjectId::psSource,
                                                                                                   PlacebleObjectFactor,
                                                                                                   id, r_powerSource,
                                                                                                   c_powerSource,
                                                                                                   m_powerSource);

                m_obj[row][col] = std::move(powerSource);
                m_player.transaction(-m_obj[row][col]->buildCost());

                // check(row, col, id);
            }
        } else if (id == 3) {
            int retflag;
            del(row, col);

            std::__1::unique_ptr<Ground> ground = std::__1::make_unique<Ground>(sf::Vector2f(
                                                                                        col * tileWidth + MARGINX, row * tileWidth + MARGINY), row, col, gameObjectId::TileSheet,
                                                                                FACTOR, 0, r_delete, c_delete,
                                                                                m_delete);


            m_obj[row][col] = std::move(ground);
            m_player.transaction(-m_obj[row][col]->buildCost());

            //check(row, col, retflag);

        } else if (id == 1 && m_obj[row][col]->returnID() == 6 ||
                   id == 6 && m_obj[row][col]->returnID() == 1) {

            m_obj[row][col]->roadpLine(true);

        }


    }
}

void TileMap::del(int row, int col) {


    if (row < 1 || row > m_rows - 2 || col < 1 || col > m_cols - 2)
        return;
    //for (int row = 0; row < m_rows; row++) {
    // Loop through the columns
    // for (int col = 0; col < m_cols; col++) {
    if (m_obj[row][col]->returnID() != 0) {
        if (m_obj[row][col]->returnID() == 5)
            m_player.numOfTotalBuildings(-1, 10);

        if (m_obj[row - 1][col]->returnID() != 0) {
            //  m_obj[row - 1][col]->roadpLine(false);
            m_obj[row - 1][col]->connectPower(false);
        }
        //std::cout << row - 1 << col << "UP : " << m_obj[row - 1][col]->returnID() << std::endl;
        if (m_obj[row + 1][col]->returnID() != 0) {
            //    m_obj[row + 1][col]->roadpLine(false);

            m_obj[row + 1][col]->connectPower(false);
        }


        if (m_obj[row][col - 1]->returnID() != 0) {
            //    m_obj[row ][col-1]->roadpLine(false);

            m_obj[row][col - 1]->connectPower(false);
        }
        if (m_obj[row][col + 1]->returnID() != 0) {
            //     m_obj[row ][col+1]->roadpLine(false);

            m_obj[row][col + 1]->connectPower(false);
        }
    }
    //  }
    // }

}

//--------------------------------------------------------------------------
void TileMap::check(int row, int col) {
    // Loop through the rows

    if (m_obj[row][col]->returnID() == 0)
        return;
    if (row < 1 || row > m_rows - 2 || col < 1 || col > m_cols - 2)
        return;


    if (m_obj[row - 1][col]->returnID() != 0)
        processCollision(*m_obj[row][col], *m_obj[row - 1][col]);

    //std::cout << row - 1 << col << "UP : " << m_obj[row - 1][col]->returnID() << std::endl;
    if (m_obj[row + 1][col]->returnID() != 0)
        processCollision(*m_obj[row][col], *m_obj[row + 1][col]);


    if (m_obj[row][col - 1]->returnID() != 0)
        processCollision(*m_obj[row][col], *m_obj[row][col - 1]);
    if (m_obj[row][col + 1]->returnID() != 0)
        processCollision(*m_obj[row][col], *m_obj[row][col + 1]);


}


//--------------------------------------------------------------------------
void TileMap::createRoad(int &row, int &col) {


    std::unique_ptr<Road> roads = std::make_unique<Road>(sf::Vector2f(
                                                                 col * tileWidth + MARGINX, row * tileHeight + MARGINY), row, col, gameObjectId::roadHor,
                                                         PlacebleObjectFactor, 1, r_road, c_road, m_road);

    m_obj[row][col] = std::move(roads);
    m_player.transaction(-m_obj[row][col]->buildCost());
    diraction(row, col);

}

//--------------------------------------------------------------------------
void TileMap::diraction(int &row, int &col) {//make gengeric
    if (row > 0 && row < m_rows)
        if (m_obj[row - 1][col]->returnID() == 1 ||
            m_obj[row + 1][col]->returnID() == 1) {
            m_obj[row][col]->rotate();
            if (m_obj[row - 1][col]->returnID() == 1 &&
                m_obj[row + 1][col]->returnID() == 1) {
                m_obj[row - 1][col]->rotate();
                m_obj[row + 1][col]->rotate();
            }


        }

}

// Check the SFML documentation about intrect if you do not know what is going on here
// Add / remove some when needed (if you use less or more tiles in the texture)
// The value of 30 is the width / height of a tile
// Change if the tiles should be bigger / smaller
void TileMap::initIntRect() {
    m_grass.left = 16;
    m_grass.top = 0;
    m_grass.width = tileWidth / FACTOR;
    m_grass.height = tileHeight / FACTOR;

    m_ground.left = 0;
    m_ground.top = 0;
    m_ground.width = tileWidth / FACTOR;
    m_ground.height = tileHeight / FACTOR;


}
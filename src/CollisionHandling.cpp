#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "PlacebleObject.h"
#include "Road.h"
#include "PowerLines.h"
#include "Commercial.h"

#include "Ground.h"
namespace // anonymous namespace — the standard way to make function "static"
{

// primary collision-processing functions

//--------com collisions------
    void comPower(PlacebleObject &com,
                  PlacebleObject &powerSource) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }
    void comPowerLine(PlacebleObject &com,
                      PlacebleObject &powerLine) {
        com.connectPower(true);
        powerLine.connectPower(true);
        std:: cout <<"line and com collide ! "<<powerLine.isPowerConnected();

    }

    void comRoad(PlacebleObject &com,
                 PlacebleObject &road) {
        std::cout << "road and commercial collision!\n";
    }

    void comCom(PlacebleObject &com,
                PlacebleObject &com2) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void comIn(PlacebleObject &com,
               PlacebleObject &in) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void comRes(PlacebleObject &com,
                PlacebleObject &res) {
        std::cout << "Two SpaceShips collision!\n";
    }
//----------end of com collision --------------------

//---------indes Collision---------------------------

    void inPower(PlacebleObject &in,
                 PlacebleObject &powerSource) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }
    void inPowerLine(PlacebleObject &in,
                     PlacebleObject &powerLine) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }

    void inRoad(PlacebleObject &in,
                PlacebleObject &road) {
        std::cout << "Asteroid and SpaceStation collision!\n";
    }

    void inCom(PlacebleObject &in,
               PlacebleObject &com) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void inIn(PlacebleObject &in,
              PlacebleObject &in2) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void inRes(PlacebleObject &com,
               PlacebleObject &res) {
        std::cout << "Two SpaceShips collision!\n";
    }
//----------end of collision in ---------------------


//---------res Collision---------------------------

    void resPower(PlacebleObject &res,
                  PlacebleObject &powerSource) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }
    void resPowerLine(PlacebleObject &res,
                      PlacebleObject &powerLine) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }

    void resRoad(PlacebleObject &res,
                 PlacebleObject &road) {
        std::cout << "Asteroid and SpaceStation collision!\n";
    }

    void resCom(PlacebleObject &res,
                PlacebleObject &com) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void resIn(PlacebleObject &res,
               PlacebleObject &in) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void resRes(PlacebleObject &res,
                PlacebleObject &res2) {
        std::cout << "Two SpaceShips collision!\n";
    }
//----------end of collision in ---------------------

//---------road Collision---------------------------

    void roadPower(PlacebleObject &road,
                   PlacebleObject &powerSource) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }
    void roadPowerLine(PlacebleObject &road,
                       PlacebleObject &powerLine) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }

    void roadRoad(PlacebleObject &road,
                  PlacebleObject &road2) {
        std::cout << "Asteroid and SpaceStation collision!\n";
    }

    void roadCom(PlacebleObject &road,
                 PlacebleObject &com) {
        comRoad(com,road);
    }

    void roadIn(PlacebleObject &road,
                PlacebleObject &in) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void roadRes(PlacebleObject &road,
                 PlacebleObject &res) {
        std::cout << "Two SpaceShips collision!\n";
    }
//----------end of collision in ---------------------

//---------pLine Collision---------------------------

    void pLinePower(PlacebleObject &pLine,
                    PlacebleObject &powerSource) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }
    void pLinePowerLine(PlacebleObject &pLine,
                        PlacebleObject &powerLine) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }

    void pLineRoad(PlacebleObject &pLine,
                   PlacebleObject &road) {
        std::cout << "Asteroid and SpaceStation collision!\n";
    }

    void pLineCom(PlacebleObject &pLine,
                  PlacebleObject &com) {
        comPowerLine(com,pLine);
    }

    void pLineIn(PlacebleObject &pLine,
                 PlacebleObject &in) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void pLineRes(PlacebleObject &pLine,
                  PlacebleObject &res) {
        std::cout << "Two SpaceShips collision!\n";
    }
//----------end of collision in ---------------------

    void ground(PlacebleObject &som,
                  PlacebleObject &ground) {
        std::cout << "Two SpaceShips collision!\n";
    }
//...

    using HitFunctionPtr = void (*)(PlacebleObject &, PlacebleObject &);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
// std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap() {
        HitMap phm;
        phm[Key(typeid(Road), typeid(Commercial))] = &comRoad;
        phm[Key(typeid(Commercial), typeid(Road))] = &roadCom;

        phm[Key(typeid(PowerLines), typeid(Commercial))] = &pLineCom;
        phm[Key(typeid(Commercial), typeid(PowerLines))] = &comPowerLine;
        phm[Key(typeid(Commercial), typeid(Ground))] = &ground;
        phm[Key(typeid(Ground), typeid(Commercial))] = &ground;

        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index &class1, const std::type_index &class2) {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end()) {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(PlacebleObject &object1, PlacebleObject &object2) {
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf) {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}

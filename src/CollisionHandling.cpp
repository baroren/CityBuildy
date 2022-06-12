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
#include "Indastrial.h"
#include "PowerSource.h"
#include "Ground.h"
#include "Residence.h"

namespace // anonymous namespace — the standard way to make function "static"
{

// primary collision-processing functions
    void ground(PlacebleObject &som,
                PlacebleObject &ground) {
        som.connectPower(false);
        som.connectPowerSource(false);
        std::cout << "Two SpaceShips collision!\n";
    }

//--------com collisions------
    void comPower(PlacebleObject &com,
                  PlacebleObject &powerSource) {
        std::cout << "SpaceShip and SpaceStation collision!\n";
    }

    void comPowerLine(PlacebleObject &com,
                      PlacebleObject &powerLine) {


        com.connectPowerSource(true);
        com.connectPower(true);
        powerLine.connectPower(true);
        //  std:: cout <<"line and com collide ! "<<powerLine.isPowerConnected();

    }

    void comRoad(PlacebleObject &com,
                 PlacebleObject &road) {
        std::cout << "road and commercial collision!\n";
    }

    void comCom(PlacebleObject &com,
                PlacebleObject &com2) {
        //make generic






        if (com.isPowerConnected())
            com2.connectPower(true);


        // else if (!com.isPowerConnected())
        //     com2.connectPower(false);


        if (com2.isPowerConnected())
            com.connectPower(true);

    }

    void comIn(PlacebleObject &com,
               PlacebleObject &in) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void comRes(PlacebleObject &com,
                PlacebleObject &res) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void comGround(PlacebleObject &com,
                   PlacebleObject &res) {
        ground(res, com);
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
        comPowerLine(res, powerLine);
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
        comCom(res, res2);
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
        comRoad(com, road);
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
        comPowerLine(com, pLine);
    }

    void pLineIn(PlacebleObject &pLine,
                 PlacebleObject &in) {
        std::cout << "Two SpaceShips collision!\n";
    }

    void pLineRes(PlacebleObject &pLine,
                  PlacebleObject &res) {
resPowerLine(res,pLine);
    }
//----------end of collision in ---------------------


//...

    using HitFunctionPtr = void (*)(PlacebleObject &, PlacebleObject &);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
// std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap() {
        HitMap phm;
        phm[Key(typeid(Commercial), typeid(Road))] = &roadCom;
        phm[Key(typeid(Commercial), typeid(PowerLines))] = &comPowerLine;
        phm[Key(typeid(Commercial), typeid(Ground))] = &ground;
        phm[Key(typeid(Commercial), typeid(Residence))] = &comRes;
        phm[Key(typeid(Commercial), typeid(Indastrial))] = &comIn;
        phm[Key(typeid(Commercial), typeid(Commercial))] = &comCom;

        phm[Key(typeid(Residence), typeid(Road))] = &resRoad;
        phm[Key(typeid(Residence), typeid(PowerLines))] = &resPowerLine;
        phm[Key(typeid(Residence), typeid(Ground))] = &ground;
        phm[Key(typeid(Residence), typeid(Residence))] = &resRes;
        phm[Key(typeid(Residence), typeid(Indastrial))] = &resIn;
        phm[Key(typeid(Residence), typeid(Commercial))] = &resCom;

        phm[Key(typeid(PowerLines), typeid(Commercial))] = &pLineCom;
        phm[Key(typeid(PowerLines), typeid(Residence))] = &pLineRes;

        phm[Key(typeid(Road), typeid(Commercial))] = &comRoad;


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

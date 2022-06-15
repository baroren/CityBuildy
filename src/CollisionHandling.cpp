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
    void twoAreaCollide(PlacebleObject &com, PlacebleObject &com2);

    void twoAreaCollide(PlacebleObject &com, PlacebleObject &com2) {
        if (com.isPowerConnected())
            com2.connectPower(true);

        if (com2.isPowerConnected())
            com.connectPower(true);
    }

// primary collision-processing functions


//--------com collisions------
    void comPower(PlacebleObject &com,
                  PlacebleObject &powerSource) {

        com.connectPowerSource(true);
        com.connectPower(true);
    }

    void comPowerLine(PlacebleObject &com,
                      PlacebleObject &powerLine) {

        if (powerLine.isPowerConnected()) {
            com.connectPowerSource(true);
            com.connectPower(true);
        }
        //  std:: cout <<"line and com collide ! "<<powerLine.isPowerConnected();

    }

    void comRoad(PlacebleObject &com,
                 PlacebleObject &road) {
        if (road.isroadpLineConnected())
            comPowerLine(com, road);

        if (road.isResConnected())
            com.roadToResconnected(true);


        // std::cout << "comRoad\n";
        //}

    }


    void comCom(PlacebleObject &com,
                PlacebleObject &com2) {
        //make generic

        twoAreaCollide(com, com2);

    }


    void comIn(PlacebleObject &com,
               PlacebleObject &in) {
        twoAreaCollide(com, in);
        com.happy(-1);

    }

    void comRes(PlacebleObject &com,
                PlacebleObject &res) {
        twoAreaCollide(com, res);

            com.roadToResconnected(true);


    }

    void comGround(PlacebleObject &com,
                   PlacebleObject &res) {
        //ground(res, com);
    }
//----------end of com collision --------------------

//---------indes Collision---------------------------

    void inPower(PlacebleObject &in,
                 PlacebleObject &powerSource) {
        comPower(in, powerSource);
    }

    void inPowerLine(PlacebleObject &in,
                     PlacebleObject &powerLine) {
        comPowerLine(in, powerLine);
    }

    void inRoad(PlacebleObject &in,
                PlacebleObject &road) {
        if (road.isroadpLineConnected())
            inPowerLine(in, road);

        if (road.isResConnected())
            in.roadToResconnected(true);

    }

    void inCom(PlacebleObject &in,
               PlacebleObject &com) {
        comIn(com, in);

    }

    void inIn(PlacebleObject &in,
              PlacebleObject &in2) {
        comCom(in, in2);
    }

    void inRes(PlacebleObject &com,
               PlacebleObject &res) {
        twoAreaCollide(com, res);

    }
//----------end of collision in ---------------------


//---------res Collision---------------------------

    void resPower(PlacebleObject &res,
                  PlacebleObject &powerSource) {
        comPower(res, powerSource);
    }

    void resPowerLine(PlacebleObject &res,
                      PlacebleObject &powerLine) {
        comPowerLine(res, powerLine);
    }

    void resRoad(PlacebleObject &res,
                 PlacebleObject &road) {

        if (road.isroadpLineConnected())
            resPowerLine(res, road);

        road.roadToResconnected(true);
    }

    void resCom(PlacebleObject &res,
                PlacebleObject &com) {
        comRes(com, res);
    }

    void resIn(PlacebleObject &res,
               PlacebleObject &in) {

        inRes(res, in);
    }

    void resRes(PlacebleObject &res,
                PlacebleObject &res2) {
        comCom(res, res2);
    }
//----------end of collision in ---------------------

//---------road Collision---------------------------

    void roadPower(PlacebleObject &road,
                   PlacebleObject &powerSource) {

        if (road.isroadpLineConnected())
            road.connectPower(true);
    }

    void roadPowerLine(PlacebleObject &road,
                       PlacebleObject &powerLine) {
        //    powerLine.roadpLine(true);
        //  road.roadpLine(true);
        if (powerLine.isPowerConnected()) {
           if (road.isroadpLineConnected())
                road.connectPower(true);
        }
        // if (road.isroadpLineConnected())
             // road.connectPower(true);


    }

    void roadRoad(PlacebleObject &road,
                  PlacebleObject &road2) {

        comCom(road, road2);


        if (road.isResConnected())
            road2.roadToResconnected(true);

        if (road2.isResConnected())
            road.roadToResconnected(true);


    }

    void roadCom(PlacebleObject &road,
                 PlacebleObject &com) {
        roadPowerLine(road,com);
        comRoad(com, road);
    }

    void roadIn(PlacebleObject &road,
                PlacebleObject &in) {
        roadPowerLine(road,in);

    }

    void roadRes(PlacebleObject &road,
                 PlacebleObject &res) {
        roadPowerLine(road,res);

        resRoad(res,road);
    }
//----------end of collision in ---------------------

//---------pLine Collision---------------------------

    void pLinePower(PlacebleObject &pLine,
                    PlacebleObject &powerSource) {

        pLine.connectPower(true);
        powerSource.connectPower(true);
    }

    void pLinePowerLine(PlacebleObject &pLine,
                        PlacebleObject &powerLine) {
        roadRoad(pLine, powerLine);
        comCom(pLine, powerLine);




    }

    void pLineRoad(PlacebleObject &pLine,
                   PlacebleObject &road) {
        roadPowerLine(road, pLine);
    }

    void pLineCom(PlacebleObject &pLine,
                  PlacebleObject &com) {
        if (com.isPowerConnected())
            pLine.connectPower(true);
        comPowerLine(com, pLine);

    }

    void pLineIn(PlacebleObject &pLine,
                 PlacebleObject &in) {
        inPowerLine(in, pLine);

    }


    void pLineRes(PlacebleObject &pLine,
                  PlacebleObject &res) {
        resPowerLine(pLine, res);
        resRoad(res,pLine);
    }
//----------end of collision in ---------------------

//---------powerSource Collision---------------------------

    void powerSourcePower(PlacebleObject &powerSource,
                          PlacebleObject &powerSource2) {
    }

    void powerSourcePowerLine(PlacebleObject &powerSource,
                              PlacebleObject &powerLine) {
        pLinePower(powerLine, powerSource);
    }

    void powerSourceRoad(PlacebleObject &powerSource,
                         PlacebleObject &road) {
    }

    void powerSourceCom(PlacebleObject &powerSource,
                        PlacebleObject &com) {
        comPower(com, powerSource);
    }

    void powerSourceIn(PlacebleObject &powerSource,
                       PlacebleObject &in) {
        comPower(in, powerSource);
    }

    void powerSourceRes(PlacebleObject &powerSource,
                        PlacebleObject &res) {
        comPower(res, powerSource);
    }


//...

    using HitFunctionPtr = void (*)(PlacebleObject &, PlacebleObject &);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
// std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap() {
        HitMap phm;


        //---------------Commercial------------------------------------
        phm[Key(typeid(Commercial), typeid(Road))] = &roadCom;
        phm[Key(typeid(Commercial), typeid(PowerLines))] = &comPowerLine;
       // phm[Key(typeid(Commercial), typeid(Ground))] = &ground;
        phm[Key(typeid(Commercial), typeid(Residence))] = &comRes;
        phm[Key(typeid(Commercial), typeid(Indastrial))] = &comIn;
        phm[Key(typeid(Commercial), typeid(Commercial))] = &comCom;
        phm[Key(typeid(Commercial), typeid(PowerSource))] = &comPower;



        //---------------Residence------------------------------------
        phm[Key(typeid(Residence), typeid(Road))] = &resRoad;
        phm[Key(typeid(Residence), typeid(PowerLines))] = &resPowerLine;
       // phm[Key(typeid(Residence), typeid(Ground))] = &ground;
        phm[Key(typeid(Residence), typeid(Residence))] = &resRes;
        phm[Key(typeid(Residence), typeid(Indastrial))] = &resIn;
        phm[Key(typeid(Residence), typeid(Commercial))] = &resCom;
        phm[Key(typeid(Residence), typeid(PowerSource))] = &resPower;

        //---------------PowerLine------------------------------------
        phm[Key(typeid(PowerLines), typeid(Road))] = &pLineRoad;
        phm[Key(typeid(PowerLines), typeid(PowerLines))] = &pLinePowerLine;
      //  phm[Key(typeid(PowerLines), typeid(Ground))] = &ground;
        phm[Key(typeid(PowerLines), typeid(Indastrial))] = &pLineIn;
        phm[Key(typeid(PowerLines), typeid(Commercial))] = &pLineCom;
        phm[Key(typeid(PowerLines), typeid(Residence))] = &pLineRes;
        phm[Key(typeid(PowerLines), typeid(PowerSource))] = &pLinePower;

        //---------------PowerSource-------------------------------------
        phm[Key(typeid(PowerSource), typeid(Road))] = &powerSourceRoad;
        phm[Key(typeid(PowerSource), typeid(PowerLines))] = &powerSourcePowerLine;
    //    phm[Key(typeid(PowerSource), typeid(Ground))] = &ground;
        phm[Key(typeid(PowerSource), typeid(Indastrial))] = &powerSourceIn;
        phm[Key(typeid(PowerSource), typeid(Commercial))] = &powerSourceIn;
        phm[Key(typeid(PowerSource), typeid(Residence))] = &powerSourceRes;
        phm[Key(typeid(PowerSource), typeid(PowerSource))] = &powerSourcePower;

        //---------------Road-------------------------------------
        phm[Key(typeid(Road), typeid(Road))] = &roadRoad;
        phm[Key(typeid(Road), typeid(PowerLines))] = &roadPowerLine;
        //phm[Key(typeid(Road), typeid(Ground))] = &ground;
        phm[Key(typeid(Road), typeid(Indastrial))] = &roadIn;
        phm[Key(typeid(Road), typeid(Commercial))] = &roadCom;
        phm[Key(typeid(Road), typeid(Residence))] = &roadRes;
        phm[Key(typeid(Road), typeid(PowerSource))] = &roadPower;

        //---------------Indastrial-------------------------------------
        phm[Key(typeid(Indastrial), typeid(Road))] = &inRoad;
        phm[Key(typeid(Indastrial), typeid(PowerLines))] = &inPowerLine;
     //   phm[Key(typeid(Indastrial), typeid(Ground))] = &ground;
        phm[Key(typeid(Indastrial), typeid(Indastrial))] = &inIn;
        phm[Key(typeid(Indastrial), typeid(Commercial))] = &inCom;
        phm[Key(typeid(Indastrial), typeid(Residence))] = &inRes;
        phm[Key(typeid(Indastrial), typeid(PowerSource))] = &inPower;


       // phm[Key(typeid(Ground), typeid(Commercial))] = &ground;

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

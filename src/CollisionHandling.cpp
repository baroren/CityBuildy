#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "SpaceShip.h"
#include "SpaceStation.h"
#include "Asteroid.h"

namespace // anonymous namespace — the standard way to make function "static"
{

// primary collision-processing functions
void shipAsteroid(GameObject& spaceShip,
                  GameObject& asteroid)
{
    // To get the actual types and use them:
    // SpaceShip& ship = dynamic_cast<SpaceShip&>(spaceShip);
    // Asteroid&  ast  = dynamic_cast<Asteroid&>(asteroid);
    // or:
    // SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
    // Asteroid&  ast  = static_cast<Asteroid&>(asteroid);

    std::cout << "SpaceShip and Asteroid collision!\n";
}

void shipStation(GameObject& spaceShip,
                 GameObject& spaceStation)
{
    std::cout << "SpaceShip and SpaceStation collision!\n";
}

void asteroidStation(GameObject& asteroid,
                     GameObject& spaceStation)
{
    std::cout << "Asteroid and SpaceStation collision!\n";
}

void shipShip(GameObject& spaceShip1,
              GameObject& spaceShip2)
{
    std::cout << "Two SpaceShips collision!\n";
}

//...

// secondary collision-processing functions that just
// implement symmetry: swap the parameters and call a
// primary function
void asteroidShip(GameObject& asteroid,
                  GameObject& spaceShip)
{
    shipAsteroid(spaceShip, asteroid);
}
void stationShip(GameObject& spaceStation,
                 GameObject& spaceShip)
{
    shipStation(spaceShip, spaceStation);
}
void stationAsteroid(GameObject& spaceStation,
                     GameObject& asteroid)
{
    asteroidStation(asteroid, spaceStation);
}
//...

using HitFunctionPtr = void (*)(GameObject&, GameObject&);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
// std::unordered_map is better, but it requires defining good hash function for pair
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap()
{
    HitMap phm;
    phm[Key(typeid(SpaceShip   ), typeid(Asteroid    ))] = &shipAsteroid;
    phm[Key(typeid(SpaceShip   ), typeid(SpaceStation))] = &shipStation;
    phm[Key(typeid(Asteroid    ), typeid(SpaceStation))] = &asteroidStation;
    phm[Key(typeid(SpaceShip   ), typeid(SpaceShip   ))] = &shipShip;
    phm[Key(typeid(Asteroid    ), typeid(SpaceShip   ))] = &asteroidShip;
    phm[Key(typeid(SpaceStation), typeid(SpaceShip   ))] = &stationShip;
    phm[Key(typeid(SpaceStation), typeid(Asteroid    ))] = &stationAsteroid;
    //...
    return phm;
}

HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}

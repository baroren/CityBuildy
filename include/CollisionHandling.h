#pragma once

#include "PlacebleObject.h"
#include <iostream>
#include <typeinfo>

// Sample struct for exception throwing
struct UnknownCollision : public std::runtime_error
{
    UnknownCollision(PlacebleObject& a, PlacebleObject& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    {
    }
};

void processCollision(PlacebleObject& object1, PlacebleObject& object2);

#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "Residence.h"
#include "Commercial.h"
#include "Road.h"
#include "Indastrial.h"
#include "Ground.h"
#include "PowerLines.h"
#include "PowerSource.h"

#include "PlacebleObject.h"


class Factory {
public:
    using pFnc = std::unique_ptr<PlacebleObject>(*)(sf::Vector2f pos, int row, int col
                                                    );
    static std::unique_ptr<PlacebleObject> create(const std::string& name,sf::Vector2f pos, int row, int col);
    static void registerit(const std::string& name, pFnc f);
private:
    static auto& getMap() {
        static std::map<std::string, pFnc> map;
        return map;
    }
};
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
#include "Area.h"

class Commercial : public Area {
public:

    using Area::Area;
    void money(){if(currAnim==3)r_commercial=200;}
private:
    std::pair<int, int> pos;

};
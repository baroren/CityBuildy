#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Resources.h"
#include "Conectors.h"
#include "Macros.h"
#include "Area.h"
#include "ProgressBar.h"


class CRIclass {
public:
    CRIclass() {}

    void calcCRI(int c = 0, int r = 0, int i = 0);

    void update();
    int getCRI(CRI id){return m_CRI[int(id)];};
    //void CRIdraw(sf::RenderWindow &window){progressBar.progressBarDraw(window);};

private:

    // ProgressBar progressBar;

    std::array<string, 3> m_need = {"need more commercial! ", "need more residence!", "need more Indastrial!"};
    std::array<int, 3> m_CRI{};

};



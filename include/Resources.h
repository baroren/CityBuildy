#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <array>

#include "Macros.h"

using std::vector;
using std::string;

class Resources
{
public:
    Resources(const Resources &) = delete;

    static Resources &instance();
    void operator=(const Resources &) = delete;
    sf::Music* getMusic(gameObjectId id);
    void buildMusic();

    sf::Texture *getTexture(gameObjectId id);
    sf::Font* getFont() ;
    sf::Sprite *getSprite(gameObjectId id); // todo
    int getImageCount(gameObjectId id){return numOfFrames[int(id)];};

private:
    Resources();
    void buildTexture();
    void buildSprite();
    sf::Texture m_temp;
    std::array <sf::Sprite, numOfSprites> m_sprite;
    std::array <sf::Texture, numOfSprites> m_texture;
    vector <string> m_imagePath = {"CityBuildyMAIN","outdoors","road","comm","destroy","indast","resident","powerLine",
                                   "powerSource","park","roadHor","comPlace","resPlace"
                                   ,"inPlace","PowerSourcePlace","powerLinePlace","bg","grass","save","zoomIn","zoomOut"
                                                                                                               ,"left","up","down","right","gameOver"};
    vector <string> m_musicNames={"MainMenuMusic.ogg"};
   // vector<Animation *> m_animation;
    sf::Music m_music;
    int numOfAnim=1;
    std::array<int,numOfSprites> numOfFrames{ 1,1 ,1,
                                              1,1,1,1,
                                              1,1,1,2,
                                              4,3,3,1,
                                              2,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    sf::Font m_font;
};
#include "Resources.h"

Resources::Resources() {
    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
       // error...
        std::cout << "error loading font";

   }
    buildTexture();
    //buildAnimation();
    buildSprite();
     buildMusic();
    //add sound
}
// ----------------------------------------------------------------------------

void Resources::buildTexture() {
    for(int i=0;i<m_imagePath.size();i++) {
        if (!m_texture[i].loadFromFile(m_imagePath[i] + ".png"))
            exit(EXIT_FAILURE);
        /*
        if (!m_temp.loadFromFile(m_imagePath[i]+".png")) {
            // error...
            std::cout << "error loading font";

        }
        m_texture.push_back(m_temp);
        */
    }
}
// ----------------------------------------------------------------------------

sf::Texture* Resources::getTexture(gameObjectId id)
{
    return &m_texture[(int)id];
}
// ----------------------------------------------------------------------------

sf::Sprite* Resources::getSprite(gameObjectId id)
{
    return &m_sprite[(int)id];

}
// ----------------------------------------------------------------------------

sf::Font* Resources::getFont()
{
    return &m_font;
}

// ----------------------------------------------------------------------------

void Resources::buildSprite()
{
    for(int i=0;i<m_imagePath.size();i++) {
        m_sprite[i].setTexture(m_texture[i]);
        m_sprite[i].setOrigin(m_sprite[i].getGlobalBounds().width/numOfFrames[i] /2.f,m_sprite[i].getGlobalBounds().height /numOfFrames[i]/2.f);

    }
}

// ----------------------------------------------------------------------------
void Resources::playMusic(gameObjectId id)
{
    m_music.play();

}
// ----------------------------------------------------------------------------
void Resources::stopMusic(gameObjectId id)
{
    m_music.stop();

}
// ----------------------------------------------------------------------------

void Resources::buildMusic()
{

    for(int i=0;i<m_musicNames.size();i++) {
        // sf::Music temp;
        if (!m_music.openFromFile(m_musicNames[i])) {
            // error...
           throw(std::logic_error("Music\n"));

        }
        // m_music.push_back(temp);
    }
}
// ----------------------------------------------------------------------------

Resources& Resources:: instance(){
    static auto resources=Resources();
    return resources;
}
// ----------------------------------------------------------------------------






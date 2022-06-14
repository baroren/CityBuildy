#include "ProgressBar.h";

ProgressBar::ProgressBar(float x, float y, float width, float height, bool bg, sf::Color color, int rate) : m_width(
        width), m_rate(rate) {
    if (bg) {
        m_barBack.setFillColor(sf::Color(255, 255, 255));
        m_barBack.setOutlineThickness(2);
    }
    m_barInner.setFillColor(color);


}

void ProgressBar::progressBarDraw(sf::RenderWindow& window) {
    if (m_width < 0)
        return;


    window.draw(m_barBack);

    window.draw(m_barInner);


}
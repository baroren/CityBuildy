#include "Factory.h"

std::unique_ptr<PlacebleObject> Factory::create(const std::string &name, sf::Vector2f pos, int row, int col) {
    static bool initial = true;
    if (initial) {

        registerit(std::to_string(int(classId::res)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<Residence>(pos, row, col, gameObjectId::resPlace, PlacebleObjectFactor,
                                               int(classId::res), r_ressidance, c_ressidance, m_ressidance);
        });
        registerit(std::to_string(int(classId::com)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<Commercial>(pos, row, col, gameObjectId::comPlace, PlacebleObjectFactor,
                                               int(classId::com), r_commercial, r_commercial, m_commercial);
        });
        registerit(std::to_string(int(classId::in)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<Indastrial>(pos, row, col, gameObjectId::inPlace, PlacebleObjectFactor,
                                                int(classId::in), r_indastrial, c_indastrial, m_indastrial);
        });
        registerit(std::to_string(int(classId::road)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<Road>(pos, row, col, gameObjectId::roadHor, PlacebleObjectFactor,
                                          int(classId::road), r_road, c_road, m_road);
        });
        registerit(std::to_string(int(classId::pl)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<PowerLines>(pos, row, col, gameObjectId::psLines, PlacebleObjectFactor,
                                          int(classId::pl), r_powerline, c_powerline, m_powerline);
        });
        registerit(std::to_string(int(classId::ps)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<PowerSource>(pos, row, col, gameObjectId::psSource, PlacebleObjectFactor,
                                                int(classId::ps), r_powerSource, c_powerSource, m_powerSource);
        });
        registerit(std::to_string(int(classId::ground)), [](sf::Vector2f pos, int row, int col) ->
                std::unique_ptr<PlacebleObject> {
            return std::make_unique<PowerSource>(pos, row, col, gameObjectId::TileSheet, FACTOR,
                                                 int(classId::ground), 0, 0, 0);
        });

        initial = false;
    }

    auto it = Factory::getMap().find(name);
    if (it == Factory::getMap().end())
        return nullptr;
    return it->second(pos, row, col);
}

void Factory::registerit(const std::string &name, pFnc f) {
    Factory::getMap().emplace(name, f);
}
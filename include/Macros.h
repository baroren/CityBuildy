//
// Created by Bar Oren on 14/05/2022.
//
#pragma once
enum class gameObjectId{MainMenuBG,TileSheet,road,comm,destroy,indast,park,powerLine,
    powerSource,resident,roadHor,comPlace,resPlace};
enum class sideMenuId{S_road=1,S_com=2,S_del=3,S_facroty=4,S_park=5,S_powerLine,S_PowerPlant};
const int numOfSprites=20,MARGINX=600,MARGINY=200;
 static int FACTOR=3,PlacebleObjectFactor=1;
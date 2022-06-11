//
// Created by Bar Oren on 14/05/2022.
//
#pragma once
enum class gameObjectId{MainMenuBG,TileSheet,road,comm,destroy,indast,resident,powerLine,
    powerSource,park,roadHor,comPlace,resPlace,inPlace,psSource,psLines};
enum class checkConector{road=1,powerLines=6};
enum class sideMenuId{S_road=1,S_com=2,S_del=3,S_facroty=4,S_park=5,S_powerLine,S_PowerPlant};
const int numOfSprites=20,MARGINX=300,MARGINY=100,
        c_ressidance=30,c_road=10,c_commercial=90,c_indastrial=50,c_delete=10,
        c_powerline=10,c_powerSource=100,
        m_ressidance=10,m_road=5,m_commercial=30,m_indastrial=10,m_delete=0,
        m_powerline=5,m_powerSource=300,
        r_ressidance=30,r_road=0,r_commercial=90,r_indastrial=50,r_delete=0,
        r_powerline=10,r_powerSource=0;
static int FACTOR=3,PlacebleObjectFactor=1, month = 2;


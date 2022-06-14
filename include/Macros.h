//
// Created by Bar Oren on 14/05/2022.
//
#pragma once
enum class gameObjectId{MainMenuBG,TileSheet,road,comm,destroy,indast,resident,powerLine,
    powerSource,park,roadHor,comPlace,resPlace,inPlace,psSource,psLines,bg,grass};
enum class sideMenuId{S_road=1,S_com=2,S_del=3,S_facroty=4,S_park=5,S_powerLine,S_PowerPlant};
const int numOfSprites=20,MARGINX=300,MARGINY=100;


static int FACTOR=3,PlacebleObjectFactor=1, month = 2,
        c_ressidance=30,c_road=10,c_commercial=90,c_indastrial=50,c_delete=10,
        c_powerline=10,c_powerSource=300,
        m_ressidance=0,m_road=10,m_commercial=0,m_indastrial=0,m_delete=0,
        m_powerline=10,m_powerSource=0,//-
        r_ressidance=0,//will calculate in  taxes
        r_road=0,r_commercial=300,r_indastrial=200,r_delete=0,
        r_powerline=0,r_powerSource=0;//+
enum class playerData{resBuilsing,comBuilding,inBuilding};
enum class CRI{C,R,I};

enum class classId {ground,road,com,del,in,res,pl,ps};

const int tileWidth=16*FACTOR;
const int tileHeight=16*FACTOR;
const int CAL = 100;

//
// Created by Bar Oren on 14/05/2022.
//
#pragma once
enum class gameObjectId{MainMenuBG,TileSheet,road,comm,destroy,indast,resident,powerLine,
    powerSource,park,roadHor,comPlace,resPlace,inPlace,
    psSource,psLines,bg,grass,save,zoomIn,zoomOut,left,up,down,right,gameover};
enum class popUps{gameover};
const int POPUPSIZE=1;
enum class sideMenuId{S_road=1,S_com=2,S_del=3,S_facroty=4,S_park=5,S_powerLine,S_PowerPlant};
const int numOfSprites=30,MARGINX=900,MARGINY=900;

const sf::Vector2f maxSize(50*16*3,50*16*3);
static int FACTOR=3,PlacebleObjectFactor=1, month = 2,
        c_ressidance=30,c_road=10,c_commercial=90,c_indastrial=50,c_delete=10,
        c_powerline=10,c_powerSource=300,
        m_ressidance=50,m_road=10,m_commercial=100,m_indastrial=100,m_delete=0,
        m_powerline=10,m_powerSource=200,//-
        r_ressidance=0,//will calculate in  taxes
        r_road=0,r_commercial=150,r_indastrial=120,r_delete=0,
        r_powerline=0,r_powerSource=0;//+
enum class playerData{resBuilsing,comBuilding,inBuilding};
enum class CRI{C,R,I};
const float m_zoomRate=0.2;
const int MOVE=100;
enum class classId {ground,road,com,del,in,res,pl,ps};

const int tileWidth=16*FACTOR;
const int tileHeight=16*FACTOR;
const int CAL = 100,startYear=1920;


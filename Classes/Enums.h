#pragma once

#define GET_OBJECT_LAYER    dynamic_cast<ObjectLayer*>(cocos2d::Director::getInstance()->getRunningScene()->getChildByName("GameScene")->getChildByName("ListenerLayer")->getChildByName("ObjectLayer"))
#define GET_MAP_LAYER       dynamic_cast<MapLayer*>(cocos2d::Director::getInstance()->getRunningScene()->getChildByName("GameScene")->getChildByName("ListenerLayer")->getChildByName("MapLayer"))
#define GET_UI_LAYER        dynamic_cast<UILayer*>(cocos2d::Director::getInstance()->getRunningScene()->getChildByName("GameScene")->getChildByName("UILayer"))




enum BodyShape
{
    CIRCLE,
    BOX,
};

enum Direction
{
    E,
    W,
    N,
    S,

};

enum TankAction
{
    MOVE_LEFT,
    MOVE_RIGHT,
    SHOT,
    DEGREE_UP,
    DEGREE_DOWN,
    ACTION_NONE,
};

enum GameResult
{
    WIN,
    LOSE,
};

enum MissileType
{
    MISSILE_NONE,
    DIRT_DESTROYER,
    TANK_DESTROYER,
    DIRT_MAKER,
};

enum Team
{
    TEAM_NONE,
    TEAM_A,
    TEAM_B,
};

enum UnitType
{
    UNIT_NONE,
    UNIT_TANK,
    UNIT_MISSILE,
};
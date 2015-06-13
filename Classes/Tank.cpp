#include "cocos2d.h"
#include "Tank.h"
#include "GameManager.h"
#include "ObjectLayer.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

Tank::Tank(int unitId)
{
    m_UnitType = UNIT_TANK;
    m_UnitID = unitId;
}


Tank::~Tank()
{
}



#pragma once
#include <map>
#include "Enums.h"
#include "cocos2d.h"
#include "Unit.h"
#include "Tank.h"
USING_NS_CC;

class Unit;
class Missile;

#define GET_IM GameManager::getInstance().getInputManager()


class ObjectLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(ObjectLayer);


    void Tick(float dt);
    void CreateMapObject(int unitID, Vec2 pos);
    void AddTank(Unit* tank);
    void AddMissile(Unit* missile);

protected:
  //  std::map<int, std::shared_ptr<Unit>>	m_UnitList;
};

#pragma once
#include "cocos2d.h"

USING_NS_CC;

class MapLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(MapLayer);

    void MakeObject(int id, Vec2 pos);

    PhysicsBody* m_EdgeBox;
};


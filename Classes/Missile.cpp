#include "cocos2d.h"
#include "Missile.h"
#include "GameManager.h"
#include "ObjectLayer.h"
#include "SimpleAudioEngine.h"


using namespace CocosDenshion;

Missile::Missile(Player*owner, Vec2 createPos, int unitId,Team team)
{
    m_UnitType = UNIT_MISSILE;
    m_UnitID = unitId;
    m_Damage = 0;
    m_Scale = 0.6f;
    //m_Speed = 200.0f;
    m_Team = team;
    m_Owner = owner;

    m_Sprite = Sprite::create("Images/Missile.png");
    m_Sprite->setScale(m_Scale);
    auto material = PhysicsMaterial(0.0f, 0.0f, 5.0f);

    m_Body = PhysicsBody::createCircle(m_Sprite->getContentSize().width*m_Scale/3, material);
    //m_Body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height), material);
    m_Body->setRotationEnable(true);
    m_Sprite->setPhysicsBody(m_Body);
    m_Sprite->setPosition(createPos);


}


Missile::~Missile()
{
}


void Missile::MissileCrash()
{
//     if (m_Particle == nullptr) return;
//     m_Particle->stopAllActions();
// 
//     auto action1 = DelayTime::create(1.0f);
//     auto action2 = CallFunc::create(CC_CALLBACK_0(Missile::MissileDelete, this));
//     auto action3 = Sequence::create(action1, action2, NULL);
//     m_Particle->runAction(action3);
// 
//     Effect* effect;
//     auto type = GET_SIDE_TYPE(m_UnitID);

}

void Missile::MissileDelete()
{
//     if (m_Particle == nullptr) return;
//     GET_OBJECT_LAYER->removeChild(m_Particle);
//     m_Particle = nullptr;
//     GET_OBJECT_LAYER->DeleteMissile(m_UnitID);
}

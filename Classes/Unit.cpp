#include "cocos2d.h"
#include "Unit.h"
#include "GameManager.h"
#include "SimpleAudioEngine.h"
#include <memory>
#include "Player.h"
#include "Box2D.h"

using namespace CocosDenshion;


Unit::Unit()
{
    m_UnitType = UNIT_NONE;
    m_PlayerID = -1;
    m_UnitID = -1;
    m_CurHp = m_MaxHp = 0;
    m_Speed = 0;
    m_TargetPos = { 0, 0 };
    m_CurPos = { 0, 0 };

}

Unit::~Unit()
{
}






// 
// void Unit::InitCenterSprite()
// {
//     m_CenterSprite->stopAllActions();
//     m_CenterSprite->setVisible(true);
// }
// 
// void Unit::InitRealSprite()
// {
//     m_RealSprite->stopAllActions();
//     m_RealSprite->setVisible(true);
//     m_RealSprite->setColor(Color3B(255, 255, 255));
// }
// 
// void Unit::SetAllSpriteVisible()
// {
//     m_CenterSprite->setOpacity(255);
//     m_RealSprite->setOpacity(255);
//     m_HpBarFrame->setOpacity(255);
//     if (m_HpBar != nullptr)
//     {
//         m_HpBar->setOpacity(255);
//     }
// }

void Unit::SetHp(int curHp)
{
    if (curHp <= 0)
    {
        m_CurHp = 0;
        return;
    }
    m_CurHp = curHp;
}

// void Unit::SetMyHpBar()
// {
//     SetHeroHpBar("Images/Interface/hp_bar_in.png");
// }
// 
// void Unit::SetEnemyHpBar()
// {
//     SetHeroHpBar("Images/Interface/hp_bar_in_enemy.png");
// }
// 
// void Unit::SetTeamHpBar()
// {
//     SetHeroHpBar("Images/Interface/hp_bar_in_team.png");
// }
// 
// void Unit::SetUnitHpBar()
// {
//     m_HpBarFrame = Sprite::create("Images/Interface/hp_bar_frame_mob.png");
//     m_HpBarFrame->setPosition(Vec2(0, 50));
//     m_CenterSprite->addChild(m_HpBarFrame, 10);
// 
//     m_HpBar = Sprite::create("Images/Interface/hp_bar_in_mob.png");
//     m_HpBar->setAnchorPoint(Vec2(0, 0));
//     m_HpBar->setPosition(Vec2(2, 2));
//     m_HpBarFrame->addChild(m_HpBar);
// }
// 
// void Unit::UpdateHpBar()
// {
//     if (m_HpBar)
//     {
//         Damaged();
//         m_HpBar->setScaleX(m_CurHp / m_MaxHp);
//     }
// }
// 



// void Unit::SetHeroHpBar(const char* barImage)
// {
//     m_HpBarFrame = Sprite::create("Images/Interface/hp_bar_frame.png");
//     m_HpBarFrame->setPosition(Vec2(0, 75));
//     m_CenterSprite->addChild(m_HpBarFrame, 10);
// 
//     m_HpBar = Sprite::create(barImage);
//     m_HpBar->setAnchorPoint(Vec2(0, 0));
//     m_HpBar->setPosition(Vec2(5, 5));
//     m_HpBarFrame->addChild(m_HpBar);
// }

void Unit::Damaged()
{
//     if (GET_MAIN_TYPE(m_UnitID) == UNIT_HERO)
//     {
//         auto hero = dynamic_cast<Hero*>(this);
// 
//         if (hero->GetBuff()->GetBuffNum(BUFF_SHIELD) > 0)
//         {
//             SimpleAudioEngine::getInstance()->playEffect("Music/Effect/shield.mp3");
// 
//         }
//     }
//     {
//         SimpleAudioEngine::getInstance()->playEffect("Music/Effect/damage.mp3");
//     }
// 
//     auto action1 = TintTo::create(0, 255, 0, 0);
//     auto action2 = TintTo::create(0.1f, 255, 255, 255);
//     auto action3 = Sequence::create(action1, action2, action1, action2, action1, action2, NULL);
//     
// 
//     //auto action1 = Blink::create(0.5f, 4);
// 
//     m_RealSprite->runAction(action3);
//     //m_Damaged->setVisible(false);
}

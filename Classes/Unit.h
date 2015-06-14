#pragma once
#include "Enums.h"
#include "cocos2d.h"

USING_NS_CC;



class Player;

class Unit : public Sprite
{
public:
    Unit();
    virtual ~Unit();

       UnitType        GetUnitType(){ return m_UnitType; }
       Vec2            GetTargetPos(){ return m_TargetPos; }
       int             GetPlayerID(){ return m_PlayerID; }
       int             GetUnitID(){ return m_UnitID; }
       float           GetMaxHp(){ return m_MaxHp; }
       float           GetCurHp(){ return m_CurHp; }
       float           GetSpeed(){ return m_Speed; }
       float           GetAngleRadian(){ return m_AngleRadian; }
       Team            GetTeam(){ return m_Team; }

       Sprite*      GetSprite(){ return m_Sprite; }
     Sprite*         GetHpBarFrame(){ return m_HpBarFrame; }
     Sprite*         GetHpBar(){ return m_HpBar; }
     void            Move();
// 
     void            SetUnitID(int unitID){ m_UnitID = unitID; }
     void            SetHp(int curHp);
     void            SetMyHpBar();
     void            SetCurPos(Vec2 pos){ m_CurPos = pos; }
     void            SetUnitOwner(int PlayerID){ m_PlayerID = PlayerID; }
     void            SetTeam(Team team){ m_Team = team; }
     void            SetDynamicBody(const Vec2& initPos, float scale);


     void            UpdateHpBar();
     void            Damaged();
     PhysicsBody*    GetPhysicsBody(){ return m_Body; }


protected:
    UnitType        m_UnitType;
    std::string     m_Name;
    int             m_PlayerID;
    int             m_UnitID;
    float           m_MaxHp;
    float           m_CurHp;
    Vec2            m_TargetPos;
    Vec2            m_CurPos;
    float           m_Speed;
    float           m_AngleRadian;
    Team            m_Team;
    Player*         m_Owner;
    PhysicsBody*    m_Body = nullptr;
    Sprite*         m_Sprite = nullptr;

    Sprite*         m_HpBarFrame = nullptr;
    Sprite*         m_HpBar = nullptr;

protected:

    friend class ObjectManager;
};
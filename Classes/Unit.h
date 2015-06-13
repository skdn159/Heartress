#pragma once
#include "Enums.h"
#include "cocos2d.h"

USING_NS_CC;


typedef std::map<Direction, Animation*> MoveMotion;

class Unit
{
public:
    Unit();
    virtual ~Unit();
// 
//     void            SetType(int type){ m_UnitID = SET_SIDE_TYPE(m_UnitID, type); }
//     void            SetPlayerID(int playerID){ m_PlayerID = playerID; }
//     void            SetUnitID(int unitID){ m_UnitID = unitID; }
//     void            SetSpeed(float speed) { m_Speed = speed; }
//     void            SetCooltimeBonus(int bonus){ m_CooltimeBonus = bonus; }
//     void            SetTargetPos(Vec2 pos){ m_TargetPos = pos; }
//     void            SetMoveState(MoveState* moveState) { m_MoveState = moveState; }
//     void            SetUnitHiddenState(bool isHidden) { m_IsHidden = isHidden; }
// 
       UnitType        GetUnitType(){ return m_UnitType; }
       Vec2            GetTargetPos(){ return m_TargetPos; }
       int             GetPlayerID(){ return m_PlayerID; }
       int             GetUnitID(){ return m_UnitID; }
       float           GetMaxHp(){ return m_MaxHp; }
       float           GetCurHp(){ return m_CurHp; }
       float           GetSpeed(){ return m_Speed; }
       float           GetAngleRadian(){ return m_AngleRadian; }


//     virtual void    SetMoveMotionToCache() = 0;
//     virtual void    SetMoveMotionByDir() = 0;
// 
// 
     Sprite*         GetCenterSprite(){ return m_CenterSprite; }
     Sprite*         GetRealSprite(){ return m_RealSprite; }
     Sprite*         GetHpBarFrame(){ return m_HpBarFrame; }
     Sprite*         GetHpBar(){ return m_HpBar; }
// 
//     MoveState*      GetMoveState(){ return m_MoveState; }
//     MoveState*      GetStandbyState(){ return (MoveState*)m_StandbyState; }
//     MoveState*      GetMovingState(){ return (MoveState*)m_MovingState; }
//     MoveState*      GetCrashedState(){ return (MoveState*)m_CrashedState; }
// 
//     void            TryMove(){ m_MoveState->TryMove(this); }
//     void            EndMove(){ m_MoveState->EndMove(this); }
//     void            Crashed(){ m_MoveState->Crashed(this); }
//     void            EndCrash(){ m_MoveState->EndCrash(this); }
//     void            Movement(){ m_MoveState->Movement(this); }
// 
     void            Move();
//     void            Crash();
// 
//     void            InitCenterSprite();
//     void            InitRealSprite();
//     void            SetAllSpriteVisible();
     void            SetHp(int curHp);
     void            SetMyHpBar();
//     void            SetEnemyHpBar();
//     void            SetTeamHpBar();
//     void            SetUnitHpBar();
     void            UpdateHpBar();
// protected:
//     void            SetHeroHpBar(const char* barImage);
     void            Damaged();
//     RepeatForever*  MakeUnitAnimation(const char* format, int size);
//     Animate*        MakeUnitAnimationOnce(const char* format, int size);
// 
//     Direction       CalcMoveDirection(Vec2 displacement);
//     Direction       CalcSkillDirection(Vec2 displacement);

protected:
    UnitType        m_UnitType;
    std::string     m_Name;
    int             m_PlayerID;
    int             m_UnitID;
    float           m_MaxHp;
    float           m_CurHp;
    Vec2            m_TargetPos;
    float           m_Speed;
    float           m_AngleRadian;

protected:
    MoveMotion      m_MoveMotionByDir;
    Sprite*         m_CenterSprite = nullptr; // 투명 스프라이트
    Sprite*         m_RealSprite = nullptr;
    Sprite*         m_HpBarFrame = nullptr;
    Sprite*         m_HpBar = nullptr;

protected:

    friend class ObjectManager;
};
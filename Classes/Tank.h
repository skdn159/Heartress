#pragma once
#include "Unit.h"
#include "Enums.h"
class Tank :	public Unit
{
public:
    Tank(Player* owner, Vec2 createPos, int unitId, Team team);
    virtual ~Tank();

public:
//     void MissileCast(const char* image, const char* soundEffect, float speed, Vec2 createPos, Vec2 targetPos);
//     void MissileCrash();
//     void MissileDelete();
// 
//     virtual void    SetMoveMotionToCache();
//     virtual void    SetMoveMotionByDir();
    void MissileCast();
    bool GetCanMove(){ return m_CanMove; }
    void SetCanMove(bool canMove){ m_CanMove = canMove; }
    void SetLookingDir(Direction dir){ m_LookingDir = dir; }
    Direction GetLookingDir(){ return m_LookingDir; }

    void DoAction(TankAction action,bool pressed);

    void ShotGuageUp();
    void ShotMissile();
    void Calstatus(Direction dir);
    void DegreeAdj(Direction dir);
    void MoveL();
    void MoveR();
    Vec2 GenerateMissileInitPos();


protected:

private:
    Direction   m_LookingDir;
    bool         m_CanMove;
    float       m_Speed;
    Vec2        m_AimDegree;
    float       m_DegreeAdj;
    float       m_Guage;

};


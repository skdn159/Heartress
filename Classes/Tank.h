#pragma once
#include "Unit.h"
#include "Enums.h"
class Tank :	public Unit
{
public:
    Tank(Vec2 createPos, int unitId);
    virtual ~Tank();

public:
//     void MissileCast(const char* image, const char* soundEffect, float speed, Vec2 createPos, Vec2 targetPos);
//     void MissileCrash();
//     void MissileDelete();
// 
//     virtual void    SetMoveMotionToCache();
//     virtual void    SetMoveMotionByDir();

    void SetLookingDir(Direction dir){ m_LookingDir = dir; }
    Direction GetLookingDir(){ return m_LookingDir; }

    void Shot();
    void Move();

protected:
    //ParticleSystemQuad* m_Particle = nullptr;

private:
    Direction   m_LookingDir;

};


#pragma once
#include "Unit.h"
#include "Enums.h"
class Tank :	public Unit
{
public:
    Tank(int unitId);
    virtual ~Tank();

public:
//     void MissileCast(const char* image, const char* soundEffect, float speed, Vec2 createPos, Vec2 targetPos);
//     void MissileCrash();
//     void MissileDelete();
// 
//     virtual void    SetMoveMotionToCache();
//     virtual void    SetMoveMotionByDir();

protected:
    //ParticleSystemQuad* m_Particle = nullptr;

private:
    Direction   m_LookingDir;
};


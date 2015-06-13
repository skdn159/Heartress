#pragma once
#include "Unit.h"

class Missile : public Unit
{
public:
    Missile(int unitId);
    virtual ~Missile();

public:
    void MissileCast(const char* image, const char* soundEffect, float speed, Vec2 createPos, Vec2 targetPos);
    void MissileCrash();
    void MissileDelete();
    // 
    //     virtual void    SetMoveMotionToCache();
    //     virtual void    SetMoveMotionByDir();

    MissileType GetMissileType(){ return m_MissileType; }
    float GetMissileDamage(){ return m_Damage; }

    void SetMissileDamage(float missileDamage){ m_Damage = missileDamage; }
    void SetMissileType(MissileType missileType){ m_MissileType = missileType; }

protected:
    ParticleSystemQuad* m_Particle = nullptr;

private:
    float       m_Damage;
    MissileType m_MissileType;
};

#include "cocos2d.h"
#include "Tank.h"
#include "GameManager.h"
#include "ObjectLayer.h"
#include "SimpleAudioEngine.h"
#include "Missile.h"
#include "Enums.h"

using namespace CocosDenshion;                     
//#define GET_OBJ_LAYER	dynamic_cast<ObjectLayer*>(this->getParent()->getParent()->getChildByName("UILayer"))


Tank::Tank(Player* owner,Vec2 createPos, int unitId,Team team)
{
    m_UnitType = UNIT_TANK;
    m_UnitID = unitId;
    m_Team = team;
    m_CanMove = false;
    m_Speed = 100.0f;
    m_Owner = owner;
    m_DegreeAdj = 5.0f;
    m_AimDegree = { 20.0f, 20.0f };
    m_Guage = 0.0f;
    m_Sprite = Sprite::create("Images/Tank.png");
    auto material = PhysicsMaterial(0.0f, 0.0f, 5.0f);

    m_Body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height), material);
    m_Body->setRotationEnable(false);

    m_Sprite->setPhysicsBody(m_Body);
    m_Sprite->setPosition(createPos);

}


Tank::~Tank()
{
}



void Tank::DegreeAdj(Direction dir)
{
    switch (dir)
    {
    case E:
        break;
    case W:
        break;
    case N:
        m_AimDegree.x += m_DegreeAdj;
        break;
    case S:
        m_AimDegree.x -= m_DegreeAdj;
        break;
    default:
        break;
    }

}

void Tank::MoveL()
{
    m_Body->applyImpulse(Vec2(-m_Speed, 0));
    

}

void Tank::MoveR()
{
    m_Body->applyImpulse(Vec2(+m_Speed, 0));

}
void Tank::Stop()
{
    m_Body->applyImpulse(Vec2(0.0f, 0.0f));
}




void Tank::Calstatus(Direction dir)
{
    switch (dir)
    {
    case E:
        MoveR();
        break;
    case W:
        MoveL();
        break;
    case N:
        break;
    case S:
        break;
    default:
        break;
    }

}

void Tank::DoAction(TankAction action, bool pressed)
{
    if (m_Owner->GetIsMyTrun() == true){
        switch (action)
        {
        case MOVE_LEFT:
            Calstatus(W);
            break;
        case MOVE_RIGHT:
            Calstatus(E);
            break;
        case SHOT:
            switch (pressed)
            {
            case  true:
                ShotGuageUp();
                break;

            case  false:
                ShotMissile();
                break;
            }
            
            ShotGuageUp();
            break;

        case DEGREE_UP:
            DegreeAdj(N);
            break;
        case DEGREE_DOWN:
            DegreeAdj(S);
            break;
        case ACTION_NONE:
            break;
        default:
            break;
        }
    }
}

void Tank::MissileCast()
{
    auto missileInitPos = GenerateMissileInitPos();
    Missile* missile = new Missile(m_Owner, missileInitPos, 5, m_Team);
    GET_OBJECT_LAYER->AddMissile(missile);
    auto normal = m_AimDegree.getNormalized();

    missile->GetPhysicsBody()->applyImpulse(Vec2( normal.x*m_Guage, normal.y*m_Guage));

    //player가 턴 넘기게
    
}

void Tank::ShotMissile()
{
    MissileCast();
    m_Guage = 0.0;
}

void Tank::ShotGuageUp()
{
    m_Guage += 10.0f;
}

Vec2 Tank::GenerateMissileInitPos()
{
    auto curPos = m_Body->getPosition();
    Vec2 normal = m_AimDegree.getNormalized();
    auto a = m_Sprite->getContentSize().height;

    auto missilePos = curPos + normal*a;
    return missilePos;
}


#include "cocos2d.h"
#include "Player.h"
#include "Tank.h"
#include "Unit.h"
#include "GameManager.h"

Player::Player(int playerID, Team team)
{
    m_PlayerID = playerID;
    m_Team = team;
    m_IsMyTurn = false;

    
}


Player::~Player()
{
}

void Player::ReceiveChance(int receivedPlayerID)
{
    if (receivedPlayerID = !m_PlayerID){
        return;
    }

    
    if (m_IsMyTurn == true)
    {
        m_Tank->SetCanMove(true);
        
        //탱그이동 => 매순간 is My Turn인지 인지해야함

        //inputMangager 값 읽어서 파워게이지
        // 공경
    }

}

void Player::MakeTank(int unitID, Vec2 initPos)
{
    
    auto tank = new Tank(this, initPos, unitID, m_Team);
    //tank->SetDynamicBody(initPos, 1.0f);

    m_Tank = tank;
    m_UnitList[unitID] = tank;
}

void Player::FinishTurn()
{
    m_IsMyTurn = false;
   // m_Tank->SetCanMove(false);
    GGameManager->ChangeTurn(m_PlayerID);
}

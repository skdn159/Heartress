#include "cocos2d.h"
#include "Player.h"
#include "Tank.h"

Player::Player(int playerID)
{
    m_PlayerID = playerID;


}


Player::~Player()
{
}

void Player::ReceiveChance(int receivedPlayerID)
{
    if (receivedPlayerID = !m_PlayerID){
        return;
    }

    //탱그이동

    //inputMangager 값 읽어서 파워게이지
    // 공경


}

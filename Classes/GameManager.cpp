#include "cocos2d.h"
#include "GameManager.h"
#include "ObjectLayer.h"
#include "Player.h"
#include "Tank.h"
#include "ContactListener.h"

GameManager* GGameManager = nullptr;


GameManager::GameManager()
{
    m_IM = std::make_shared<InputManager>();
    InitPhysicsWorld();

    //하드코딩 
    m_Player1 = new Player(1);
    m_Player2 = new Player(2);

    m_WhoseTurn = m_Player1->GetPlayerID();
    GiveTurn(m_WhoseTurn);
}

int GameManager::ChangeTurn(int finishedPlayerID)
{
    //int nextTurnPlayerID;

    if (finishedPlayerID == 1)
    {
        return 2;
    }

    else
    {
        return 1;
    }



    //return nextTurnPlayerID;
}

void GameManager::SetTwoPlayer()
{
    


}

void GameManager::GiveTurn(int playerID)
{
    //player sprite에 화살표 주기 주기


}

void GameManager::InitPhysicsWorld()
{
    b2Vec2 gravity(0.0f, -10.0f);
    m_World = new b2World(gravity);

    m_World->SetAllowSleeping(true);
    m_World->SetContinuousPhysics(true);

    m_Contact = new ContactListener();
    m_World->SetContactListener((b2ContactListener*)m_Contact);
}

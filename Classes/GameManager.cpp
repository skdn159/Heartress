#include "cocos2d.h"
#include "GameManager.h"
#include "ObjectLayer.h"
#include "Player.h"
#include "Tank.h"
#include "ContactListener.h"
#include "Enums.h"

GameManager* GGameManager = nullptr;


GameManager::GameManager()
{
    m_IM = std::make_shared<InputManager>();
    InitPhysicsWorld();
    //SetTwoPlayer();
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
    //하드코딩 
    m_PlayerList[1] = new Player(1, TEAM_A);
    m_PlayerList[2] = new Player(2, TEAM_B);


    m_Player1 = m_PlayerList[1];
    m_Player2 = m_PlayerList[2];

    auto objlayer = GET_OBJECT_LAYER;

    auto firstP = m_PlayerList.find(1);
    firstP->second->MakeTank(1, Vec2(500.0f, 100.0f));
    objlayer->AddTank(firstP->second->GetTank());


    auto secondP = m_PlayerList.find(2);
    secondP->second->MakeTank(2, Vec2(100.0f, 100.0f));
    objlayer->AddTank(secondP->second->GetTank());

    m_WhoseTurn = firstP->second->GetPlayerID();
    GiveTurn(m_WhoseTurn);
}

void GameManager::GiveTurn(int playerID)
{
    //player sprite에 화살표 주기 주기
    auto nowTurnPlayer = m_PlayerList.find(playerID);
    nowTurnPlayer->second->SetMyTurn(true);
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

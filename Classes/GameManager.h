#pragma once
#include "InputManager.h"
#include "ObjectLayer.h"
#include "Player.h"
#include <map>
#include "Box2D.h"
#include "ContactListener.h"

USING_NS_CC;

#define GET_GM GameManager::getInstance()
#define GET_IM GameManager::getInstance().getInputManager()

class GameManager
{
public:
    GameManager();
    static GameManager& getInstance()
    {
        static GameManager instance;
        return instance;
    }
    std::shared_ptr<InputManager>	getInputManager(){ return m_IM; }

    int ChangeTurn(int finishedPlayerID);
    //하드 코딩
    void SetTwoPlayer();
    void GiveTurn(int playerID);


private:
    b2World*    GetWorld(){ return m_World; }
    void        InitPhysicsWorld();
    ContactListener*    GetContact(){ return m_Contact; }


private:
    std::shared_ptr<InputManager>   m_IM = nullptr;
    b2World*              m_World = nullptr;
    ContactListener*    m_Contact = nullptr;


    int m_WhoseTurn = 0;
    std::map<int, Player*> m_PlayerList;
    //std::vector<int>m_PlayerList;


    //하드 코딩
    Player* m_Player1;
    Player* m_Player2;

    

};

extern GameManager* GGameManager;
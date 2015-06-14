#pragma once
#include "Enums.h"
#include <map>
#include "Unit.h"

class Player
{
public:
    Player(int playerID);
    ~Player();
    
    void SetPlayerID(int playerID){ m_PlayerID = playerID; }
    int GetPlayerID(){ return m_PlayerID; }
    
    void SetTeam(Team team){ m_Team = team; }
    Team GetPlayerTeam(){ return m_Team; }

    void SetMyTurn(bool myturn){ m_IsMyTurn = myturn; }
    bool GetIsMyTrun(){ return m_IsMyTurn; }

    void ReceiveChance(int receivedPlayerID);

public:
    bool m_IsMyTurn;
    Team m_Team;
    int m_PlayerID;

    std::map<int, Unit*> m_UnitList;

};


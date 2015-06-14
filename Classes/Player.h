#pragma once
#include "Enums.h"
#include <map>
#include "Unit.h"
#include "Tank.h"

typedef std::map<int, Unit*> UnitList;

class Player
{
public:
    Player(int playerID, Team team);
    ~Player();
    
    void SetPlayerID(int playerID){ m_PlayerID = playerID; }
    int GetPlayerID(){ return m_PlayerID; }
    
    void SetTeam(Team team){ m_Team = team; }
    Team GetPlayerTeam(){ return m_Team; }

    void SetMyTurn(bool myturn){ m_IsMyTurn = myturn; }
    bool GetIsMyTrun(){ return m_IsMyTurn; }

    void ReceiveChance(int receivedPlayerID);
    void MakeTank(int unitID, Vec2 initPos);
    UnitList GetUnitList(){ return m_UnitList; }

    Tank* GetTank(){ return m_Tank; }
    void FinishTurn();

public:
    bool m_IsMyTurn;
    Team m_Team;
    int m_PlayerID;

    Tank* m_Tank;
    UnitList m_UnitList;

};


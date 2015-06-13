#pragma once
#include "Enums.h"

class Player
{
public:
    Player();
    ~Player();

    void SetMyTurn(bool myturn){ m_IsMyTurn = myturn; }
    bool GetIsMyTrun(){ return m_IsMyTurn; }


public:
    bool m_IsMyTurn;
    Team m_Team;
    int m_PlayerID;

};


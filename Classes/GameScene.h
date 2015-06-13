#pragma once
#include "Enums.h"
#include "cocos2d.h"

USING_NS_CC;

class GameScene : public Layer
{
public:

    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);

    void        StartGame();
    void        GameOver(int playerId, bool isWin);

private:
    //bool	    m_IsStartGame;
    
};

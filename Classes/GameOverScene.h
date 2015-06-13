#pragma once
#include "Enums.h"
#include "cocos2d.h"

USING_NS_CC;

class GameOverScene : public LayerColor
{
public:
    static Scene* createScene(int playerId);
	virtual bool init();
	CREATE_FUNC(GameOverScene);

	//void menuCallback1(Ref* sender);
	void menuCallback2(Ref* sender);

private:
};

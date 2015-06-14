#pragma once
#include "Enums.h"
#include "cocos2d.h"

USING_NS_CC;

class UILayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(UILayer);

//    void    ClickExit(Ref* sender);
    void    UpdateHpBar(float curHp, float maxHp);
    void    ClickStart(Ref* sender); 
    //Sprite* GetCurrentCursor() { return m_Cursor; }
    //Sprite* GetCooltimeBox(SkillKey key);

private:
//     Sprite*                         m_Cursor;
//     std::map<CursorMode, Sprite*>   m_CursorShape;
   // std::map<SkillKey, Sprite*>     m_CooltimeBox;
};


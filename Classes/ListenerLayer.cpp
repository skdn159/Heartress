#include "ListenerLayer.h"
#include "MapLayer.h"
#include "ObjectLayer.h"
#include "GameManager.h"
#include "InputManager.h"
#include "GameScene.h"
#include "UILayer.h"
#include "math.h"
#include "Tank.h"
#include "Unit.h"
//#include "Macros.h"

#define GET_OBJECT_LAYER    dynamic_cast<ObjectLayer*>(this->getChildByName("ObjectLayer"))
#define GET_UI_LAYER        dynamic_cast<UILayer*>(this->getParent()->getChildByName("UILayer"))
//#define GET_ESC_LAYER       dynamic_cast<EscLayer*>(this->getParent()->getChildByName("EscLayer"))

bool ListenerLayer::init()
{
    
    if (!Layer::init())
    {
        return false;
    }
    //this->setPosition(-(MAX_MAP_SIZE_X - DISPLAY_X)/2, -(MAX_MAP_SIZE_Y - DISPLAY_Y)/2);

    auto layer2 = ObjectLayer::create();
    this->addChild(layer2, 1, "ObjectLayer");
    auto layer1 = MapLayer::create();
    this->addChild(layer1, 0, "MapLayer");

  //  m_Targeting = false;

//     auto MouseListener = EventListenerMouse::create();
//     MouseListener->onMouseDown = CC_CALLBACK_1(ListenerLayer::OnMouseDown, this);
//     MouseListener->onMouseUp = CC_CALLBACK_1(ListenerLayer::OnMouseUp, this);
//     MouseListener->onMouseMove = CC_CALLBACK_1(ListenerLayer::OnMouseMove, this);
//     _eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener, this);

    auto K_listener = EventListenerKeyboard::create();
    K_listener->onKeyPressed = CC_CALLBACK_2(ListenerLayer::OnKeyPressed, this);
    K_listener->onKeyReleased = CC_CALLBACK_2(ListenerLayer::OnKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(K_listener, this);

    m_PowerGuage = 0.0f;
    m_IsguageOn = false;

	this->schedule(schedule_selector(ListenerLayer::Tick),0.1f);
	layer2->schedule(schedule_selector(ObjectLayer::Tick));
    return true;
}

//////////////////////////////////////////////////////////////////////////
void ListenerLayer::Tick(float dt)
{
    CheckGuage();

    

}
//////////////////////////////////////////////////////////////////////////


// void ListenerLayer::ScreenMove()
// {
// //     if (GET_IM->GetMouseScrollStatus(SCROLL_UP) && this->getPositionY() < MAX_MAP_SIZE_Y / 8 - (MAX_MAP_SIZE_Y - DISPLAY_Y) / 2)
// //     {
// //         this->setPositionY(this->getPositionY() + 20);
// //     }
// //     if (GET_IM->GetMouseScrollStatus(SCROLL_DOWN) && this->getPositionY() > -MAX_MAP_SIZE_Y / 8 - (MAX_MAP_SIZE_Y - DISPLAY_Y) / 2)
// //     {
// //         this->setPositionY(this->getPositionY() - 20);
// //     }
// //     if (GET_IM->GetMouseScrollStatus(SCROLL_LEFT) && this->getPositionX() < MAX_MAP_SIZE_X / 8 - (MAX_MAP_SIZE_X - DISPLAY_X) / 2)
// //     {
// //         this->setPositionX(this->getPositionX() + 20);
// //     }
// //     if (GET_IM->GetMouseScrollStatus(SCROLL_RIGHT) && this->getPositionX() > -MAX_MAP_SIZE_X / 8 - (MAX_MAP_SIZE_X - DISPLAY_X) / 2)
// //     {
// //         this->setPositionX(this->getPositionX() - 20);
// //     }
// }
void ListenerLayer::CheckGuage()
{
    if (m_IsguageOn==true)
    {
        m_PowerGuage+=120.0f;

    }

}


///////////////////////////////////////////////////////////////////////////
/*
    마우스 리스너
*/
///////////////////////////////////////////////////////////////////////////
// void ListenerLayer::OnMouseDown(Event *event)
// {
//     if (!dynamic_cast<GameScene*>(this->getParent())->IsStartGame())
//     {
//         return;
//     }
//     auto hero = GET_OBJECT_LAYER->GetMyHero();
//     if (hero == nullptr)
//     {
//         return;
//     }
//     auto sprite = hero->GetCenterSprite();				_ASSERT(sprite != nullptr);
//     auto heroPos = sprite->getPosition();
//     auto mousePos = GET_IM->GetMouseLocation();
//     auto key = KeyboardToSkillKey(GET_IM->SearchTargetingKey());
//     auto button = static_cast<EventMouse*>(event)->getMouseButton();
//     GET_IM->SetMouseStatus(button, true);
// 
//     switch (button)
//     {
//     case MOUSE_BUTTON_LEFT:
//         {
//             if (!m_Targeting || key == SKILL_NONE)
//             {
//                 break;
//             }
// 			TcpClient::getInstance()->skillRequest(heroPos, mousePos - this->getPosition(), key);
//             CoolTimeStart(key);
// 
//             hero->SkillEnd(key);
//             GET_UI_LAYER->CursorChange(CURSOR_DEFAULT);
//             GET_UI_LAYER->GetCurrentCursor()->setPosition(mousePos);
//             GET_IM->InitTargetingKey();
//             m_Targeting = false;
//         }
//         break;
// 
//     case MOUSE_BUTTON_RIGHT:
//         {
//             if (hero->GetMoveState() != hero->GetCrashedState())
//             {
//                 if (hero->GetHeroType()==HERO_LAPHINX)
//                 {
//                     if (hero->GetHeroPerforming() == false)
//                     {
//                         TcpClient::getInstance()->moveRequest(heroPos, mousePos - this->getPosition());
//                     }
//                 }
//                 else
//                 {
//     				TcpClient::getInstance()->moveRequest(heroPos, mousePos - this->getPosition());
//                 }
//             }
//             if (key != SKILL_NONE)
//             {
//                 hero->SkillEnd(key);
//                 GET_UI_LAYER->CursorChange(CURSOR_DEFAULT);
//                 GET_UI_LAYER->GetCurrentCursor()->setPosition(mousePos);
//                 GET_IM->InitTargetingKey();
//                 m_Targeting = false;
//             }
//         }
//         break;
//     }
// }
// 
// void ListenerLayer::OnMouseUp(Event *event)
// {
//     auto button = static_cast<EventMouse*>(event)->getMouseButton();
//     GET_IM->SetMouseStatus(button, false);
// }
// 
// void ListenerLayer::OnMouseMove(Event *event)
// {
//     auto location = static_cast<EventMouse*>(event)->getLocation();
//     location.y = Director::getInstance()->getWinSize().height - location.y;
// 
//     GET_IM->SetMouseLocation(location);
//     GET_IM->CheckMouseScroll();
//     GET_UI_LAYER->GetCurrentCursor()->setPosition(location);
//     SetArrowPos();
//     SetNearRangePos();
// }



///////////////////////////////////////////////////////////////////////////
/*
    키보드 리스너
*/
///////////////////////////////////////////////////////////////////////////
void ListenerLayer::OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    GET_IM->SetKeyStatus(keyCode, true);
    
    auto missileKey = KeyboardToMissileType(keyCode);
    auto actionKey = KeyboardToAction(keyCode);

    if (actionKey == SHOT)
    {
        m_IsguageOn = true;
    }

    auto Tank1P = GGameManager->Get1Player()->GetTank();
    auto Tank2P = GGameManager->Get2Player()->GetTank();


    ///분화 해야하지만 그냥 감 Enum Action을 1p 2p 따로...


    Tank1P->DoAction(actionKey,true);
    Tank2P->DoAction(actionKey,true);

}

void ListenerLayer::OnKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    GET_IM->SetKeyStatus(keyCode, false);
    auto powerKey = KeyboardToAction(keyCode);

    auto Tank1P = GGameManager->Get1Player()->GetTank();
    auto Tank2P = GGameManager->Get2Player()->GetTank();

     Tank1P->SetGuage(m_PowerGuage);
    Tank2P->SetGuage(m_PowerGuage);

    Tank1P->DoAction(powerKey, false);
    Tank2P->DoAction(powerKey, false);

    m_IsguageOn = false;
    m_PowerGuage = 0.0f;
    
}

MissileType ListenerLayer::KeyboardToMissileType(EventKeyboard::KeyCode keyCode)
{
    switch (keyCode)
    {

    case KEY_1:  return DIRT_DESTROYER;
    case KEY_8:  return DIRT_DESTROYER;
    case KEY_2:  return TANK_DESTROYER;
    case KEY_9:  return TANK_DESTROYER;
    case KEY_3:  return DIRT_MAKER;
    case KEY_0:  return DIRT_MAKER;



    default:     return MISSILE_NONE;
    }
}

TankAction ListenerLayer::KeyboardToAction(EventKeyboard::KeyCode keyCode)
{
    //todo P1, P2 다뤄야함
    switch (keyCode)
    {
    case KEY_W: return DEGREE_UP;
    case KEY_S: return DEGREE_DOWN;
    case KEY_A: return MOVE_LEFT;
    case KEY_D: return MOVE_RIGHT;
    case KEY_TAB: return SHOT;

    case KEY_UP_ARROW:   return DEGREE_UP;
    case KEY_DOWN_ARROW:  return DEGREE_DOWN;
    case KEY_LEFT_ARROW:  return MOVE_LEFT;
    case KEY_RIGHT_ARROW: return MOVE_RIGHT;
    case  KEY_SPACE: return SHOT;

    default: return ACTION_NONE;
    }
}

float ListenerLayer::CalGuage()
{
    return m_PowerGuage;
}





///////////////////////////////////////////////////////////////////////////
/*
    private 함수들
*/
///////////////////////////////////////////////////////////////////////////


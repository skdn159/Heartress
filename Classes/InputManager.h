#pragma once
#include "ListenerLayer.h"
#include "cocos2d.h"

USING_NS_CC;

#define KEY_ENTER           EventKeyboard::KeyCode::KEY_ENTER
#define KEY_ESC             EventKeyboard::KeyCode::KEY_ESCAPE

#define KEY_UP_ARROW        EventKeyboard::KeyCode::KEY_UP_ARROW
#define KEY_DOWN_ARROW      EventKeyboard::KeyCode::KEY_DOWN_ARROW
#define KEY_LEFT_ARROW      EventKeyboard::KeyCode::KEY_LEFT_ARROW
#define KEY_RIGHT_ARROW     EventKeyboard::KeyCode::KEY_RIGHT_ARROW

#define KEY_W               EventKeyboard::KeyCode::KEY_W
#define KEY_S               EventKeyboard::KeyCode::KEY_S
#define KEY_A               EventKeyboard::KeyCode::KEY_A
#define KEY_D               EventKeyboard::KeyCode::KEY_D

#define KEY_1               EventKeyboard::KeyCode::KEY_1
#define KEY_2               EventKeyboard::KeyCode::KEY_2
#define KEY_3               EventKeyboard::KeyCode::KEY_3

#define KEY_8               EventKeyboard::KeyCode::KEY_8
#define KEY_9               EventKeyboard::KeyCode::KEY_9
#define KEY_0               EventKeyboard::KeyCode::KEY_0

#define KEY_SPACE           EventKeyboard::KeyCode::KEY_SPACE
#define KEY_TAB             EventKeyboard::KeyCode::KEY_TAB

enum ScrollDir
{
    SCROLL_UP,
    SCROLL_DOWN,
    SCROLL_LEFT,
    SCROLL_RIGHT,
};

class InputManager
{
public:
    InputManager();

    Vec2	GetMouseLocation()                                      { return m_MouseLocation; }
    bool	GetMouseStatus(int button)                              { return m_MouseStatus[button]; }
    bool    GetMouseScrollStatus(ScrollDir dir)                     { return m_MouseScrollStatus[dir]; }
    bool	GetKeyStatus(EventKeyboard::KeyCode key)                { return m_KeyStatus[key]; }
    bool	GetTargeting(EventKeyboard::KeyCode key)                { return m_Targeting[key]; }

    void	SetMouseLocation(Vec2 p)                                { m_MouseLocation = p; }
    void	SetMouseStatus(int button, bool status)                 { m_MouseStatus[button] = status; }
    void	SetMouseScrollStatus(ScrollDir dir, bool status)        { m_MouseScrollStatus[dir] = status; }
    void	SetKeyStatus(EventKeyboard::KeyCode key, bool status)   { m_KeyStatus[key] = status; }
    void	SetTargeting(EventKeyboard::KeyCode key, bool status)   { m_Targeting[key] = status; }

    void                    CheckMouseScroll();
    void                    InitTargetingKey();
    EventKeyboard::KeyCode  SearchTargetingKey();

private:
    Vec2                                    m_MouseLocation;
    std::map<int, bool>                     m_MouseStatus;
    std::map<ScrollDir, bool>               m_MouseScrollStatus;
    std::map<EventKeyboard::KeyCode, bool>  m_KeyStatus;
    std::map<EventKeyboard::KeyCode, bool>  m_Targeting;
};
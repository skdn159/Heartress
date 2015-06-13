#include "cocos2d.h"
#include "GameManager.h"

GameManager::GameManager()
{
    m_IM = std::make_shared<InputManager>();
}

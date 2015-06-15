#include "cocos2d.h"
#include "MapLayer.h"
#include "GameManager.h"

bool MapLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
     auto sprite = Sprite::create("Images/sky.png");
     sprite->setScale(1.4f);
     sprite->setPosition(this->getAnchorPointInPoints());
     this->addChild(sprite);

     auto visibleSize = Director::getInstance()->getVisibleSize();

     m_EdgeBox = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
     auto node = cocos2d::Node::create();
     
     node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
     node->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2+30.0f ));
     node->setPhysicsBody(m_EdgeBox);
     
     
     this->addChild(node);

     return true;
}

void MapLayer::MakeObject(int id, Vec2 pos)
{
    //id로 타입 구별 먼저 해줘야 함

//     auto rock = Sprite::create("Images/rock.png");
//     rock->setPosition(pos);
//     this->addChild(rock);
// 
//     return;
}

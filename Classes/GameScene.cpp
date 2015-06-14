#include "GameScene.h"
#include "ObjectLayer.h"
#include "ListenerLayer.h"
#include "GameManager.h"
#include "UILayer.h"
#include "windows.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

Scene* GameScene::createScene()
{

    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vect(0.0f, -1000.0f));

    auto layer1 = GameScene::create();
    auto layer2 = ListenerLayer::create();
    scene->addChild(layer1, 3, "GameScene");
    layer1->addChild(layer2, 0, "ListenerLayer");

    return scene;
}


bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    GGameManager = new GameManager();


//     m_IsStartGame = false;
// 
//     auto layer1 = LoadingBGLayer::create();
     auto layer2 = UILayer::create();
//     auto layer3 = EscLayer::create();
//     this->addChild(layer1, 10, "LoadingBGLayer");
     this->addChild(layer2, 5, "UILayer");
//     this->addChild(layer3, 20, "EscLayer");
//     layer3->setVisible(false);
     
//     SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/Background/game2.mp3", true);
//     SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.00001f);

    return true;
}

void GameScene::StartGame()
{

}


void GameScene::GameOver(int playerId, bool isWin)
{
    //m_IsStartGame = false;
    //SimpleAudioEngine::getInstance()->stopBackgroundMusic();

 //   auto scene = GameOverScene::createScene(m_RoomInfo, playerId, isWin);
 //   Director::getInstance()->popScene();
 //   Director::getInstance()->pushScene(scene);
}

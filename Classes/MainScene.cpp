#include "cocos2d.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

using namespace CocosDenshion;

#define MAX_NAME_LEN 14
#define GET_CONNECT_LABEL dynamic_cast<Label*>(this->getChildByName("ConnectLabel"))

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer, 0, "MainScene");
    //SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/Background/mainscene.mp3");
    return scene;
}

bool MainScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto winSize = Director::getInstance()->getWinSize();


    auto label1 = Label::createWithSystemFont("Game Play", "Thonburi", 50);
    auto label2 = Label::createWithSystemFont("Exit", "Thonburi", 50);

    auto menuItem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MainScene::menuCallback1, this));
    auto menuItem2 = MenuItemLabel::create(label2, CC_CALLBACK_1(MainScene::menuCallback2, this));

    auto menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->alignItemsVertically();
    this->addChild(menu, 0, "MainMenu");



//     // 배경화면 plist 보여주는 부분
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_01.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_02.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_03.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_04.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_05.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_06.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_07.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_08.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_09.plist");
//     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images/Background/MainBackground_10.plist");

//     auto background1 = Sprite::createWithSpriteFrameName("MainBackground_001.png");
//     auto background2 = Sprite::create("Images/Background/MainBackground2.png");
//     auto title = Sprite::create("Images/Background/SkimaTitle.png");
//     auto animation = Animation::create();
//     animation->setDelayPerUnit(0.2f);
// 
//     for (int i = 1; i <= 196; ++i)
//     {
//         auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("MainBackground_%003d.png", i));
//         animation->addSpriteFrame(frame);
//     }
//     background1->runAction(RepeatForever::create(Animate::create(animation)));
//     background1->setScaleX(3.60f);
//     background1->setScaleY(3.0f);
//     background1->setAnchorPoint(Vec2::ZERO);
//     background2->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
//     background2->setOpacity(50);
//     title->setPosition(Vec2(winSize.width / 2, winSize.height * 3 / 4));
//     title->setScale(1.30f);
//     this->addChild(background1);
//     this->addChild(background2);
//     this->addChild(title);
// 
//     //serverIP 입력 창
//     auto servIPBox = Sprite::create("Images/Interface/ServerBox.png");
//     servIPBox->setPosition(winSize.width / 2, winSize.height / 3 + 100.0f);
//     servIPBox->setScaleY(0.7f);
//     auto IPInputButtonImage = MenuItemImage::create("Images/Interface/IPInputButton.png", "Images/Interface/IPInputButton_selected.png", CC_CALLBACK_1(MainScene::servIpCallback, this));
//     auto IPInputMenu = Menu::create(IPInputButtonImage, NULL);
//     IPInputMenu->setPosition(Vec2(480.0f, 85.0f));
//     IPInputMenu->alignItemsVertically(); 
//     this->addChild(servIPBox);
//     servIPBox->addChild(IPInputMenu);
// 
//     m_ServIPBox = InputBox::create("서버주소 입력", "Thonburi", MAX_NAME_LEN);
//     m_ServIPBox->beginInput();
//     m_ServIPBox->setFontSize(25.0f);
//     m_ServIPBox->setColor(Color3B::BLACK);
//     m_ServIPBox->setPosition(Vec2(winSize.width / 2 - 10, winSize.height / 2 - 72.0f));
//     this->addChild(m_ServIPBox);
// 
// 
//     // Login창 띄우기
//     auto loginScene = Sprite::create("Images/Interface/LoginScene.png");
//     loginScene->setPosition(Vec2(winSize.width / 2, winSize.height / 4));
//     loginScene->setScaleY(0.7f);
//     auto loginButtonImage = MenuItemImage::create("Images/Interface/LoginButton.png", "Images/Interface/LoginButton_selected.png", CC_CALLBACK_1(MainScene::menuCallback1, this));
//     auto loginMenu = Menu::create(loginButtonImage, NULL);
//     loginMenu->setPosition(Vec2(470.0f, 80.0f));
//     loginMenu->alignItemsVertically();
//     this->addChild(loginScene);
//     loginScene->addChild(loginMenu);
//     
//     // Login입력 받는 box 구현
//     m_LoginBox = InputBox::create("이름을 입력", "Thonburi", MAX_NAME_LEN);
//     //m_LoginBox->beginInput();
//     m_LoginBox->setFontSize(25.0f);
//     m_LoginBox->setColor(Color3B::BLACK);
//     m_LoginBox->setPosition(Vec2(winSize.width / 2 - 10, winSize.height / 3-87.0f));
//     this->addChild(m_LoginBox);
// 
//     SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/Background/mainscene.mp3", true);
//     SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0f);

    return true;
}

void MainScene::menuCallback1(Ref* sender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->pushScene(scene);
}
void MainScene::menuCallback2(Ref* sender)
{
    Director::getInstance()->end();
}


#include "LoadScene.h"



Scene* LoadScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LoadScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LoadScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto layer = LayerColor::create(Color4B(255, 255, 255, 255), visibleSize.width, visibleSize.height);
    this->addChild(layer, 0);
    auto sprite = Sprite::create("logo.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 1);
    this->runAction(Sequence::create(
        DelayTime::create(1.5f),
        CallFuncN::create(CC_CALLBACK_0(LoadScene::loadGameScene,this)),nullptr));
    
    return true;
}

void LoadScene::loadGameScene()
{
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, Mentalism::createScene()));
}

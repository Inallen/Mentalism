#include "MentalismScene.h"


Scene* Mentalism::createScene()
{
	auto scene = Scene::create();
	auto layer = Mentalism::create();
	scene->addChild(layer);
	return scene;
}

bool Mentalism::init()
{
	if(!Layer::init()) 
	{
		return false;
	}
	initData();
	initLight();
	return true;
}

void Mentalism::initData() {
	_size = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();
	_hasTouched = false;
	_time = 0.0f;
	scheduleUpdate();
	auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Mentalism::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(Mentalism::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Mentalism::initLight() {
	for(int i = 0; i < SIZE; i++) {
		_currentLight[i] = 0;
		_lightSprite[i] = Sprite::create("light.png");
		_lightSprite[i]->setVisible(false);
		this->addChild(_lightSprite[i], 1);
	}
	_lightSprite[0]->setPosition(Vec2(_size.width / 4, _size.height * 3 / 4));
	_lightSprite[1]->setPosition(Vec2(_size.width * 3 / 4, _size.height *3 / 4));
	_lightSprite[2]->setPosition(Vec2(_size.width / 4, _size.height / 4));
	_lightSprite[3]->setPosition(Vec2(_size.width * 3 / 4, _size.height / 4));


}


bool Mentalism::onTouchBegan(Touch* touch, Event* event) {
	if(!_hasTouched){
		auto location = touch->getLocation();
	}
	else {

	}
    return true;
}

void Mentalism::onTouchEnded(Touch* touch, Event* event) {

}



void Mentalism::update(float dt) {
	_time += dt;
	if(_time >= 13.0f) {
		_time = 0.0f;
	}
	_value = (int) _time;
	for(int i = 1; i <= SIZE; i++) {
		_light[SIZE - i] = _value % 2;
		_value /= 2; 
	}
	updateLight();
}

void Mentalism::updateLight() {
	for(int i = 0; i < SIZE; i++) {
		if(_currentLight[i] != _light[i]) {
			_currentLight[i] = _light[i];
			if(_light[i] == 0) {
				_lightSprite[i]->setVisible(false);
			}
			else {
				_lightSprite[i]->setVisible(true);
			}
		}
	}
}

void Mentalism::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

}
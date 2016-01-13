#ifndef __MENTALISM_SCENE_H__
#define __MENTALISM_SCENE_H__

#pragma once
#include "cocos2d.h"

USING_NS_CC;
class Mentalism : public Layer
{
private:
	const static int SIZE = 4;
	Size _size;
	Vec2 _origin;
	Sprite* _pokerOneSide;
	Sprite* _pokerOtherSide;
	Sprite* _lightSprite[SIZE];
	Action* _action;
	bool _hasTouched;
	float _time;
	int _value;
	int _light[SIZE];
	int _currentLight[SIZE];

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void initData();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    virtual void update(float dt) override;
    void initLight();
    void updateLight();
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    CREATE_FUNC(Mentalism);
};

#endif // __MENTALISM_SCENE_H__

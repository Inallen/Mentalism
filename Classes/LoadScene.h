#ifndef __LOAD_SCENE_H__
#define __LOAD_SCENE_H__

#pragma once
#include "cocos2d.h"
#include "MentalismScene.h"
#include "Global.h"

USING_NS_CC;

class LoadScene : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();
    
    void loadGameScene();
    
    // implement the "static create()" method manually
    CREATE_FUNC(LoadScene);
};

#endif // __LOAD_SCENE_H__

//
//  AnotherScene.h
//  TZFE
//
//  Created by songbo on 14-5-13.
//
//

#ifndef __TZFE__AnotherScene__
#define __TZFE__AnotherScene__

#include <iostream>
#include "cocos2d.h"

class AnotherClass : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(AnotherClass);
    
    void turnBackHelloWorldScene(Object *pSender);
};

#endif /* defined(__TZFE__AnotherScene__) */
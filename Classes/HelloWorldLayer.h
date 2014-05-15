#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CardSprite.h"

class HelloWorld : public cocos2d::Layer
{
public:
    CardSprite *cardArr[4][4];
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    bool doUp();
    bool doDown();
    bool doLeft();
    bool doRight();
    
    void presentAnotherView(Object *pSender);
    void createCardSprite(cocos2d::Size size);
    void autoCreateNewCard();
    void checkGameOver();
    
private:
    int firstX, firstY, endX, endY;
};

#endif // __HELLOWORLD_SCENE_H__

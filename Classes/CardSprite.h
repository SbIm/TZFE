//
//  CardSprite.h
//  TZFE
//
//  Created by songbo on 14-4-22.
//
//

#ifndef __CARDSPRITE_SCENE_H__
#define __CARDSPRITE_SCENE_H__

#include "cocos2d.h"

class CardSprite : public cocos2d::Sprite
{
public:
    static CardSprite* createCardSprite(int numbers,int width,int height,float CardSpriteX,float CardSpriteY);
    virtual bool init();
    CREATE_FUNC(CardSprite);
    
    int getNumber();
    void setNumber(int num);
    
private:
    int number;
    void enemyInit(int numbers,int width,int height,float CardSpriteX,float CardSpriteY);
    
    cocos2d::LabelTTF* labelTTFCardNumber;
    cocos2d::LayerColor* layerColorBG;
};

#endif // __CARDSPRITE_SCENE_H__

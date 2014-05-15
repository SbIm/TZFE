//
//  CardSprite.cpp
//  TZFE
//
//  Created by songbo on 14-4-22.
//
//

#include "CardSprite.h"

USING_NS_CC;

CardSprite* CardSprite::createCardSprite(int numbers,int width,int height,float CardSpriteX,float CardSpriteY)
{
    CardSprite* enemy = new CardSprite();
    if(enemy && enemy->init())
    {
        enemy->autorelease();
        enemy->enemyInit(numbers, width, height, CardSpriteX, CardSpriteY);
        
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);
    return NULL;
}

bool CardSprite::init()
{
    if(!Sprite::init())
    {
        return false;
    }
    
    return true;
}

void CardSprite::enemyInit(int numbers,int width,int height,float CardSpriteX,float CardSpriteY)
{
    //set init number
    number = numbers;
    
    //add game background color
    layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(100,100,255, 150),width-15,height-15);
    layerColorBG->setPosition(Point(CardSpriteX,CardSpriteY));
    
    
    
    //judge: if number>0, show it
    if(number > 0)
    {
        //set font
        labelTTFCardNumber = LabelTTF::create(String::createWithFormat("%i",number)->getCString(),"HiraKakuProN-W6",40);
        labelTTFCardNumber->setPosition(Point(layerColorBG->getContentSize().width/2,layerColorBG->getContentSize().height/2));
        labelTTFCardNumber->setTag(8);
        layerColorBG->addChild(labelTTFCardNumber);
    }
    else
    {
        //set font
        labelTTFCardNumber = LabelTTF::create("","HiraKakuProN-W6",40);
        labelTTFCardNumber->setPosition(Point(layerColorBG->getContentSize().width/2,layerColorBG->getContentSize().height/2));
        labelTTFCardNumber->setTag(8);
        layerColorBG->addChild(labelTTFCardNumber);
    }
    this->addChild(layerColorBG);
    
}

//get card number
int CardSprite::getNumber()
{
    return number;
}

//set card number
void CardSprite::setNumber(int num)
{
    number = num;
    
    if(number > 0)
    {
        //update card number
        labelTTFCardNumber->setString(String::createWithFormat("%i",number)->getCString());
    }
    else
    {
        labelTTFCardNumber->setString("");
    }
}

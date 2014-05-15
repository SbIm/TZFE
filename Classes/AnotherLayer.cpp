//
//  AnotherScene.cpp
//  TZFE
//
//  Created by songbo on 14-5-13.
//
//

#include "AnotherLayer.h"
#include "HelloWorldLayer.h"

USING_NS_CC;

Scene* AnotherClass::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = AnotherClass::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool AnotherClass::init()
{
    if (!Layer::init()) {
        return false;
    }
    //add a button
    auto menuItem = MenuItemImage::create("Button.png", "ButtonClicked.png", CC_CALLBACK_1(AnotherClass::turnBackHelloWorldScene, this));
    menuItem->setPosition(Point(450, 730));
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void AnotherClass::turnBackHelloWorldScene(Object *pSender)
{
    auto helloWorldScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene( CCTransitionFade::create(2, helloWorldScene));
    
}

#include "HelloWorldScene.h"

USING_NS_CC;

static float myRand_0_1()
{
    timeval psv;
    gettimeofday(&psv, NULL);
    unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000 + rand();
    srand(tsrans);
    return CCRANDOM_0_1();
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Point origin = Director::getInstance()->getVisibleOrigin();
    auto layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(180, 170, 160, 255));
    this->addChild(layerColorBG);
    createCardSprite(visibleSize);
    
    autoCreateNewCard();
    autoCreateNewCard();
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

//handle interface
bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    Point touchPoint = touch->getLocation();
    touch->getLocationInView();
    firstX = touchPoint.x;
    firstY = touchPoint.y;
    
    return true;
}

void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    Point touchPoint = touch->getLocation();
    endX = firstX - touchPoint.x;
    endY = firstY - touchPoint.y;
    
    if (abs(endX) > abs(endY))
    {
        if (endX + 5 > 0)
        {
            doLeft();
        }
        else
        {
            doRight();
        }
    }
    else
    {
        if (endY + 5 > 0)
        {
            doDown();
        }
        else
        {
            doUp();
        }
    }
    autoCreateNewCard();
    checkGameOver();
}

bool HelloWorld::doUp()
{
    bool isdo = false;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 3; y >= 0; y--)
        {
            for (int y1 = y - 1; y1 >= 0; y1--)
            {
                if (cardArr[x][y1]->getNumber() > 0)
                {
                    if (cardArr[x][y]->getNumber() <= 0)
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                        
                        y++;
                        isdo = true;
                    }
                    else if (cardArr[x][y1]->getNumber() == cardArr[x][y]->getNumber())
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
                        cardArr[x][y1]->setNumber(0);
                        
                        isdo = true;
                    }
                    break;
                }
            }
        }
    }
    return isdo;
}

bool HelloWorld::doDown()
{
    bool isdo = false;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int y1 = y + 1; y1 < 4; y1++)
            {
                if (cardArr[x][y1]->getNumber() > 0)
                {
                    if (cardArr[x][y]->getNumber() <= 0)
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                        
                        y--;
                        isdo = true;
                    }
                    else if (cardArr[x][y1]->getNumber() == cardArr[x][y]->getNumber())
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
                        cardArr[x][y1]->setNumber(0);
                        
                        isdo = true;
                    }
                    break;
                }
            }
        }
    }
    return isdo;
}

bool HelloWorld::doLeft()
{
    bool isdo = false;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            for (int x1 = x + 1; x1 < 4; x1 ++)
            {
                if (cardArr[x1][y]->getNumber() > 0)
                {
                    if (cardArr[x][y]->getNumber() <= 0)
                    {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                        
                        x--;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber())
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x1][y]->setNumber(0);
                        
                        isdo = true;
                    }
                    break;
                }
            }
        }
    }
    return isdo;
}

bool HelloWorld::doRight()
{
    bool isdo = false;
    for (int y = 3; y >= 0; y--)
    {
        for (int x = 3; x >= 0; x--)
        {
            for (int x2 = x - 1; x2 >= 0; x2--)
            {
                if (cardArr[x2][y]->getNumber() > 0)
                {
                    if (cardArr[x][y]->getNumber() <= 0)
                    {
                        cardArr[x][y]->setNumber(cardArr[x2][y]->getNumber());
                        cardArr[x2][y]->setNumber(0);
                        
                        x++;
                        isdo = true;
                    }
                    else if (cardArr[x][y]->getNumber() == cardArr[x2][y]->getNumber())
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
                        cardArr[x2][y]->setNumber(0);
                        
                        isdo = true;
                    }
                    break;
                }
            }
        }
    }
    
    return isdo;
}

void HelloWorld::createCardSprite(cocos2d::Size size)
{
    int uintSize = (size.height - 28) / 4;
    log("the uintsize : %d", uintSize); //73
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            CardSprite *card = CardSprite::createCardSprite(0, uintSize, uintSize, uintSize * i + 140, uintSize * j + 20);
            cardArr[i][j] = card;
            addChild(card);
        }
    }
}

void HelloWorld::autoCreateNewCard()
{
    int zeroCardNumber = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (0 == cardArr[i][j]->getNumber())
            {
                zeroCardNumber++;
            }
        }
    }
    //reset
    int randomCard = (int)(myRand_0_1() * zeroCardNumber) + 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (0 == cardArr[i][j]->getNumber())
            {
                randomCard--;
            }
            if (0 == randomCard)
            {
                cardArr[i][j]->setNumber(myRand_0_1() * 10 < 1 ? 4 : 2);
                
                return;
            }
        }
    }
}

void HelloWorld::checkGameOver()
{
    bool isGameOver = true;
    
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (cardArr[x][y]->getNumber() == 0 ||
                (x > 0 && (cardArr[x][y]->getNumber() == cardArr[x-1][y]->getNumber())) ||
                (x < 3 && (cardArr[x][y]->getNumber() == cardArr[x+1][y]->getNumber())) ||
                (y > 0 && (cardArr[x][y]->getNumber() == cardArr[x][y-1]->getNumber())) ||
                (y < 3 && (cardArr[x][y]->getNumber() == cardArr[x][y+1]->getNumber()))) {
                isGameOver = false;
            }
        }
    }
    
    if (isGameOver) {
        log("game over");
        Director::getInstance()->replaceScene(TransitionFade::create(1, HelloWorld::createScene()));
    }
}
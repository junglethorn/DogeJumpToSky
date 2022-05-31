#include "myscene.h"
#include <stdlib.h>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    //207 X 117
    for(int i=0; i<16; i++){
        this->item[i] = new myitem;
        this->item[i]->setRect(0, 0, 80, 80);
        this->item[i]->setBrush(QBrush(QColor(255, 0, 255)));
        this->item[i]->setPos(i%4 * this->item[i]->boundingRect().width(),
                              i/4 * this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }

    this->ptimer = new QTimer;
    //connect(this->ptimer, SIGNAL(timeout()), this, SLOT(showMouse()));
}

void MyScene::showMouse()
{
    //随机一个数字 0-15
    int count = rand()%(3) + 1; // 1-3
    int i = 0;
    for(i=0; i<16; i++){
        this->item[i]->setPic(":/background.png");
        this->item[i]->setMouse(false);
        this->item[i]->setHit(false);
    }
    for(i=0; i<count; i++){
        int index = rand()%16;
        this->item[index]->setPic(":/ac.png");
        this->item[index]->setMouse(true);
    }

}

void MyScene::startGame()
{
    this->ptimer->start(1000);
    for(int i=0; i<16; i++){
        this->item[i]->setStart(true);
    }

}

void MyScene::pulseGame()
{
    this->ptimer->stop();
    for(int i=0; i<16; i++){
        this->item[i]->setStart(false);
    }
}

void MyScene::stopGame()
{
    this->ptimer->stop();
    for(int i=0; i<16; i++){
        this->item[i]->setPic(":/background.png");
        this->item[i]->setMouse(false);
    }

    for(int i=0; i<16; i++){
        this->item[i]->setStart(false);
    }
}

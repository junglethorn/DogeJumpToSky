#include "myscene.h"
#include <stdlib.h>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    //207 X 117



    this->ptimer = new QTimer;
    connect(this->ptimer, SIGNAL(timeout()), this, SLOT(showMouse()));
}

void MyScene::showMouse()
{
    //随机一个数字 0-15
    int count = rand()%(3) + 1; // 1-3
    int i = 0;


}

void MyScene::startGame()
{
    this->ptimer->start(1000);


}

void MyScene::pulseGame()
{
    this->ptimer->stop();


}

void MyScene::stopGame()
{
    this->ptimer->stop();




}

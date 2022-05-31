#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include <QCursor>

myitem::myitem()
{
    //this->setPixmap(QPixmap("background.png"));
    this->start = false;
    this->mouse = false;
    this->hit = false;
    //this->setCursor(QCursor(QPixmap("background.png")));//设置光标
}

void myitem::setPic(QString path)
{
    //this->setPixmap(QPixmap(path));
}

void myitem::setMouse(bool mouse)
{
    this->mouse = mouse;
}

bool myitem::isMouse()
{
    return this->mouse;
}

void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/gcs.jpg")));
    if(!this->isStart())
        return;

    //handler* hand = handler::getInstance();

    //if(this->isMouse() && this->hit==false){
    //    hand->addScore();
    //    this->hit = true;
    //}
}

void myitem::setStart(bool start)
{
    this->start = start;
}

bool myitem::isStart()
{
    return this->start;
}

void myitem::setHit(bool hit)
{
    this->hit = hit;
}

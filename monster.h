#ifndef MONSTER_H
#define MONSTER_H

#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QGraphicsScene>
#include "config.h"

class monster:public QGraphicsPixmapItem
{
public:
    monster();
    void draw();
    void stamped();
public:
    QPixmap m_monster;
    //位置
    int m_X;
    int m_Y;
    bool used=0;
};

#endif // MONSTER_H

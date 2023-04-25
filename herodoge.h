#ifndef HERODOGE_H
#define HERODOGE_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QRect>

class HeroDoge:public QGraphicsPixmapItem
{
public:
    HeroDoge();
    void setPosition(int x,int y);
    void draw();
public:
    //doge对象
    QPixmap m_Doge;
    //doge坐标
    int m_X;
    int m_Y;
    //doge的矩形边框
    QRect m_Rect;
    //上一次踩到的块
    int last_board;
    int protect=0;
};



#endif // HERODOGE_H

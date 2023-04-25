#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsPixmapItem>
#include "config.h"
class Board:public QGraphicsPixmapItem
{

public:
    Board();
    //更新坐标
    void updatePosition();
    //查询类型
    virtual int getType();
    //绘制
    virtual void draw();
public:
    //acboard对象
    QPixmap m_board;
    //位置
    int m_X;
    int m_Y;
};

#endif // BOARD_H

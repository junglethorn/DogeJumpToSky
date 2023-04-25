#ifndef ACBOARD_H
#define ACBOARD_H
#include "config.h"
#include "board.h"
#include <QPixmap>

class ACBoard:public Board
{

public:
    ACBoard();
    //查询类型
    virtual int getType();
    //绘制
    virtual void draw();
};

#endif // ACBOARD_H

#ifndef SPRING_H
#define SPRING_H

#include "config.h"
#include "board.h"
#include <QPixmap>

class Spring:public Board
{

public:
    Spring();
    //查询类型
    virtual int getType();
    //绘制
    virtual void draw();
};


#endif // SPRING_H

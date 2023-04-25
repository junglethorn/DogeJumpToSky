#ifndef WABOARD_H
#define WABOARD_H
#include "config.h"
#include "board.h"
#include <QPixmap>

class WABoard:public Board
{

public:
    WABoard();
    virtual int getType();
    virtual void draw();
    void crash();//碎裂
public:
     bool crashed;
};



#endif // WABOARD_H

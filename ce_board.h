#ifndef CEBOARD_H
#define CEBOARD_H
#include "board.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
class CEBoard:public QObject,public Board
{
    Q_OBJECT
public:
    CEBoard();
    virtual int getType();
    virtual void draw();
    void stamped();
public:
    bool used;
};

#endif // CEBOARD_H

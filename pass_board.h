#ifndef PASSBOARD_H
#define PASSBOARD_H
#include "board.h"
#include <QTimer>
#include <QObject>

class PassBoard : public QObject,public Board
{
    Q_OBJECT
public:
    PassBoard(bool vertical_);
    int getType();
    void draw();
    void move();
public:
    bool vertical;
    int dir;
    int len;
    QTimer timer;
};

#endif // PASSBOARD_H

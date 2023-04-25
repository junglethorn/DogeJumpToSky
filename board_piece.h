#ifndef BOARDPIECE_H
#define BOARDPIECE_H
#include "board.h"
#include <QTimer>

class BoardPiece:public QObject,public Board
{
    Q_OBJECT
public:
    BoardPiece(bool isleft_);
    void draw();
    void move();
public:
    QTimer timer;
    bool isleft;
    QMatrix matrix;
    int dx,dy,du;
};

#endif // BOARDPIECE_H

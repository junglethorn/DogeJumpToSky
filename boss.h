#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "barrier.h"

class Boss : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Boss(QGraphicsScene* psubscene_,QObject *parent = 0);
    void generate_barrier();
    void move();
    void draw();
    void stopf();
    void continuef();
public:
    double dx=3.2;
    double du=-0.02;
    int dir=1;
    int len=0;
    bool barrierThere=0;
    bool stop=0;
    QPixmap m_boss;
    QTimer* timer;
    QTimer* barrier_generate_timer;
    Barrier* pbarrier;
    QGraphicsScene* psubscene;
};

#endif // BOSS_H

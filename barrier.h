#ifndef BARRIER_H
#define BARRIER_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Barrier : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Barrier(QObject *parent = 0);
    void draw();
    void move();
    void stopf();
    void continuef();
public:
    QTimer timer;
    QPixmap m_barrier;
    double dy,du;
    bool stop=0;
};

#endif // BARRIER_H

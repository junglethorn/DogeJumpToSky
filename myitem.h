#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>

class myitem : public QGraphicsPixmapItem
{
public:
    myitem();
    void setPic(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setMouse(bool mouse);
    bool isMouse();
    void setStart(bool start);
    bool isStart();
    void setHit(bool hit);

private:
    bool mouse;
    bool start;
    bool hit;
};


#endif // MYITEM_H
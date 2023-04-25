#ifndef MAP_H
#define MAP_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
class Map:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Map(QString path,double w,double h);
    void draw();
    void fade_in();
public:
    //地图图片对象
    QPixmap m_map1;
};
#endif // MAP_H

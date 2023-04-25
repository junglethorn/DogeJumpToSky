#include "map.h"
#include "config.h"
Map::Map(QString path,double w,double h)
{
    //初始化加载地图对象
    m_map1.load(path);
    //调整图像大小
    m_map1=m_map1.scaled(w,h);
}

void Map::draw(){
    setPixmap(m_map1);
}

void Map::fade_in(){
    setPixmap(m_map1);


    //淡入效果动画
    QGraphicsOpacityEffect *  pEffect;
    QPropertyAnimation * pAnimation;

    pEffect = new QGraphicsOpacityEffect(this);
    pEffect->setOpacity(0);
    this->setGraphicsEffect(pEffect);

    pAnimation = new QPropertyAnimation(pEffect,"opacity",this);
    pAnimation->setDuration(1500);
    pAnimation->setStartValue(0);
    pAnimation->setEndValue(1.0);
    pAnimation->start();
}

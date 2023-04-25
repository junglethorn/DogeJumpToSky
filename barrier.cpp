#include "barrier.h"
#include "config.h"
Barrier::Barrier(QObject *parent) : QObject(parent)
{
    m_barrier.load(BARRIER_PATH);//加载图片
    m_barrier=m_barrier.scaled(BARRIER_LEN,BARRIER_LEN);//调整大小
    //timer设置
    connect(&timer,&QTimer::timeout,[=](){
        move();
    });
    //移动相关参数设置
    dy=0;
    du=0.05;
    //开始计时
    timer.start(GAME_RATE);
}

void Barrier::draw(){
    setPixmap(m_barrier);
}

void Barrier::move(){
    dy+=du;
    setPos(x(),y()+dy);
    draw();
    if(y()>1250){
        timer.stop();
    }
}

void Barrier::stopf(){
    stop=1;
    timer.stop();
}

void Barrier::continuef(){
    stop=0;
    timer.start();
}

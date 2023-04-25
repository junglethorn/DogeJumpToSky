#include "boss.h"
#include "config.h"

Boss::Boss(QGraphicsScene* psubscene_,QObject *parent) : QObject(parent),psubscene(psubscene_)
{
    m_boss.load(BOSS_PATH);//加载图片
    setPos(275,0);
    m_boss=m_boss.scaled(m_boss.width()*1.5,m_boss.height()*1.5);//调整大小

    //timer设置
    timer=new QTimer;
    timer->start(GAME_RATE);
    connect(timer,&QTimer::timeout,[=](){
        move();
    });

    //发射干扰物的timer设置
    barrier_generate_timer=new QTimer;
    barrier_generate_timer->start(5000);
    connect(barrier_generate_timer,&QTimer::timeout,[=](){
        generate_barrier();
    });
}

void Boss::draw(){
    setPixmap(m_boss);
}

void Boss::move(){
    dx+=du;
    setPos(x()+dx,y());
    if((dx<-3.2&&du<0)||(dx>3.2&&du>0)){
        du=-du;
    }
    draw();
}

void Boss::generate_barrier(){
    barrierThere=1;
    pbarrier=new Barrier;
    psubscene->addItem(pbarrier);
    pbarrier->setPos(x(),y()+BARRIER_LEN);
}

void Boss::stopf(){
    stop=1;
    timer->stop();
    barrier_generate_timer->stop();
    if(barrierThere)
        pbarrier->stopf();
}

void Boss::continuef(){
    stop=0;
    timer->start();
    barrier_generate_timer->start();
    if(barrierThere)
        pbarrier->continuef();
}

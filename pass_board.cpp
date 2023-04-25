#include "pass_board.h"

PassBoard::PassBoard(bool vertical_):vertical(vertical_)
{
    //图片参数设置
    m_board.load(PASS_BOARD_PATH);
    m_board=m_board.scaled(BOARD_WIDTH,BOARD_HEIGHT);
    //移动相关参数设置
    dir=0;
    len=0;
    //timer设置
    timer.start(GAME_RATE);
    connect(&timer,&QTimer::timeout,[=](){
        move();
    });
}
int PassBoard::getType(){//得到类型
    return 2;
}

void PassBoard::draw(){//绘制
    setPixmap(m_board);
}

void PassBoard::move(){//移动函数
    if(vertical){
        if(dir){
            len++;
            setPos(x(),y()-1);
            if(len==90){
                dir=0;
            }
        }
        else{
            len--;
            setPos(x(),y()+1);
            if(len==-90){
                dir=1;
            }
        }
    }
    else{
        if(dir){
            len++;
            setPos(x()-2,y());
            if(len==90){
                dir=0;
            }
        }
        else{
            len--;
            setPos(x()+2,y());
            if(len==-90){
                dir=1;
            }
        }
    }
    m_X=x();
    m_Y=y();
    /*
    if(y()>1200){
        timer.stop();
    }*/
}

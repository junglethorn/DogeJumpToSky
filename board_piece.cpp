#include "board_piece.h"
#include "config.h"
BoardPiece::BoardPiece(bool isleft_):isleft(isleft_)
{    
    if(isleft){
        m_board.load(WA_PIECE1_PATH);//加载图片
        m_board=m_board.scaled(BOARD_WIDTH*0.5,BOARD_HEIGHT*0.95);//调整大小
        matrix.rotate(-45);//设置旋转角度
    }
    else{
        m_board.load(WA_PIECE2_PATH);
        m_board=m_board.scaled(BOARD_WIDTH*0.5,BOARD_HEIGHT*0.95);
        matrix.rotate(45);
    }
    //timer设置
    timer.start(GAME_RATE);
    connect(&timer,&QTimer::timeout,[=](){
        move();
    });
    //移动相关参数设置
    if(isleft)dx=-1;
    else dx=1;
    dy=2;
    du=1;
}

void BoardPiece::draw(){
    setPixmap(m_board.transformed(matrix, Qt::SmoothTransformation));
}

void BoardPiece::move(){
    dy+=du;
    setPos(x()+dx,y()+dy);
    draw();
    if(y()>1220){
        timer.stop();
    }
}





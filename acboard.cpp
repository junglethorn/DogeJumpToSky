#include "acboard.h"


ACBoard::ACBoard()
{
    //acboard加载
    m_board.load(ACBOARD_PATH);
    //调整acboard大小
    m_board=m_board.scaled(BOARD_WIDTH*0.9,BOARD_HEIGHT);
    //acboard位置
    m_X = 0;
    m_Y = 0;
}

int ACBoard::getType(){
    return 0;
}

void ACBoard::draw(){
    setPixmap(m_board);
}

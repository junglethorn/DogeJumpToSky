#include "spring.h"

Spring::Spring()
{
    m_board.load(SPRING_PATH);
    //调整acboard大小
    m_board=m_board.scaled(BOARD_WIDTH*0.9,BOARD_HEIGHT);
    //acboard位置
    m_X = 0;
    m_Y = 0;
}

int Spring::getType(){
    return 6;
}

void Spring::draw(){
    setPixmap(m_board);
}

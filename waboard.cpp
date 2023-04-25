#include "waboard.h"

WABoard::WABoard()
{
    m_board.load(WABOARD_PATH);
    m_board=m_board.scaled(BOARD_WIDTH*1.2,BOARD_HEIGHT*1.2);
    m_X = 0;
    m_Y = 0;
    crashed=0;
}

int WABoard::getType(){
    return 1;
}

void WABoard::draw(){
    if(!crashed)
        setPixmap(m_board);
}

void WABoard::crash(){//碎裂
    crashed=1;
    m_board.fill(Qt::transparent);
    setPixmap(m_board);
}

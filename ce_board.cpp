#include "ce_board.h"
#include "config.h"
CEBoard::CEBoard()
{
    m_board.load(CEBOARD_PATH);
    m_board=m_board.scaled(BOARD_WIDTH,BOARD_HEIGHT);
    m_X = 0;
    m_Y = 0;
    used=0;
}

int CEBoard::getType(){
    return 3;
}

void CEBoard::draw(){
    if(!used)
        setPixmap(m_board);
}

void CEBoard::stamped(){
    used=1;

    //透明效果动画
    QGraphicsOpacityEffect *  pEffect;
    QPropertyAnimation * pAnimation;

    pEffect = new QGraphicsOpacityEffect(this);
    pEffect->setOpacity(1.0);
    this->setGraphicsEffect(pEffect);

    pAnimation = new QPropertyAnimation(pEffect,"opacity",this);
    pAnimation->setDuration(300);
    pAnimation->setStartValue(1.0);
    pAnimation->setEndValue(0);
    pAnimation->start();
}

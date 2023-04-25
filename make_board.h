#ifndef MAKE_BOARD_H
#define MAKE_BOARD_H
#include "board.h"
#include "acboard.h"
#include "waboard.h"
#include "ce_board.h"
#include "spring.h"
#include "pass_board.h"
Board* makeBoard(int x,int y,int& WATimes){
    Board* pboard;
    int rdm=rand()%25;
    if(rdm>=0&&rdm<=2&&WATimes<2){
        ++WATimes;
        pboard=new WABoard;
        pboard->setPos(x,y);
    }
    else if(rdm==3||rdm==4){
        WATimes=0;
        pboard=new PassBoard(0);
        pboard->setPos(x,y);
    }
    else if(rdm==5||rdm==6){
        WATimes=0;
        pboard=new PassBoard(1);
        pboard->setPos(x,y);
    }
    else if(rdm>=7&&rdm<=10){
        WATimes=0;
        pboard=new CEBoard;
        pboard->setPos(x,y);
    }
    else if(rdm>=11&&rdm<=13){
        WATimes=0;
        pboard=new Spring;
        pboard->setPos(x,y);
    }
    else{
        WATimes=0;
        pboard=new ACBoard;
        pboard->setPos(x,y);
    }
    return pboard;
}

#endif // MAKE_BOARD_H

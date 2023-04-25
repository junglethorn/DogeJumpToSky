#ifndef MAKE_MONSTER_H
#define MAKE_MONSTER_H

#include "monster.h"
monster* makeMonster(int x, int y) {
    monster* pmonster;
    pmonster = new monster;
    pmonster->setPos(x, y);
    return pmonster;
}

#endif // MAKE_MONSTER_H

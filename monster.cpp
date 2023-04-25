#include "monster.h"

monster::monster()
{
    m_monster.load(MONSTER_PATH);
    //调整大小
    m_monster = m_monster.scaled(MONSTER_WIDTH, MONSTER_HEIGHT);
    //位置
    m_X = 0;
    m_Y = 0;
}

void monster::draw()
{
    setPixmap(m_monster);
}

void monster::stamped(){
    used=1;
    m_monster.fill(Qt::transparent);
    setPixmap(m_monster);
}

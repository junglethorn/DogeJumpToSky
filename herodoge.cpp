#include "herodoge.h"
#include "config.h"

void HeroDoge::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);

}

HeroDoge::HeroDoge()
{
    //初始化加载doge图片资源
    m_Doge.load(HERO_PATH);
    //调整doge图像大小
    m_Doge=m_Doge.scaled(m_Doge.width()*1.2,m_Doge.height()*1.2);
    //初始化doge坐标
    m_X = (MAP_WIDTH-m_Doge.width())*0.27;
    m_Y = MAP_HEIGHT-m_Doge.height()*5;
    //初始化其他指标
    last_board=0;
}

void HeroDoge::draw(){
    setPixmap(m_Doge);
}

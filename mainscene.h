#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include "map.h"
#include "config.h"
#include "herodoge.h"
#include "acboard.h"
#include "waboard.h"
#include "ce_board.h"
#include "pass_board.h"
#include "board_piece.h"
#include "end_window.h"
#include "boss.h"
#include "monster.h"

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    //初始化场景
    void initScene();
    //启动游戏
    void playGame();
    //重新制作按下按键事件
    void keyPressEvent(QKeyEvent *pevent);
    //重新制作松开按键事件
    void keyReleaseEvent(QKeyEvent *pevent);
    //板出场
    void boardToScene();
    //人物跳跃和镜头移动
    void jump();
    //碰撞检测
    bool collisionDetection(int i);
    void monsterCollision(int i);
    //键盘控制移动
    void move_manip();
    //板块更新
    void board_update(int i);
    //小怪更新
    void monster_update(int i);
    //游戏结束跳转
    void go_to_end(int killed);
    //boss出场
    void generate_boss();
    //根据分数判断boss出场时机和提示语的显示
    void judge_score();


public:
    //板块指针数组
    Board* pboard[BOARD_NUM];
    //小怪指针数组
    monster* pmonster[MONSTER_NUM];
    //子场景
    QGraphicsScene subscene;
    //地图指针
    Map* m_map;
    //doge对象
    HeroDoge* m_hero;
    //定时器
    QTimer* m_Timer;
    //boss对象
    Boss* boss;
    int bossThere;
    //其他指标
    int WATimes;
    bool stop;
private slots:
    void on_stop_clicked();

    void on_continue_btn_clicked();

    void on_restart_clicked();

    void on_end_clicked();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H

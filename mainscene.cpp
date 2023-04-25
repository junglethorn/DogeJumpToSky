#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include "make_board.h"
#include "make_monster.h"
#include <QIcon>
#include <QSound>
#include <QMouseEvent>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>

static double dy=0,du=0.4;//纵向位移量与位移变化量
static int doge_x,doge_y;
static double cur_score=0;
static QVector<Qt::Key> pressedKeys;
QTimer *keyPressTimer;

MainScene::MainScene(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //调用初始化场景
    initScene();
    //启动游戏
    playGame();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()//场景初始化
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEHGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);
    //设置icon
    setWindowIcon(QIcon(GAME_ICON));
    //设定随机种子
    srand(time(NULL));
    //定时器设置
    m_Timer=new QTimer;
    m_Timer->setInterval(GAME_RATE);
    keyPressTimer=new QTimer;
    keyPressTimer->setInterval(KEY_REPEAT_RATE);
    //设置子场景
    subscene.setSceneRect(0,0,GAMEVIEW_WIDTH,GAMEVIEW_HEIGHT);
    ui->graphicsView->setScene(&subscene);
    //设置子场景背景
    m_map=new Map(MAP_PATH,MAP_WIDTH,MAP_HEIGHT);
    m_map->setPos(-5,-5);
    subscene.addItem(m_map);
    m_map->draw();
    //设置按钮
    ui->stop->setStyleSheet(BOTTON_CONFIG);
    ui->restart->setStyleSheet(BOTTON_CONFIG);
    ui->end->setStyleSheet(BOTTON_CONFIG);
    ui->continue_btn->setStyleSheet(BOTTON_CONFIG);
    ui->continue_btn->setVisible(0);
    //初始化板块生成指标
    WATimes=0;
    //设置初始board布局
    pboard[0]=new ACBoard();
    pboard[0]->m_X=120;
    pboard[0]->m_Y=70+Y_INTERVAL*(BOARD_NUM-1);
    pboard[0]->setPos(pboard[0]->m_X,pboard[0]->m_Y);
    subscene.addItem(pboard[0]);
    pboard[0]->draw();
    for(int i=1;i<BOARD_NUM;i++){
        int tmpx=10+X_INTERVAL*(i-1),tmpy=70+Y_INTERVAL*(i-1);
        pboard[i]=makeBoard(tmpx,tmpy,WATimes);
        pboard[i]->m_X=tmpx;
        pboard[i]->m_Y=tmpy;
        pboard[i]->setPos(pboard[i]->m_X,pboard[i]->m_Y);
        subscene.addItem(pboard[i]);
        pboard[i]->draw();
    }
    //初始化小怪设置
    for (int i = 0; i < MONSTER_NUM; i++) {
        int tmpx = 50 + MONSTER_X_INTERVAL * (i+1), tmpy = 100 + MONSTER_Y_INTERVAL * (i+ 1);
        pmonster[i] = makeMonster(tmpx, tmpy);
        pmonster[i]->m_X = tmpx;
        pmonster[i]->m_Y = tmpy;
        pmonster[i]->setPos(pmonster[i]->m_X, pmonster[i]->m_Y);
        subscene.addItem(pmonster[i]);
        pmonster[i]->draw();
    }
    //将玩家加入子场景视图
    m_hero=new HeroDoge;
    m_hero->m_X = (MAP_WIDTH-m_hero->m_Doge.width())*0.27;
    m_hero->m_Y = MAP_HEIGHT-m_hero->m_Doge.height()*5;
    m_hero->setPos(m_hero->m_X,m_hero->m_Y);
    subscene.addItem(m_hero);
    m_hero->draw();
    doge_y=m_hero->m_Y;
    doge_x=m_hero->m_X;
    //初始化提示
    ui->tip->setText("通过\n踩小虫\ndebug\n以获取\n更高分\n\n移动板\n得分更高\n\n最终\nboss是\nPOJ\n小心它的\n断网法术");
    //初始化其他指标
    dy=0,du=0.4;
    cur_score=0;
    stop=0;
    m_hero->last_board=0;
    bossThere=0;
}

void MainScene::playGame()//开始游戏
{
    QSound::play(SOUND_BACKGROUND);

    //监听定时器发出的信号
    connect(m_Timer,&QTimer::timeout,[=](){
        jump();
        judge_score();
    });
    connect(keyPressTimer,&QTimer::timeout,[=](){
        move_manip();
    });
    m_Timer->start();
}

void MainScene::keyPressEvent(QKeyEvent *pevent)//按键操作函数
{
    if(!stop){
        pressedKeys.append(static_cast<Qt::Key>(pevent->key()));
        if(!keyPressTimer->isActive()) {
           keyPressTimer->start(KEY_REPEAT_RATE);
        }
    }
}

void MainScene::keyReleaseEvent(QKeyEvent *pevent)//按键松开操作函数
{
    if(keyPressTimer->isActive() && pressedKeys.isEmpty()) {
        keyPressTimer->stop();
        move_manip();
    }
    pressedKeys.removeAll(static_cast<Qt::Key>(pevent->key()));
}

void MainScene::jump(){
    dy+=du;
    doge_y+=dy;
    ui->score->setNum(cur_score);

    if(doge_y>MAP_HEIGHT){//出界,游戏失败
        go_to_end(0);
    }
    if(doge_y<MOVE_THRESH){//移动视角
        doge_y=MOVE_THRESH;
        //处理板子
        for(int i=0;i<BOARD_NUM;i++){
            pboard[i]->m_Y=pboard[i]->m_Y-dy;
            //清除出界的板子,产生新板子
            if(pboard[i]->getType()==2){
                PassBoard* ppass=(PassBoard*)pboard[i];
                if(ppass->vertical){
                    if(ppass->m_Y+ppass->len>=MAP_HEIGHT){
                        ppass->timer.stop();
                        board_update(i);
                    }
                }
                else if(pboard[i]->m_Y>=MAP_HEIGHT){
                    board_update(i);
                }
            }
            else if(pboard[i]->m_Y>=MAP_HEIGHT){
                board_update(i);
            }
        }
        for(int i=0;i<BOARD_NUM;i++){
            pboard[i]->setPos(pboard[i]->m_X,pboard[i]->m_Y);
        }
        //处理小怪
        for (int i = 0; i < MONSTER_NUM; i++) {
            pmonster[i]->m_Y = pmonster[i]->m_Y - dy;
            //清除出界的小怪，产生新小怪
            if (pmonster[i]->m_Y >= MAP_HEIGHT) {
                monster_update(i);
            }
        }
        for (int i=0;i<MONSTER_NUM;i++){
            pmonster[i]->setPos(pmonster[i]->m_X,pmonster[i]->m_Y);
        }
    }
    //板块碰撞探测
    for(int i=0;i<BOARD_NUM;i++){
        if(collisionDetection(i))break;
    }
    //小怪碰撞探测
    for (int i = 0; i < MONSTER_NUM; i++) {
        monsterCollision(i);
    }
    m_hero->m_Y=doge_y;
    m_hero->setPos(m_hero->m_X,doge_y);
    if(m_hero->m_X>GAMEVIEW_WIDTH){
        m_hero->setPos(0,m_hero->m_Y);
        m_hero->m_X=0;
    }
    else if(m_hero->m_X<0){
        m_hero->setPos(GAMEVIEW_WIDTH,m_hero->m_Y);
        m_hero->m_X=GAMEVIEW_WIDTH;
    }
    m_hero->draw();

}

bool MainScene::collisionDetection(int i)//碰撞探测
{
    if(m_hero->collidesWithItem(pboard[i])&&dy>0&&pboard[i]->m_Y>=m_hero->m_Y){
        if(pboard[i]->getType()==0){//ac板
            dy=-20;
            if(m_hero->last_board!=i){
                m_hero->last_board=i;
                cur_score+=1;
            }
        }
        else if(pboard[i]->getType()==1){//wa板
            WABoard* pwaBoard=(WABoard*)pboard[i];
            if(!pwaBoard->crashed){
                cur_score-=0.5;
                pwaBoard->crash();//wa板碎裂
                //碎裂效果
                BoardPiece* ppiece1=new BoardPiece(1);
                BoardPiece* ppiece2=new BoardPiece(0);
                subscene.addItem(ppiece1);
                subscene.addItem(ppiece2);
                ppiece1->setPos(pwaBoard->m_X-BOARD_WIDTH*0.5,pwaBoard->m_Y);
                ppiece2->setPos(pwaBoard->m_X+BOARD_WIDTH*0.5,pwaBoard->m_Y);
            }
        }
        else if(pboard[i]->getType()==2){//passed板
            dy=-20;
            if(m_hero->last_board!=i){
                m_hero->last_board=i;
                cur_score+=2;
            }
        }
        else if(pboard[i]->getType()==3){//ce板
            CEBoard* pceBoard=(CEBoard*)pboard[i];
            if(!pceBoard->used){
                dy=-20;
                cur_score+=0.5;
                pceBoard->stamped();
                m_hero->last_board=i;
            }
        }
        else if(pboard[i]->getType()==6){//SPRING
            dy=-50;
            m_hero->protect=1;
            if(m_hero->last_board!=i){
                m_hero->last_board=i;
                cur_score+=2.5;
            }
        }
        QSound::play(SOUND_BOMB);
    }
    if(bossThere&&boss->barrierThere){
        if(m_hero->collidesWithItem(boss->pbarrier)){
            go_to_end(1);
            return 1;
        }
    }
    return 0;
}

void MainScene::monsterCollision(int i) {
    if (m_hero->collidesWithItem(pmonster[i])) {
        if(dy>0&&m_hero->m_Y<=pmonster[i]->m_Y){
            if(!pmonster[i]->used){
                dy=-20;
                cur_score+=1.5;
                pmonster[i]->stamped();
                m_hero->last_board=-1;
            }
        }
        else{
            if(m_hero->protect==0){
                m_Timer->stop();
                keyPressTimer->stop();
                pressedKeys.clear();
                stop = 1;
                go_to_end(2);
            }
        }
    }
}


void MainScene::move_manip(){//操控人物
    if(pressedKeys.contains(Qt::Key_A)) {
        m_hero->protect=0;
        m_hero->m_X-=4;
        m_hero->setPos(m_hero->m_X,m_hero->m_Y);
    }
    if(pressedKeys.contains(Qt::Key_D)) {
        m_hero->protect=0;
        m_hero->m_X+=4;
        m_hero->setPos(m_hero->m_X,m_hero->m_Y);
    }

}

void MainScene::board_update(int i){//更新板块
    subscene.removeItem(pboard[i]);
    int tmpx=X_INTERVAL*(rand()%(BOARD_NUM-1));
    int tmpy=0;
    delete pboard[i];
    pboard[i]=makeBoard(tmpx,tmpy,WATimes);
    pboard[i]->m_X=tmpx;
    pboard[i]->m_Y=tmpy;
    pboard[i]->draw();
    subscene.addItem(pboard[i]);
}

void MainScene::monster_update(int i) {
    subscene.removeItem(pmonster[i]);
    int tmpx = MONSTER_X_INTERVAL * (rand() % 31);
    int tmpy = 0;
    delete pmonster[i];
    pmonster[i] = makeMonster(tmpx, tmpy);
    pmonster[i]->m_X = tmpx;
    pmonster[i]->m_Y = tmpy;
    pmonster[i]->draw();
    subscene.addItem(pmonster[i]);
}

void MainScene::on_stop_clicked()
{
    m_Timer->stop();
    keyPressTimer->stop();
    pressedKeys.clear();
    for(int i=0;i<BOARD_NUM;i++){
        if(pboard[i]->getType()==2){
            ((PassBoard*)pboard[i])->timer.stop();
        }
    }
    ui->continue_btn->setVisible(1);
    stop=1;
    if(bossThere){
        boss->stopf();
    }
}


void MainScene::on_continue_btn_clicked()
{
    m_Timer->start();
    for(int i=0;i<BOARD_NUM;i++){
        if(pboard[i]->getType()==2){
            ((PassBoard*)pboard[i])->timer.start();
        }
    }
    ui->continue_btn->setVisible(0);
    stop=0;
    if(bossThere){
        boss->continuef();
    }
}

void MainScene::on_restart_clicked()
{
    //清理原背景
    m_Timer->stop();
    keyPressTimer->stop();
    pressedKeys.clear();
    for(int i=0;i<BOARD_NUM;i++){
        if(pboard[i]->getType()==2){
            ((PassBoard*)pboard[i])->timer.stop();
        }
    }
    for(int i=0;i<BOARD_NUM;i++){
        subscene.removeItem(pboard[i]);
        delete pboard[i];
    }
    delete m_hero;
    delete m_Timer;

    if(bossThere){
        boss->timer->stop();
        boss->barrier_generate_timer->stop();
        if(boss->barrierThere){
            boss->pbarrier->timer.stop();
            subscene.removeItem(boss->pbarrier);
        }
        subscene.removeItem(boss);
    }

    //初始化参数
    dy=0,du=0.4;
    cur_score=0;
    initScene();
    //重新设定doge参数
    m_hero->last_board=0;
    //重新设定计时器参数
    keyPressTimer=new QTimer();
    connect(keyPressTimer,&QTimer::timeout,[=](){
        move_manip();
    });
    connect(m_Timer,&QTimer::timeout,[=](){
        jump();
        judge_score();
    });
    m_Timer->start();
    stop=0;
    //播放开始的音乐
    QSound::play(SOUND_BACKGROUND);
}

void MainScene::judge_score(){//根据分数判断boss是否应当出场
    if(cur_score>35&&!bossThere){
        generate_boss();
    }
    if(cur_score>=100){
        ui->tip->setText("大佬！\n你已经\n满分辣\n求求你\n别卷了\n快交卷吧");
        ui->tip->setVisible(1);
    }
}

void MainScene::generate_boss(){//生成boss
    bossThere=1;
    boss=new Boss(&subscene);
    subscene.addItem(boss);
    boss->draw();
}

void MainScene::on_end_clicked()//交卷按钮函数
{
    go_to_end(0);
}

void MainScene::go_to_end(int killed){//进入结束界面
    //清理原背景
    m_Timer->stop();
    keyPressTimer->stop();
    pressedKeys.clear();
    for(int i=0;i<BOARD_NUM;i++){
        if(pboard[i]->getType()==2){
            ((PassBoard*)pboard[i])->timer.stop();
        }
    }
    for(int i=0;i<BOARD_NUM;i++){
        subscene.removeItem(pboard[i]);
    }
    if(bossThere){
        boss->timer->stop();
        boss->barrier_generate_timer->stop();
        if(boss->barrierThere){
            boss->pbarrier->timer.stop();
            subscene.removeItem(boss->pbarrier);
        }
        subscene.removeItem(boss);
    }

    EndWindow* pEndWindow=new EndWindow(cur_score,killed);
    pEndWindow->show();
    this->close();
}

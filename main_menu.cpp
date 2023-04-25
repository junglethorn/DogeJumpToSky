#include "main_menu.h"
#include "ui_main_menu.h"
#include "config.h"
#include "mainscene.h"
#include <QTime>
#include <QSound>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    //初始化起始界面
    initMenu();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::initMenu(){
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEHGHT);
    //设置窗口标题
    setWindowTitle(GAME_TITLE);
    //设置icon
    setWindowIcon(QIcon(GAME_ICON));
    //设置按钮
    ui->start->setStyleSheet(BOTTON_CONFIG);
    ui->exit->setStyleSheet(BOTTON_CONFIG);
    //设置场景
    m_scene.setSceneRect(0,0,GAME_WIDTH,GAME_HEHGHT);
    ui->graphicsView->setScene(&m_scene);
    //设置主菜单背景
    start_bg=new Map(START_BG_PATH,1000,1400);
    start_bg->setPos(-25,-100);
    m_scene.addItem(start_bg);
    start_bg->draw();
    //设置主菜单图标
    start_icon=new Map(START_ICON_PATH,400,400);
    start_icon->setPos(200,25);
    m_scene.addItem(start_icon);
    start_icon->fade_in();
    //设置主菜单标题
    start_title=new Map(START_TITLE_PATH,600,150);
    start_title->setPos(100,300);
    m_scene.addItem(start_title);
    start_title->fade_in();
    //显示游戏说明
    info=new Map(START_INFO_PATH,1100,420);
    info->setPos(-140,450);
    m_scene.addItem(info);
    info->fade_in();
    //按钮淡入动画
    set_fade_in(ui->start);
    set_fade_in(ui->exit);
}

void MainMenu::on_start_clicked()
{
    MainScene* pMainScene=new MainScene;
    pMainScene->show();
    this->close();
}

void MainMenu::on_exit_clicked()
{
    this->close();
}

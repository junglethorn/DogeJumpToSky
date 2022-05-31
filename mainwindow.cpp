#include "mainwindow.h"
#include "myscene.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->scene = new MyScene;
    this->ui->graphicsView->setScene(scene);
    //this->scene->setBackgroundBrush(Qt::green);
    this->score = 0;
    connect(this->ui->btn_start, SIGNAL(clicked()), this->scene, SLOT(startGame()));
    connect(this->ui->btn_pulse, SIGNAL(clicked()), this->scene, SLOT(pulseGame()));
    connect(this->ui->btn_stop, SIGNAL(clicked()), this->scene, SLOT(stopGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this, "", "你真的要关闭吗", "是", "否");
    if(ret == 1){
        event->ignore();
    }
}

void MainWindow::updateScore(){
    this->score +=10;
    this->ui->lcdNumber->display(this->score);
}

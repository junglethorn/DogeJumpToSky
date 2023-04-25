#include "end_window.h"
#include "ui_end_window.h"

EndWindow::EndWindow(double score_,int killed_,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndWindow),
    score(score_),
    killed(killed_)
{
    ui->setupUi(this);

    initWindow();
}

EndWindow::~EndWindow()
{
    delete ui;
}

void EndWindow::initWindow(){
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEHGHT);
    //设置窗口标题
    setWindowTitle(GAME_TITLE);
    //设置icon
    setWindowIcon(QIcon(GAME_ICON));
    //设置场景
    m_scene.setSceneRect(0,0,GAME_WIDTH,GAME_HEHGHT);
    ui->graphicsView->setScene(&m_scene);
    //设置背景
    end_bg=new Map(END_BG_PATH,1000,1400);
    end_bg->setPos(-100,-75);
    m_scene.addItem(end_bg);
    end_bg->draw();
    //显示结果
    if(killed==1){
        ui->label->setText("你遭受了OJ的断网法术攻击！\nOJ一直显示502BadGateway，你不得不结束考试");
    }
    else if(killed==2){
        ui->label->setText("你的程序出了意外bug，de了很久也没de出来\n你不得不结束考试");
    }

    set_fade_in(ui->Text1);

    if(score>=100)
        ui->scoreLabel->setNum(100);
    else if(score<0)
        ui->scoreLabel->setNum(0);
    else
        ui->scoreLabel->setNum(score);
    set_fade_in(ui->scoreLabel);

    if(score<60){
        ui->Text2->setText("你没想到你还是没能考好，\n或许是考试太紧张？\n你不知道\n郭老师在考试最后延长了半小时\n你好不容易借此机会才做出一题\n出考场时，你的手都在抖\n你感到前所未有的失败\n信科的课程对你来说或许就是一个迈不过去的坎\n怎么办呢\n时间永是流驶，生活还要继续\n你开始寻求帮助，\n在与学长学姐的谈心中得到了许多建议\n在与老师的沟通中重新明确了目标\n渐渐地，在你的努力下，你的成绩慢慢变好\n对信科的课程也再没有原先那么恐惧.\n你渐渐放下了对自己的苛责，学会了接纳自己\n努力成为一个平凡的信科人，这也一样值得骄傲");
    }
    else if(score<85){
        ui->Text2->setText("你通过了考试\n虽然如此，你没能取得非常理想的成绩\n你觉得自己的努力还是没有应有的回报\n悲伤与焦虑交加下\n你在树洞中表达了你的emo\n没想到的是，你获得了很多人的共鸣\n也有非常多的学长学姐给你提出中肯的建议\n你重拾了希望，相信只要继续努力\n假以时日\n一切都会有改观\n曾经因为自己比不上别人而自卑的你\n现在却因能够处在这么一个团结的大家庭\n而感到无比幸运\n渐渐地\n信科的课对你而言不再是痛苦\n而是一种享受");
    }
    else{
        ui->Text2->setText("    出乎意料地\n    你取得了优秀\n    曾经的幻想成为了现实\n    你欣慰的笑了\n    多少灯火通明的夜晚\n    多少de不出bug时候的捶胸顿足\n    多少听课时跟不上老师思路的痛苦\n    多少写大作业时冥思苦想却不得思路的时刻\n    你都记得。\n    你也记得\n    树洞上学长学姐的暖心帮助\n    老师耐心答疑解惑的面孔\n    还有心理援助热线另一头温柔的声音\n    来到北大信科，多么幸运\n    在这次考试之后\n    你也知道了:\n    原来一切皆有可能");
    }
    set_fade_in(ui->Text2);

    //设置按钮
    ui->back_to_menu->setStyleSheet(BOTTON_CONFIG);
    ui->exit->setStyleSheet(BOTTON_CONFIG);
    set_fade_in(ui->back_to_menu);
    set_fade_in(ui->exit);
}

void EndWindow::on_back_to_menu_clicked()
{
    MainMenu* pMainMenu=new MainMenu;
    pMainMenu->show();
    this->close();
}

void EndWindow::on_exit_clicked()
{
    this->close();
}

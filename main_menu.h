#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "config.h"
#include "fadein_animation.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

    void initMenu();

public:
    Map* start_icon;
    Map* start_title;
    Map* start_bg;
    Map* info;
    QGraphicsScene m_scene;

private slots:
    void on_start_clicked();

    void on_exit_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAIN_MENU_H

#ifndef END_WINDOW_H
#define END_WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "config.h"
#include "main_menu.h"
#include "fadein_animation.h"

namespace Ui {
class EndWindow;
}

class EndWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndWindow(double score_,int killed_,QWidget *parent = 0);
    ~EndWindow();

    void initWindow();

private:
    Ui::EndWindow *ui;
public:
    Map* end_bg;
    QGraphicsScene m_scene;
    double score;
    int killed;
private slots:
    void on_back_to_menu_clicked();
    void on_exit_clicked();
};

#endif // END_WINDOW_H

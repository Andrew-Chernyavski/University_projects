#include <QtGui/QApplication>
#include "view.h"
#include "scene.h"
#include "sceneb.h"
#include "sceneblhole.h"
#include "menu.h"
#include "youwin.h"
#include "youlose.h"
#include <QTime>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    View view;
    Scene scene;
    SceneB scene2;
    SceneBlHole scene3;
    QTimer timer;
    timer.setInterval(20);
    YouWin win;
    YouLose lose;
    Menu menu(&view, &scene, &scene2, &scene3, &timer, &win, &lose);

    view.setScene(&menu);
    view.showFullScreen();

    return a.exec();
}

#include "menu.h"

Menu::Menu(View *v, Scene *s, SceneB *s2, SceneBlHole *s3, QTimer *t, YouWin *w, YouLose *l)
{
    emit stop();
    setSceneRect(- 500, - 375, 1000, 750);
    setBackgroundBrush(QPixmap(":/menu.jpg"));

    QGraphicsPixmapItem *level1 = new QGraphicsPixmapItem(QPixmap(":/level1.gif"));
    level1->setX(- 200);
    level1->setY(-30);
    addItem(level1);

    view = v;
    gameScene = s;
    gameScene2 = s2;
    gameScene3 = s3;
    yWin = w;
    yLose = l;
    timer = t;

    QObject::connect(yWin, SIGNAL(toMenu()), this, SLOT(returnToMenu()));
    QObject::connect(yWin, SIGNAL(next(int)), this, SLOT(restartLevel(int)));
    QObject::connect(yLose, SIGNAL(toMenu()), this, SLOT(returnToMenu()));
    QObject::connect(yLose, SIGNAL(tryAgain(int)), this, SLOT(restartLevel(int)));
    QObject::connect(gameScene, SIGNAL(youWin(int)), this, SLOT(outputWin(int)));
    QObject::connect(gameScene, SIGNAL(youLose(int)), this, SLOT(outputLose(int)));
    QObject::connect(gameScene2, SIGNAL(youWin(int)), this, SLOT(outputWin(int)));
    QObject::connect(gameScene2, SIGNAL(youLose(int)), this, SLOT(outputLose(int)));
    QObject::connect(gameScene3, SIGNAL(youWin(int)), this, SLOT(outputWin(int)));
    QObject::connect(gameScene3, SIGNAL(youLose(int)), this, SLOT(outputLose(int)));
    QObject::connect(this, SIGNAL(start()), timer, SLOT(start()));
    QObject::connect(this, SIGNAL(stop()), timer, SLOT(stop()));
    QObject::connect(gameScene, SIGNAL(stop()), view, SLOT(fullScene()));
    QObject::connect(gameScene2, SIGNAL(stop()), view, SLOT(fullScene()));
    QObject::connect(gameScene3, SIGNAL(stop()), view, SLOT(fullScene()));
    QObject::connect(this, SIGNAL(sizeForGame()), view, SLOT(normalScene()));
    QObject::connect(timer, SIGNAL(timeout()), view, SLOT(center()));
    QObject::connect(gameScene, SIGNAL(stop()), timer, SLOT(stop()));
    QObject::connect(gameScene2, SIGNAL(stop()), timer, SLOT(stop()));
    QObject::connect(gameScene3, SIGNAL(stop()), timer, SLOT(stop()));


}

void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->scenePos().x() < 200 && event->scenePos().x() > - 200)
        {
            if (event->scenePos().y() < 30 && event->scenePos().y() > -30)
            {
                gameScene->restart(1920, 1080);
                view->setScene(gameScene);
                QObject::connect(timer, SIGNAL(timeout()), gameScene, SLOT(updating()));

                emit sizeForGame();
                emit start();
            }
            else if (event->scenePos().y() < 60 && event->scenePos().y() > 30)
            {
                gameScene3->restart(1920, 1080);
                view->setScene(gameScene3);
                QObject::connect(timer, SIGNAL(timeout()), gameScene3, SLOT(updating()));

                emit sizeForGame();
                emit start();
            }
        }
    }
}

void Menu::returnToMenu()
{
    if (gameScene->clots.empty())
        QObject::disconnect(timer, SIGNAL(timeout()), gameScene, SLOT(updating()));
    if (gameScene2->clots.empty())
        QObject::disconnect(timer, SIGNAL(timeout()), gameScene2, SLOT(updating()));
    if (gameScene3->clots.empty())
        QObject::disconnect(timer, SIGNAL(timeout()), gameScene3, SLOT(updating()));

    view->setScene(this);
}

void Menu::outputWin(int number)
{
    yWin->setNumber(number);
    view->setScene(yWin);
}

void Menu::outputLose(int number)
{
    yLose->setNumber(number);
    view->setScene(yLose);
}

void Menu::restartLevel(int number)
{
    switch (number)
    {
    case 1:
        gameScene->restart(1920, 1080);
        view->setScene(gameScene);
        QObject::disconnect(timer, SIGNAL(timeout()), gameScene3, SLOT(updating()));
        QObject::connect(timer, SIGNAL(timeout()), gameScene, SLOT(updating()));
        emit sizeForGame();
        emit start();
        break;
    case 2:
        gameScene2->restart(1920, 1080);
        view->setScene(gameScene2);
        QObject::disconnect(timer, SIGNAL(timeout()), gameScene, SLOT(updating()));
        QObject::connect(timer, SIGNAL(timeout()), gameScene2, SLOT(updating()));
        emit sizeForGame();
        emit start();
        break;
    case 3:
        gameScene3->restart(1920, 1080);
        view->setScene(gameScene3);
        QObject::disconnect(timer, SIGNAL(timeout()), gameScene2, SLOT(updating()));
        QObject::connect(timer, SIGNAL(timeout()), gameScene3, SLOT(updating()));
        emit sizeForGame();
        emit start();
        break;
    }
}



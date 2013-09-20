#pragma once
#include "scene.h"
#include "sceneb.h"
#include "sceneblhole.h"
#include "view.h"
#include "youwin.h"
#include "youlose.h"
#include <QGraphicsScene>
#include "QGraphicsSceneEvent"
#include <QTimer>


class Menu : public QGraphicsScene
{
    Q_OBJECT
public:
    Menu(View *v, Scene *s, SceneB *s2, SceneBlHole *s3, QTimer *t, YouWin *w, YouLose *l);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    View *view;
    Scene *gameScene;
    SceneB *gameScene2;
    SceneBlHole *gameScene3;
    YouWin *yWin;
    YouLose *yLose;
    QTimer *timer;
public slots:
    void returnToMenu();
    void outputWin(int number);
    void outputLose(int number);
    void restartLevel(int number);

signals:
    void start();
    void stop();
    void sizeForGame();
};

#pragma once
#include <QGraphicsScene>
#include "playerclot.h"
#include "botclot.h"
#include "normalclot.h"
#include "QGraphicsSceneEvent"

class SceneB : public QGraphicsScene
{
    Q_OBJECT
public:
    void restart(qreal w, qreal h);
    PlayerClot *player;
    QList<NormalClot *> clots;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    void checkForCollisions();
    void updateColor();
    void isWin();
    void clear();
    qreal win;
    bool FindObject;
signals:
    void stop();
    void youWin(int);
    void youLose(int);
public slots:
    void updating();

};

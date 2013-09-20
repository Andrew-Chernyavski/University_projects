#pragma once

#include <QGraphicsScene>
#include "QGraphicsSceneEvent"

class YouLose : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit YouLose();
    void setNumber(int num);
    
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int number;

signals:
    void toMenu();
    void tryAgain(int);
};


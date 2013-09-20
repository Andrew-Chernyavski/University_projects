#pragma once

#include <QGraphicsScene>
#include "QGraphicsSceneEvent"

class YouWin : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit YouWin();
    void setNumber(int num);
    
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int number;

signals:
    void toMenu();
    void next(int);
};


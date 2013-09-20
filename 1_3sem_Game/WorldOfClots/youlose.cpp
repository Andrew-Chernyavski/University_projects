#include "youlose.h"

YouLose::YouLose()
{
    setSceneRect(-960, -540, 1920, 1080);
    setBackgroundBrush(QPixmap(":/youLose.jpg"));
    //addRect(-560, 132, 400, 194);
    //addRect(268, 135, 284, 208);
}

void YouLose::setNumber(int num)
{
    number = num;
}

void YouLose::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->scenePos().x() > -560 && event->scenePos().x() < -160 && event->scenePos().y() > 132 && event->scenePos().y() < 326)
            emit toMenu();
        if (event->scenePos().x() > 268 && event->scenePos().x() < 552 && event->scenePos().y() > 135 && event->scenePos().y() < 343)
            emit tryAgain(number);
    }
}

#include "youwin.h"

YouWin::YouWin()
{
    setSceneRect(-960, -540, 1920, 1080);
    setBackgroundBrush(QPixmap(":/youWin.jpg"));
    //addRect(-560, 136, 400, 196);
    //addRect(291, 197, 258, 74);
}

void YouWin::setNumber(int num)
{
    number = num;
}

void YouWin::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->scenePos().x() > -560 && event->scenePos().x() < -160 && event->scenePos().y() > 136 && event->scenePos().y() < 332)
            emit toMenu();
        if (event->scenePos().x() > 291 && event->scenePos().x() < 549 && event->scenePos().y() > 197 && event->scenePos().y() < 271)
        {
            if (number + 1 != 4)
                emit next(number + 1);
            else
                emit next(1);
        }
    }
}

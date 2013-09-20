#include "view.h"

View::View(QWidget *parent) :
    QGraphicsView(parent)
{
    zoomActive = true;
    fullScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0 && zoomActive)
        zoomIn();
    else
        zoomOut();
}

void View::scaleView(qreal scaleFactor)
{
    if (zoomActive)
    {
        qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
        if (factor < 0.7 || factor > 4.8)
            return;
        scale(scaleFactor, scaleFactor);
        this->scene()->update();
    }
}

void View::zoomIn()
{
    scaleView(qreal(1.05));
}

void View::zoomOut()
{
    scaleView(1 / qreal(1.05));
}

void View::fullScene()
{
    while (transform().scale(1 / qreal(1.05), 1 / qreal(1.05)).mapRect(QRectF(0, 0, 1, 1)).width() > 0.7)
        scale(1 / qreal(1.05), 1 / qreal(1.05));
    zoomActive = false;
}

void View::normalScene()
{
    zoomActive = true;
    for (int i = 0; i < 8; i++)
        zoomIn();
}

void View::center()
{
    QList<QGraphicsItem *> list = scene()->items();
    for (int i = 0; i < list.size(); i++)
    {
        PlayerClot *player = qgraphicsitem_cast<PlayerClot *>(list[i]);
        if (player)
            centerOn(player);
    }
}

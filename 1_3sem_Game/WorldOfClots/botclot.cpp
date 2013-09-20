#include "botclot.h"
#include "sceneB.h"

void BotClot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColor(255, 0, 0));
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    painter->drawEllipse(- radius, - radius, diametr, diametr);
}

void BotClot::advance(int phase)
{
    NormalClot::advance(phase);
}


QRectF BotClot::boundingRect() const
{
   qreal a = 0.25;
   qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
   qreal diametr = 2 * radius;
   return QRectF(- radius, - radius, diametr + a, diametr + a);
}

int BotClot::type() const
{
    return Type;
}

QPainterPath BotClot::shape() const
{
    QPainterPath path;
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    path.addEllipse(- radius, - radius, diametr, diametr);
    return path;
}

qreal BotClot::getSize()
{
    return NormalClot::getSize();
}

void BotClot::setSize(qreal s)
{
    NormalClot::setSize(s);
}

void BotClot::setTexture(qreal c)
{
    NormalClot::setTexture(c);
}

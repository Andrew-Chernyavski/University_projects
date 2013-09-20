#include "playerclot.h"


static const double Pi = 3.141592653589793;

PlayerClot::PlayerClot(qreal mX, qreal mY) : size(40000), dx(0.00001), dy(0.00001)
{
    texture.setTexture(QPixmap(":/pl_clot.jpg"));
    setPos(mX, mY);
    changeSizeNum = 0;
    valueToChange = 0;
}

void PlayerClot::setDx(qreal t)
{
    dx = t;
}

void PlayerClot::setDy(qreal t)
{
    dy = t;
}

qreal PlayerClot::getDx()
{
    return dx;
}

qreal PlayerClot::getDy()
{
    return dy;
}

qreal PlayerClot::setSizeOfPusk()
{
    qreal tmp = size / 40;
    size = size - tmp;
    return tmp;
}

qreal PlayerClot::getRadius()
{
    return qPow((3 * size) / (4 * Pi), 1.0 / 3);
}

int PlayerClot::type() const
{
    return Type;
}

QRectF PlayerClot::boundingRect() const
{
    qreal a = 0.25;
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    return QRectF(- radius, - radius, diametr + a, diametr + a);
}

void PlayerClot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(texture);
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    painter->drawEllipse(- radius, - radius, diametr, diametr);
}

QPainterPath PlayerClot::shape() const
{
    QPainterPath path;
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    path.addEllipse(- radius, - radius, diametr, diametr);
    return path;
}

qreal PlayerClot::getSize()
{
    return size;
}

void PlayerClot::setSize(qreal s)
{
    size = size + s;
}

void PlayerClot::advance(int phase)
{
    if (!phase)
        return;
    if(changeSizeNum > 0)
    {
        setSize(valueToChange / 5);
        changeSizeNum--;
    }




    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    if ((dx < 0 && x() - radius <= 0) || (dx > 0 && x() + radius >= 1920))
        dx = - dx;
    if ((dy < 0 && y() - radius <= 0) || (dy > 0 && y() + radius >= 1080))
        dy = - dy;
    setPos(x() + dx, y() + dy);
}

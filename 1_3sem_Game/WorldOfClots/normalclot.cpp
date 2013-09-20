#include "normalclot.h"
#include "scene.h"
#include "sceneb.h"
#include "sceneblhole.h"

NormalClot::NormalClot(qreal mX, qreal mY, qreal mSize, qreal mDx, qreal mDy) : size(mSize), dx(mDx), dy(mDy)
{
    setPos(mX, mY);
    changeSizeNum = 0;
    valueToChange = 0;
}

int NormalClot::type() const
{
    return Type;
}

QRectF NormalClot::boundingRect() const
{
   qreal a = 0.25;
   qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
   qreal diametr = 2 * radius;
   return QRectF(- radius, - radius, diametr + a, diametr + a);
}

void NormalClot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(texture);
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    painter->drawEllipse(- radius, - radius, diametr, diametr);
}

QPainterPath NormalClot::shape() const
{
    QPainterPath path;
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    qreal diametr = 2 * radius;
    path.addEllipse(- radius, - radius, diametr, diametr);
    return path;
}

qreal NormalClot::getSize()
{
    return size;
}

void NormalClot::setSize(qreal s)
{
    size = size + s;
}

void NormalClot::setTexture(qreal c)
{
    if (c > size)
    {
        texture.setTexture(QPixmap(":/no_clot2.jpg"));
    }
    else
    {
        texture.setTexture(QPixmap(":/no_clot.jpg"));
    }
}

void NormalClot::advance(int phase)
{
    if (!phase)
        return;

    if(changeSizeNum > 0)
    {
        setSize(valueToChange / 5);
        changeSizeNum--;
    }
    else if (changeSizeNum < 0)
    {
        setSize((-1) * valueToChange / 5);
        changeSizeNum++;
        if (changeSizeNum == 0)
        {
            Scene *s = dynamic_cast<Scene *>(scene());
            SceneB *s1 = dynamic_cast<SceneB *>(scene());
            SceneBlHole *s2 = dynamic_cast<SceneBlHole *>(scene());
            if (s)
            {
                s->removeItem(this);
                s->clots.removeAll(this);
                delete this;
            }
            if (s1)
            {
                SceneB *s1 = dynamic_cast<SceneB *>(scene());
                s1->removeItem(this);
                s1->clots.removeAll(this);
                delete this;
            }
            if (s2)
            {
                SceneBlHole *s2 = dynamic_cast<SceneBlHole *>(scene());
                s2->removeItem(this);
                s2->clots.removeAll(this);
                delete this;
            }
            return;
        }
    }
    qreal radius = qPow((3 * size) / (4 * Pi), 1.0 / 3);
    if ((dx < 0 && x() - radius <= 0) || (dx > 0 && x() + radius >= 1920))
        dx = - dx;
    if ((dy < 0 && y() - radius <= 0) || (dy > 0 && y() + radius >= 1080))
        dy = - dy;
    if (this)
        setPos(x() + dx, y() + dy);
 }

void NormalClot::setDx(qreal t)
{
    dx = t;
}

void NormalClot::setDy(qreal t)
{
    dy = t;
}

qreal NormalClot::getDx()
{
    return dx;
}

qreal NormalClot::getDy()
{
    return dy;
}

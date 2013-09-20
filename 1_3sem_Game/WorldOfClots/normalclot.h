#pragma once
#include "QGraphicsItem"
//#include "scene.h"
#include "QPainter"
#include "qmath.h"

static const double Pi = 3.141592653589793;

class NormalClot : public QGraphicsItem
{
public:
    enum { Type = UserType + 2};
    NormalClot(qreal mX, qreal mY, qreal mSize, qreal mDx, qreal mDy);
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
    qreal getSize();
    void setSize(qreal s);
    void setTexture(qreal c);
    int changeSizeNum;
    qreal valueToChange;
    qreal getDx();
    qreal getDy();
    void setDx(qreal t);
    void setDy(qreal t);

protected:
    void advance(int phase);

    qreal size;
    qreal dx;
    qreal dy;
    QBrush texture;
};

#pragma once
#include "QGraphicsItem"
#include "QPainter"
#include "qmath.h"

class PlayerClot : public QGraphicsItem
{
public:
    enum { Type = UserType + 1};
    PlayerClot(qreal mX, qreal mY);
    void setDx(qreal t);
    void setDy(qreal t);
    qreal getDx();
    qreal getDy();
    qreal setSizeOfPusk();
    qreal getRadius();
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
    qreal getSize();
    void setSize(qreal s);
    int changeSizeNum;
    qreal valueToChange;

protected:
    void advance(int phase);

private:

    qreal size;
    qreal dx;
    qreal dy;
    QBrush texture;
};

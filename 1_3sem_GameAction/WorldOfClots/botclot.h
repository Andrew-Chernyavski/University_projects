#include "normalclot.h"
#pragma once

class BotClot : public NormalClot
{
public:
    enum { Type = UserType + 2};
    BotClot(qreal mX, qreal mY, qreal mSize, qreal mDx, qreal mDy) : NormalClot(mX, mY, mSize, mDx, mDy){}
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
    qreal getSize();
    void setSize(qreal s);
    void setTexture(qreal c);

protected:
    void advance(int phase);
};

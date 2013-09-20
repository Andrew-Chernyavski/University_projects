#pragma once

#include "scene.h"
#include <QGraphicsView>
#include "QMouseEvent"


class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *event);
    void scaleView(qreal scaleFactor);

private:
    bool zoomActive;

public slots:
    void zoomIn();
    void zoomOut();
    void fullScene();
    void normalScene();
    void center();
};


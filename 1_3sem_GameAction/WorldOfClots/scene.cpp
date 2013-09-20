#include "scene.h"

void Scene::restart(qreal w, qreal h)
{
    setSceneRect(0, 0, w - 2, h - 2);
    setBackgroundBrush(QPixmap(":/bg.jpg"));
    player = new PlayerClot(w / 2, h / 2);
    win = player->getSize();
    addItem(player);
    setItemIndexMethod(QGraphicsScene::NoIndex);
    qreal plR = player->getRadius();
    for (int i = 0; i < 40; i++)
    {
        qreal newX = 20 + qrand() % (int(width()) - 40);
        qreal newY = 20 + qrand() % (int(height()) - 40);
        qreal newSize = 10000 + qrand() % 10000;
        qreal r = qPow((3 * newSize) / (4 * Pi), 1.0 / 3);
        if (newX - r < player->x() + plR && newX + r > player->x() - plR && newY + r > player->y() - r && newY + r < player->y() + plR + r)
            i--;
        else
        {
            NormalClot *ball = new NormalClot(newX, newY, newSize,
                                              (qrand() % 50) / 10.0 - 2.5, (qrand() % 50) / 10.0 - 2.5);
            addItem(ball);
            win += newSize;
            clots.push_back(ball);
        }
    }
    updateColor();
    win = win / 2;
}

void Scene::isWin()
{
    if (player && player->getSize() > win)
    {
        clear();
        emit stop();
        emit youWin(1);
    }
    else
    {
        for (int i = 0; i < clots.length(); i++)
        {
            if (clots[i]->getSize() > win && clots[i])
            {
                clear();
                emit stop();
                emit youLose(1);
            }
        }
    }
}

void Scene::clear()
{
    for (int i = 0; i < clots.length(); i++)
    {
        removeItem(clots[i]);
        delete clots[i];
        clots[i] = NULL;
    }
    removeItem(player);
    delete player;
    player = NULL;
    clots.clear();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (player)
    {
        if (event->button() == Qt::LeftButton) // ���������. ��� �������� ����� ������ ����
        {
            qreal rx = event->scenePos().x(); // ���������� x ������� ����
            qreal ry = event->scenePos().y(); // ���������� y ������� ����
            qreal newDx = 0; // �������������� ����� �������� �� x
            qreal newDy = 0; // �������������� ����� �������� �� y
            qreal rDx = player->getDx();
            qreal rDy = player->getDy();
            if (qAbs(rx - player->x()) > qAbs(ry - player->y()) ) // �������� ��������� ����� ��������
            {
                if (rx - player->x() < 0)
                    newDx = 1;
                if (rx - player->x() > 0)
                    newDx = -1;
                if (rx - player->x() == 0)
                    newDx = 0;
                newDy = -(ry - player->y()) / qAbs(rx - player->x());
                player->setDx(newDx + rDx);
                player->setDy(newDy + rDy);
            }
            else
            {
                if (ry - player->y() < 0)
                    newDy = 1;
                if (ry - player->y() > 0)
                 newDy = -1;
                if (ry - player->y() == 0)
                    newDy = 0;
                newDx = -(rx - player->x()) / qAbs(ry - player->y());
                player->setDx(newDx + rDx);
                player->setDy(newDy + rDy);
            } // ����� ��������� ��������� ����� ��������
            qreal newSize = player->setSizeOfPusk(); // �������� ����� ������������ �������, � ����� ���������� ��� �� ����� �� ������� - ������
            qreal r = qSqrt(newSize / Pi); // ������ ������������ �������
            qreal R = player->getRadius(); // ������ �������-������ ��� ��� ����� ����������� �����
            qreal a = qSqrt(qPow(rx - player->x(), 2) + qPow(ry - player->y(), 2)); // ���������� ��������� ������������ �������
            qreal newX = rx - ((a - R - r) * (rx - player->x())) / a;
            qreal newY = ry - ((a - R - r) * (ry - player->y())) / a;
            NormalClot *ball = new NormalClot(newX, newY, newSize, /*newDx/qAbs(newDx)*/ /***/ -(newDx*20 + rDx), /*newDy/qAbs(newDy) */ -(newDy*20 + rDy)); // �������� ������������ �������
            addItem(ball); // ���������� ��� �� �����
            clots.push_back(ball);
            updateColor();
        }
    }
}

void Scene::checkForCollisions()
{
    NormalClot *ball;
    for (int i = 0; i < clots.length() - 1; i++)
    {
        QList<QGraphicsItem *> col = collidingItems(clots[i]);
        for (int j = 0; j < col.length(); j++)
        {
            ball = qgraphicsitem_cast<NormalClot *>(col[j]);
            if (ball && clots[i]->changeSizeNum == 0 && ball->changeSizeNum == 0)
            {
                if (clots[i]->getSize() > ball->getSize())
                {
                    clots[i]->valueToChange = ball->getSize();
                    ball->valueToChange = ball->getSize();
                    clots[i]->changeSizeNum = 6;
                    ball->changeSizeNum = -6;
                    qreal newDx = (clots[i]->getSize() * clots[i]->getDx() + ball->getSize() * ball->getDx()) / (clots[i]->getSize() + ball->getSize());
                    qreal newDy = (clots[i]->getSize() * clots[i]->getDy() + ball->getSize() * ball->getDy()) / (clots[i]->getSize() + ball->getSize());
                    clots[i]->setDx(newDx);
                    clots[i]->setDy(newDy);
                    ball->setDx(newDx);
                    ball->setDy(newDy);
                    clots[i]->setTexture(player->getSize());
                    //qreal k = clots[i]->getSize() /
                    //clots[i]->setSize(ball->getSize());
                    //removeItem(ball);
                    //clots.removeAll(ball);
                    //delete ball;
                }
                else {
                    ball->valueToChange = clots[i]->getSize();
                    clots[i]->valueToChange = clots[i]->getSize();
                    clots[i]->changeSizeNum = -6;
                    ball->changeSizeNum = 6;
                    qreal newDx = (clots[i]->getSize() * clots[i]->getDx() + ball->getSize() * ball->getDx()) / (clots[i]->getSize() + ball->getSize());
                    qreal newDy = (clots[i]->getSize() * clots[i]->getDy() + ball->getSize() * ball->getDy()) / (clots[i]->getSize() + ball->getSize());
                    ball->setDx(newDx);
                    ball->setDy(newDy);
                    clots[i]->setDx(newDx);
                    clots[i]->setDy(newDy);
                    ball->setTexture(player->getSize());
                    //ball->setSize(clots[i]->getSize());
                    //removeItem(clots[i]);
                    //delete clots[i];
                    //clots.removeAt(i);
                }
            }
        }
    }
    QList<QGraphicsItem *> col = collidingItems(player);
    for (int i = 0; i < col.length(); i++)
    {
        ball = qgraphicsitem_cast<NormalClot *>(col[i]);
        if (ball && player->changeSizeNum == 0 && ball->changeSizeNum == 0)
        {
            if (player->getSize() > ball->getSize())
            {
                player->valueToChange = ball->getSize();
                ball->valueToChange = ball->getSize();
                player->changeSizeNum = 6;
                ball->changeSizeNum = -6;
                qreal newDx = (player->getSize() * player->getDx() + ball->getSize() * ball->getDx()) / (player->getSize() + ball->getSize());
                qreal newDy = (player->getSize() * player->getDy() + ball->getSize() * ball->getDy()) / (player->getSize() + ball->getSize());
                player->setDx(newDx);
                player->setDy(newDy);
                ball->setDx(newDx);
                ball->setDy(newDy);
                updateColor();
                //player->setSize(ball->getSize());
                //removeItem(ball);
                //clots.removeAll(ball);
                //delete ball;
            }
            else
            {
                clear();
                emit stop();
                emit youLose(1);
            }
        }
    }
}

void Scene::updateColor()
{
    for (int i = 0; i < clots.length(); i++)
    {
        if (player && clots[i])
            clots[i]->setTexture(player->getSize());
    }
}

void Scene::updating()
{
    //if (!play)
    //    return;
    advance();
    checkForCollisions();
    //
    updateColor();
    isWin();
}

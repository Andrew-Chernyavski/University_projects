#include "sceneb.h"

void SceneB::restart(qreal w, qreal h)
{
    setSceneRect(0, 0, w - 2, h - 2);
    setBackgroundBrush(QPixmap(":/bg.jpg"));
    player = new PlayerClot(w / 2, h / 2);
    win = player->getSize();
    addItem(player);
    setItemIndexMethod(QGraphicsScene::NoIndex);
    for (int i = 0; i < 30; i++)
    {
        qreal newSize = 1000 + qrand() % 24000;
        NormalClot *ball = new NormalClot(20 + qrand() % int(width()) - 40, 20 + qrand() % int(height()) - 40, newSize,
                                          (qrand() % 10) / 10.0 + 0.00001, (qrand() % 10) / 10.0 + 0.00001);
        addItem(ball);
        win += newSize;
        clots.push_back(ball);
    }

    BotClot *bot = new BotClot(w / 2, 100, 5000, 1, 2);
    win += 2500;
    addItem(bot);
    clots.push_back(bot);

    win = win / 2;
}

void SceneB::isWin()
{
    if (player && player->getSize() > win)
    {
        clear();
        emit stop();
        youWin(2);
    }
    else
    {
        for (int i = 0; i < clots.length(); i++)
        {
            if (clots[i]->getSize() > win && clots[i])
            {
                clear();
                emit stop();
                emit youLose(2);
            }
        }
    }
}

void SceneB::clear()
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

void SceneB::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (player)
    {
        if (event->button() == Qt::LeftButton) // проверяем. что нажалась левая кнопка мыши
        {
            qreal rx = event->scenePos().x(); // координата x нажатия мыши
            qreal ry = event->scenePos().y(); // координата y нажатия мыши
            qreal newDx = 0; // инициализируем новую скорость по x
            qreal newDy = 0; // инициализируем новую скорость по y
            qreal rDx = player->getDx();
            qreal rDy = player->getDy();
            if (qAbs(rx - player->x()) > qAbs(ry - player->y()) ) // алгоритм задавания новой скорости
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
            } // конец алгоритма задавания новой скорости
            qreal newSize = player->setSizeOfPusk(); // получаем массу испускаемого сгустка, а также вычитается эта жа масса из сгустка - игрока
            qreal r = qSqrt(newSize / Pi); // радиус испускаемого сгустка
            qreal R = player->getRadius(); // радиус сгустка-игрока уже без учета испускаемой массы
            qreal a = qSqrt(qPow(rx - player->x(), 2) + qPow(ry - player->y(), 2)); // вычисление координат выпускаемого сгустка
            qreal newX = rx - ((a - R - r) * (rx - player->x())) / a;
            qreal newY = ry - ((a - R - r) * (ry - player->y())) / a;
            NormalClot *ball = new NormalClot(newX, newY, newSize, /*newDx/qAbs(newDx)*/ /***/ -(newDx*20 + rDx), /*newDy/qAbs(newDy) */ -(newDy*20 + rDy)); // создание выпускаемого сгустка
            addItem(ball); // добавление его на сцену
            clots.push_back(ball);
        }
    }
}

void SceneB::checkForCollisions()
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
                //player->setSize(ball->getSize());
                //removeItem(ball);
                //clots.removeAll(ball);
                //delete ball;
            }
            else
            {
                clear();
                emit stop();
                emit youLose(2);
            }
        }
    }
}

void SceneB::updateColor()
{
    for (int i = 0; i < clots.length(); i++)
    {
        if (player && clots[i])
            clots[i]->setTexture(player->getSize());
    }
    isWin();
}

void SceneB::updating()
{
    advance();
    checkForCollisions();
    updateColor();
    isWin();
}

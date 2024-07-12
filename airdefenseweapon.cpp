#include "airdefenseweapon.h"

AirDefenseWeapon::AirDefenseWeapon() {
    this->price = 10;
<<<<<<< HEAD
    this->maximumcount = 2;
    qDebug()<<QPixmap(":/weapons/images/air_defence.png").rect();
    line1 = new QGraphicsRectItem(0, 0, 400, 40);
    line2 = new QGraphicsRectItem(0, 40, 400, 40);

    QBrush brush(Qt::red, Qt::DiagCrossPattern);
    line1->setBrush(brush);
    line2->setBrush(brush);

    addToGroup(line1);
    addToGroup(line2);

    setHandlesChildEvents(false); // Ensure that events are handled by the group
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

=======
    this->maximumcount = 3;
    qDebug()<<QPixmap(":/weapons/images/air_defence.png").rect();
    setPixmap(QPixmap(":/weapons/images/air_defence.png"));
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
}

void AirDefenseWeapon::shoot()
{
    qDebug()<<"use airdefense";
}
<<<<<<< HEAD

void AirDefenseWeapon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItemGroup::mouseReleaseEvent(event);
    snapToGrid();
}

void AirDefenseWeapon::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItemGroup::mouseMoveEvent(event);
}

void AirDefenseWeapon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItemGroup::mousePressEvent(event);
    originalPos = pos();
}

void AirDefenseWeapon::snapToGrid()
{
    qreal x = 0; // Keep lines horizontal
    qreal y = qRound(pos().y() / 40) * 40;

    // Boundary checks
    if (y < 0) y = 0;
    if (y > 400 - 2 * line1->rect().height()) y = 400 - 2 * line1->rect().height();

    if (canPlaceAt(x, y)) {
        setPos(x, y);
    } else {
        setPos(originalPos);
    }
}

bool AirDefenseWeapon::canPlaceAt(qreal x, qreal y)
{
    qreal width = 400;
    qreal height = 2 * line1->rect().height();
    QRectF newRect = QRectF(x, y, width, height).adjusted(10,10,-10,-10);
    for (auto item : scene()->items(newRect)) {
        if (item == this) continue;
        if (dynamic_cast<AirDefenseWeapon*>(item)) return false;
    }
    return true;
}
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953

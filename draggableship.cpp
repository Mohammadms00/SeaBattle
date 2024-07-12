#include "draggableship.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>
#include <cmath>

DraggableShip::DraggableShip(int width, int height)
    : QGraphicsRectItem(0, 0, width, height), originalSize(width, height), isVertical(false) {
    setBrush(QBrush(Qt::blue));
    setDragablity(true);
}

QRect DraggableShip::getArrayRect()
{
    return arrayrect;
}

void DraggableShip::setDragablity(bool dragbility)
{
    setFlag(QGraphicsItem::ItemIsMovable, dragbility);
    setFlag(QGraphicsItem::ItemIsSelectable, dragbility);
}


QRectF DraggableShip::boundingRect() const {
    qreal extra = 1;
    return QRectF(rect().x() - extra, rect().y() - extra, rect().width() + 2 * extra, rect().height() + 2 * extra);
}

void DraggableShip::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsRectItem::mouseReleaseEvent(event);
    snapToGrid();
}

void DraggableShip::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        rotateShip();
    } else {
        QGraphicsRectItem::mousePressEvent(event);
        originalPos = pos();
    }
}

void DraggableShip::snapToGrid() {
    qreal x = qRound(pos().x() / 40) * 40;
    qreal y = qRound(pos().y() / 40) * 40;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > 400 - rect().width()) x = 400 - rect().width();
    if (y > 400 - rect().height()) y = 400 - rect().height();

    if (canPlaceAt(x, y)) {
        setPos(x, y);

        arrayrect.setX(x / 40);
        arrayrect.setY(y / 40);
        arrayrect.setWidth(rect().width()/40);
        arrayrect.setHeight(rect().height()/40);
    } else {
        setPos(originalPos);
    }
}

void DraggableShip::rotateShip() {
    QPointF oldPos = pos();
    QSizeF oldSize = rect().size();
    qreal newWidth = oldSize.height();
    qreal newHeight = oldSize.width();
    QRectF newRect(0, 0, newWidth, newHeight);

    QPointF newPos[4] = {
        oldPos,
        oldPos + QPointF(0, -newHeight + oldSize.height()),
        oldPos + QPointF(-newWidth + oldSize.width(), 0),
        oldPos + QPointF(-newWidth + oldSize.width(), -newHeight + oldSize.height())
    };

    for (const auto &pos : newPos) {
        qreal x = qRound(pos.x() / 40) * 40;
        qreal y = qRound(pos.y() / 40) * 40;

        if (x + newWidth > 400) x = 400 - newWidth;
        if (y + newHeight > 400) y = 400 - newHeight;
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        if (canPlaceAt(x, y, newWidth, newHeight)) {
            setRect(newRect);
            setPos(x, y);
            isVertical = !isVertical;
            return;
        }
    }

    setRect(QRectF(0, 0, oldSize.width(), oldSize.height()));
}

bool DraggableShip::canPlaceAt(qreal x, qreal y, qreal width, qreal height) {
    QRectF newRect = QRectF(x, y, width, height).adjusted(-20, -20, 20, 20);
    for (auto item : scene()->items(newRect)) {
        if (item == this) continue;
        if (dynamic_cast<DraggableShip*>(item)) return false;
    }
    return true;
}

bool DraggableShip::canPlaceAt(qreal x, qreal y) {
    return canPlaceAt(x, y, rect().width(), rect().height());
}

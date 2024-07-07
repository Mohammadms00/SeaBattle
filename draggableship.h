#ifndef DRAGGABLESHIP_H
#define DRAGGABLESHIP_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QSizeF>
#include <QGraphicsScene>

class DraggableShip : public QGraphicsRectItem {
public:
    DraggableShip(int width, int height);
    QRectF boundingRect() const override;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPointF originalPos;
    QSizeF originalSize;
    bool isVertical;

    void snapToGrid();
    void rotateShip();
    bool canPlaceAt(qreal x, qreal y, qreal width, qreal height);
    bool canPlaceAt(qreal x, qreal y);
};

#endif // DRAGGABLESHIP_H

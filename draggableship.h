#ifndef DRAGGABLESHIP_H
#define DRAGGABLESHIP_H

#include <QGraphicsRectItem>
#include <QSizeF>
#include <QPointF>

class DraggableShip : public QGraphicsRectItem {
public:
    DraggableShip(int width, int height);

    QRectF boundingRect() const override;
    QRect getArrayRect();
    void setDragablity(bool dragbility);
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPointF originalPos;
    QSizeF originalSize;
    QRect arrayrect;
    bool isVertical;

    void snapToGrid();
    void rotateShip();
    bool canPlaceAt(qreal x, qreal y, qreal width, qreal height);
    bool canPlaceAt(qreal x, qreal y);
};

#endif // DRAGGABLESHIP_H

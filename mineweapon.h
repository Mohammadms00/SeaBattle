#ifndef MINEWEAPON_H
#define MINEWEAPON_H

#include "weapon.h"
#include "draggableship.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>
#include <cmath>
class MineWeapon : public Weapon,public QGraphicsRectItem
{
public:
    MineWeapon();
    QRectF boundingRect() const override;
    void shoot() override;
    QRect getArrayRect();

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPointF originalPos;
    QSizeF originalSize;
    QRect arrayrect;
    bool canPlaceAt(qreal x, qreal y, qreal width, qreal height);
    bool canPlaceAt(qreal x, qreal y);
    void snapToGrid();

    QPixmap pixmap;
};

#endif // MINEWEAPON_H

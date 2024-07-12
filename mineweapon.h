#ifndef MINEWEAPON_H
#define MINEWEAPON_H

#include "weapon.h"
#include "draggableship.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>
#include <cmath>
<<<<<<< HEAD
class MineWeapon : public Weapon,public QGraphicsRectItem
{
public:
    MineWeapon();
    QRectF boundingRect() const override;
    void shoot() override;
    QRect getArrayRect();

=======
class MineWeapon : public Weapon
{
public:
    MineWeapon();
    void shoot() override;
    QRect getArrayRect();
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
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
<<<<<<< HEAD

    QPixmap pixmap;
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
};

#endif // MINEWEAPON_H

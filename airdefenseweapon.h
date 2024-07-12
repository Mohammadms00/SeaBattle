#ifndef AIRDEFENSEWEAPON_H
#define AIRDEFENSEWEAPON_H

#include "weapon.h"
<<<<<<< HEAD
#include <QGraphicsItemGroup>
#include <QGraphicsScene>

class AirDefenseWeapon : public QGraphicsItemGroup,public Weapon
=======

class AirDefenseWeapon : public Weapon
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
{
public:
    AirDefenseWeapon();
    void shoot() override;
<<<<<<< HEAD
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QGraphicsRectItem *line1;
    QGraphicsRectItem *line2;
    QPointF originalPos;
    void snapToGrid();
    bool canPlaceAt(qreal x, qreal y);
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
};

#endif // AIRDEFENSEWEAPON_H

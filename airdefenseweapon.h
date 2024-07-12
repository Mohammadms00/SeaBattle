#ifndef AIRDEFENSEWEAPON_H
#define AIRDEFENSEWEAPON_H

#include "weapon.h"
#include <QGraphicsItemGroup>
#include <QGraphicsScene>

class AirDefenseWeapon : public QGraphicsItemGroup,public Weapon
{
public:
    AirDefenseWeapon();
    void shoot() override;
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
};

#endif // AIRDEFENSEWEAPON_H

#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QSizeF>
#include <QPointF>
#include <QBrush>
#include <QPixmap>
class Weapon
{
public:
    Weapon();
    int getPrice();
    int getMax();
    virtual void shoot() = 0;
protected:
    int price;
    int maximumcount;




};

#endif // WEAPON_H

#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QSizeF>
#include <QPointF>
#include <QBrush>
#include <QPixmap>
<<<<<<< HEAD
class Weapon
{
public:
    Weapon();
=======
class Weapon : public QGraphicsRectItem
{
public:
    Weapon();
    QRectF boundingRect() const override;
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
    int getPrice();
    int getMax();
    virtual void shoot() = 0;
protected:
<<<<<<< HEAD
    int price;
    int maximumcount;


=======

    void setPixmap(QPixmap pixmap);
    int price;
    int maximumcount;
private:

    QPixmap pixmap;
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953


};

#endif // WEAPON_H

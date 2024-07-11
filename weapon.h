#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QSizeF>
#include <QPointF>
#include <QBrush>
#include <QPixmap>
class Weapon : public QGraphicsRectItem
{
public:
    Weapon();
    QRectF boundingRect() const override;
    int getPrice();
    int getMax();
    virtual void shoot() = 0;
protected:

    void setPixmap(QPixmap pixmap);
    int price;
    int maximumcount;
private:

    QPixmap pixmap;


};

#endif // WEAPON_H

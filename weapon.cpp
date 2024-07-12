#include "weapon.h"

<<<<<<< HEAD
Weapon::Weapon(){
=======
Weapon::Weapon()
    : QGraphicsRectItem(0, 0, 40, 40) {
    qDebug()<<pixmap.rect();
    setBrush(QBrush(Qt::red));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
}

int Weapon::getPrice()
{
    return price;
}

int Weapon::getMax()
{
    return maximumcount;
}


<<<<<<< HEAD



=======
QRectF Weapon::boundingRect() const {
    qreal extra = 1;
    return QRectF(rect().x() - extra, rect().y() - extra, rect().width() + 2 * extra, rect().height() + 2 * extra);
}



void Weapon::setPixmap(QPixmap pixmap)
{
    this->pixmap = pixmap;
    this->pixmap.scaled(QSize(40,40));
    setBrush(QBrush(this->pixmap));
}


>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953


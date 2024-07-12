#include "mineweapon.h"

<<<<<<< HEAD
MineWeapon::MineWeapon() : QGraphicsRectItem(0, 0, 40, 40),originalSize(40, 40) {
    this->price = 5;
    this->maximumcount = 5;
    this->pixmap = QPixmap(":/weapons/images/mine.png");

    this->pixmap.scaled(QSize(40,40));
    setBrush(QBrush(this->pixmap));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    // setBrush(Qt::red);
}

QRectF MineWeapon::boundingRect() const
{
    qreal extra = 1;
    return QRectF(rect().x() - extra, rect().y() - extra, rect().width() + 2 * extra, rect().height() + 2 * extra);
=======
MineWeapon::MineWeapon() : originalSize(40, 40){
    this->price = 5;
    this->maximumcount = 5;
    qDebug()<<QPixmap(":/weapons/images/mine.png").rect();
    setPixmap(QPixmap(":/weapons/images/mine.png"));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setBrush(QBrush(Qt::red));
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
}

void MineWeapon::shoot()
{
    qDebug()<<"use mine";
}
QRect MineWeapon::getArrayRect()
{
    return arrayrect;
}

bool MineWeapon::canPlaceAt(qreal x, qreal y, qreal width, qreal height) {
    QRectF newRect = QRectF(x, y, width, height).adjusted(10,10,-10,-10);
    for (auto item : scene()->items(newRect)) {
        if (item == this) continue;
        if (dynamic_cast<DraggableShip*>(item)) return false;
        if (dynamic_cast<Weapon*>(item)) return false;
    }
    return true;
}

bool MineWeapon::canPlaceAt(qreal x, qreal y) {
    return canPlaceAt(x, y, rect().width(), rect().height());
}

void MineWeapon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsRectItem::mouseReleaseEvent(event);
    snapToGrid();
}

void MineWeapon::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsRectItem::mousePressEvent(event);
    originalPos = pos();

}

void MineWeapon::snapToGrid() {
    qreal x = qRound(pos().x() / 40) * 40;
    qreal y = qRound(pos().y() / 40) * 40;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > 400 - rect().width()) x = 400 - rect().width();
    if (y > 400 - rect().height()) y = 400 - rect().height();

    if (canPlaceAt(x, y)) {
        setPos(x, y);

        arrayrect.setX(x / 40);
        arrayrect.setY(y / 40);
        arrayrect.setWidth(rect().width()/40);
        arrayrect.setHeight(rect().height()/40);
    } else {
        setPos(originalPos);
    }
}

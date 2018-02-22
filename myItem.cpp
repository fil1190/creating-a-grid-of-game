#include "myItem.h"

MyItem::MyItem()
{
    Pressed = 0;
    setFlag(ItemIsMovable);
}

QRectF MyItem::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,500,500);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPolygonF pol;
    QPointF point, center(250, 250);
    float angle, size = 200;
    const float PI = 355.0/113.0;

    for(int i=0; i < 6; ++i)
    {
        angle = PI/180 * (60*i + 30);
        point.setX(center.x() + size * cos(angle));
        point.setY(center.y() + size * sin(angle));
        pol.push_back(point);
    }
    if(Pressed == 1)
    {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
        painter->drawRect(rect);
//        painter->drawEllipse(rect);
    }
    else if (Pressed == 2)
    {
        QPen pen(Qt::green, 3);
        painter->setPen(pen);
        painter->drawRect(rect);
    }
    else
    {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawConvexPolygon(pol);

    }
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = 1;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = 0;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = 2;
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

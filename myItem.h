#ifndef MYITEM_H
#define MYITEM_H

#include <QPainter>
#include <QGraphicsItem>

class MyItem: public QGraphicsItem
{
public:
    MyItem();

    QRectF boundingRect() const;

//    overriding paint()
    void paint (QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget);
    // item state
    int Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYITEM_H

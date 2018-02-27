#ifndef GRIDITEM_H
#define GRIDITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <IGridCell.h>
#include <QWidget>

//*************************************************************
// ПАТТЕРН "СОСТОЯНИЕ"
//*************************************************************

class GridItem: public QWidget, public QGraphicsItem
{
   Q_OBJECT
public:
    explicit GridItem(IGridCell *pointer,
                      const ServiceDataForGridCell& serviceData,
                      QWidget *parent = 0);
    GridItem(const GridItem& other) = delete;
    GridItem& operator = (const GridItem& other) = delete;
    ~GridItem(){delete _pGridCell;}

    QRectF boundingRect() const;
    //    overriding paint()
    void paint (QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget);

    inline void setCoordinatesOfCell(QPoint coord){
        _pGridCell->setCoordinatesOfCell(coord);
    }

private:
    IGridCell *_pGridCell;
    QSizeF _cellSize;
    QPointF _coordOfCenter;
    QVector <float> _edgeSize;
};

#endif // GRIDITEM_H

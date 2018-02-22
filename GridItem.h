#ifndef GRIDITEM_H
#define GRIDITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <IGridCell.h>

//*************************************************************
// ПАТТЕРН "СОСТОЯНИЕ"
//*************************************************************

class GridItem: public QGraphicsItem
{
public:
    explicit GridItem(IGridCell * pointer, const ServiceDataForGridCell& serviceData);
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
//    inline void setServiceData (const ServiceDataForGridCell &servData){
//        _pGridCell->setServiceData(servData);
//    }

private:
    IGridCell *_pGridCell;
    QSizeF _cellSize;
    QPointF _coordOfCenter;
    QVector <float> _edgeSize;
};

#endif // GRIDITEM_H

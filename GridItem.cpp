#include "GridItem.h"
#include <QVector>

GridItem::GridItem(IGridCell *pointer, const ServiceDataForGridCell &serviceData):
    _cellSize(serviceData.cellSize)
{
    _pGridCell = pointer;
    _coordOfCenter = serviceData.coordinatesOfCenter;

//    ServiceDataForGridCell servData = _pGridCell->calculateServiceData(cellSize, 1, 2);
    _pGridCell->setServiceData(serviceData);
//    _pGridCell->setEdgesSize(servData.edges);
//    _pGridCell->setCoordinatesForCenter(QPointF (servData.cellSize.width/2.0, servData.cellSize.height/2.0));
}

QRectF GridItem::boundingRect() const
{
    // outer most edges
//    return QRectF(/*_coordOfCenter.x()*/00, _coordOfCenter.y(), _cellSize.width(), _cellSize.height());
    return QRectF(/*QPointF(0,0)*/_coordOfCenter, _cellSize);
}

void GridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen(Qt::red, 3);
    painter->setPen(pen);
//    painter->drawLines(_pGridCell->calculateCoordinatesForVerticesOfPolygon());
    painter->drawConvexPolygon(_pGridCell->calculateCoordinatesForVerticesOfPolygon());

//    QPolygonF pol;
//    QPointF t0(0,0);
//    QPointF t1(_cellSize.width(),0);
//    QPointF t2(_cellSize.width(),_cellSize.height());
//    QPointF t3(0,_cellSize.height());
//    pol.push_back(t0);
//    pol.push_back(t1);
//    pol.push_back(t2);
//    pol.push_back(t3);

//    QPen pen2(Qt::blue, 1);
//    painter->setPen(pen2);
//    painter->drawConvexPolygon(pol);
}

#include "GridItem.h"
#include <QVector>

GridItem::GridItem(IGridCell *pointer, const ServiceDataForGridCell &serviceData):
    _cellSize(serviceData.cellSize),
    _edgeSize(serviceData.edgesSize),
    _coordOfCenter(serviceData.coordinatesOfCenter),
    _pGridCell(pointer)
{
//    _pGridCell = pointer;
//    _coordOfCenter = serviceData.coordinatesOfCenter;

//    ServiceDataForGridCell servData = _pGridCell->calculateServiceData(cellSize, 1, 2);
//    _pGridCell->setServiceData(serviceData);
//    _pGridCell->setEdgesSize(servData.edges);
//    _pGridCell->setCoordinatesForCenter(QPointF (servData.cellSize.width/2.0, servData.cellSize.height/2.0));
}

QRectF GridItem::boundingRect() const
{
    return QRectF(_coordOfCenter, _cellSize);
}

void GridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen(Qt::red, 3);
    painter->setPen(pen);
    painter->drawConvexPolygon(_pGridCell->calculateCoordinatesForVerticesOfPolygon(_coordOfCenter,
                                                                                    _edgeSize));
}

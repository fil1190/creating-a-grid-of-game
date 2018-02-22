#include "GridItem.h"
#include <QVector>

GridItem::GridItem(IGridCell *pointer, const ServiceDataForGridCell &serviceData):
    _cellSize(serviceData.cellSize),
    _edgeSize(serviceData.edgesSize),
    _coordOfCenter(serviceData.coordinatesOfCenter),
    _pGridCell(pointer)
{

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

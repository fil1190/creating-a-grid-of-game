#include "GridItem.h"
#include <QVector>
#include <QWidget>

GridItem::GridItem(IGridCell *pointer, const ServiceDataForGridCell &serviceData, QWidget *parent):
    _cellSize(serviceData.cellSize),
    _edgeSize(serviceData.edgesSize),
    _coordOfCenter(serviceData.coordinatesOfCenter),
    _pGridCell(pointer),
    QWidget(parent)
{

}

QRectF GridItem::boundingRect() const
{
    return QRectF(_coordOfCenter, _cellSize);
}

void GridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawConvexPolygon(_pGridCell->calculateCoordinatesForVerticesOfPolygon(_coordOfCenter,
                                                                                    _edgeSize));
}

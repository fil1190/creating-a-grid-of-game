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

    QPoint coordinates = _pGridCell->getCoordinatesOfCell();
    if (coordinates.x() == 0 && coordinates.y() == 0)
        painter->drawConvexPolygon(_pGridCell->calculateCoordinatesForVerticesOfPolygon(_coordOfCenter,
                                                                                    _edgeSize));
    else
        painter->drawLines(_pGridCell->calculateCoordinatesForVerticesOfPolygon(_coordOfCenter,
                                                                               _edgeSize));
}

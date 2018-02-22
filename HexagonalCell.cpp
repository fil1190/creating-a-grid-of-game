#include "HexagonalCell.h"
#include <math.h>


HexagonalCell::HexagonalCell(OrientHexagon orient)
{
    _orientHexagon = (orient);
}

QPolygonF HexagonalCell::calculateCoordinatesForVerticesOfPolygon()
{
    const qreal PI = 355.0/113.0;
    qreal angle;
    QPointF point;
    for (int i=0; i<6; ++i)
    {
        angle = PI/180 * calculateAngleDeg(i);

        if (!_edgeSize.size())
            return _verticesOfPolygon;

        point.setX(_coordinatesOfCenter.x() + _edgeSize.at(0) * cos(angle));
        point.setY(_coordinatesOfCenter.y() + _edgeSize.at(0) * sin(angle));
        _verticesOfPolygon.push_back(point);
//        if(i && i !=(6-1))
//            _verticesOfPolygon.push_back(point);
    }
    return _verticesOfPolygon;
}
    qreal HexagonalCell::calculateAngleDeg(const int numberAngle){
        float angle = 60 * numberAngle;
        switch (_orientHexagon)
        {
        case OrientHexagon::pointy_topped:
            return angle + 30;
            break;
        case OrientHexagon::flat_topped:
            return angle;
            break;
        default:
            return angle;
        }
    }

ServiceDataForGridCell HexagonalCell::calculateServiceData(const QSizeF& sceneSize,
                                             int numberOfCellsAtColumn,
                                             int numberOfCellsAtRow) {
    ServiceDataForGridCell serviceData;
    serviceData = calculateEdgeForPointyTopped(sceneSize,
                                               numberOfCellsAtColumn,
                                               numberOfCellsAtRow);

// fix me!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    _coordinatesOfCenter.setX((serviceData.biasFromCenter.inWidth/2.0));
//    _coordinatesOfCenter.setY(serviceData.biasFromCenter.inHeight*2.0/3.0);
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return serviceData;
}
    ServiceDataForGridCell HexagonalCell::calculateEdgeForPointyTopped(const QSizeF& sceneSize,
                                                                       int numberOfCellsAtColumn,
                                                                       int numberOfCellsAtRow)const{
        ServiceDataForGridCell serviceData;
        QSizeF cellSize;
        cellSize.setHeight((numberOfCellsAtColumn == 1)? sceneSize.height() :
                                                      (sceneSize.height()*4.0)/(qreal)(numberOfCellsAtColumn*3 + 1.0));
        if (numberOfCellsAtColumn > 1)
            cellSize.setWidth((numberOfCellsAtRow == 1)? sceneSize.width() :
                                                      sceneSize.width()/((qreal)numberOfCellsAtRow + 0.5));
        else
            cellSize.setWidth((numberOfCellsAtRow == 1)? sceneSize.width() :
                                                      sceneSize.width()/((qreal)numberOfCellsAtRow));

        float edgeSize1, edgeSize2;
        edgeSize1 = cellSize.height()/ 2;
        edgeSize2 = cellSize.width()/sqrt(3);
        if (serviceData.edgesSize.size())
            serviceData.edgesSize.clear();
        serviceData.edgesSize.push_back(calculateMinEdge(edgeSize1, edgeSize2));
        serviceData.biasFromCenter.inHeight = serviceData.edgesSize.at(0) * 3.0/2.0;
        serviceData.biasFromCenter.inWidth = serviceData.edgesSize.at(0) * sqrt(3);
        serviceData.cellSize.setHeight(serviceData.edgesSize.at(0) * 2);
        serviceData.cellSize.setWidth(serviceData.biasFromCenter.inWidth);
        return serviceData;
    }

        float HexagonalCell::calculateMinEdge(float a, float b) const{
            if (a < b)
                return a;
            else
                return b;
        }

#include "HexagonalCell.h"
#include <math.h>

HexagonalCell::HexagonalCell(OrientHexagon orient)
{
    _orientHexagon = (orient);
}

QPolygonF HexagonalCell::calculateCoordinatesForVerticesOfPolygon(const QPointF& coordinatesOfCenter,
                                                                  const QVector<float> edgeSize)
{
    static const qreal PI = 355.0/113.0;
    static qreal angle;
    static QPointF point;
    static QPolygonF verticesOfPolygon;


    verticesOfPolygon.clear();
    determiningCellType();

    for (int i=0; i < _namberOfVertices; ++i)
    {
        angle = PI/180 * calculateAngleDeg(i);

        if (!edgeSize.size())
            return verticesOfPolygon;

        point.setX(coordinatesOfCenter.x() + edgeSize.at(0) * cos(angle));
        point.setY(coordinatesOfCenter.y() + edgeSize.at(0) * sin(angle));
        verticesOfPolygon.push_back(point);
        if (_typeOfCell != TypeOfCell::firstCell && i != 0 && i != (_namberOfVertices-1))
            verticesOfPolygon.push_back(point);
    }
    return verticesOfPolygon;
}
    qreal HexagonalCell::calculateAngleDeg(const int numberAngle){
        float angle = 60 * numberAngle;
        switch (_typeOfCell)
        {
        case TypeOfCell::firstCell:
        case TypeOfCell::firstCellInColumn:
            return angle - 150;
            break;
        case TypeOfCell::firstCellInRowEven:
            return angle - 30;
            break;
        case TypeOfCell::firstCellInRowOdd:
            return angle - 90;
            break;
        case TypeOfCell::ordinaryCell:
            return angle - 90;
            break;
        default:
            return angle;
        }
    }

    void HexagonalCell::determiningCellType()
    {
        if (_coordinatesOfCell.x() == 0 && _coordinatesOfCell.y() == 0)
            _typeOfCell = TypeOfCell::firstCell;
        else if (_coordinatesOfCell.x() == 0)
        {
            _typeOfCell = TypeOfCell::firstCellInColumn;
        }
        else if (_coordinatesOfCell.y() == 0)
        {
            if ((_coordinatesOfCell.x()%2) == 0)
                _typeOfCell = TypeOfCell::firstCellInRowEven;
            else
            {
                _typeOfCell = TypeOfCell::firstCellInRowOdd;
            }
        }
        else
        {
            _typeOfCell = TypeOfCell::ordinaryCell;
            _namberOfVertices = 5;
        }
    }

ServiceDataForGridCell HexagonalCell::calculateServiceData(const QSizeF& sceneSize,
                                             int numberOfCellsAtColumn,
                                             int numberOfCellsAtRow) {
    ServiceDataForGridCell serviceData;
    serviceData = calculateEdgeForPointyTopped(sceneSize,
                                               numberOfCellsAtColumn,
                                               numberOfCellsAtRow);
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
            static int min = 30;
            if (a > min && b > min)
            {
                if (a < b)
                    return a;
                else
                    return b;
            } else
                return min;
        }

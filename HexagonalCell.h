#ifndef HEXAGONALCELL_H
#define HEXAGONALCELL_H

#include "IGridCell.h"

enum class OrientHexagon {
    pointy_topped,
    flat_topped
    };

enum class TypeOfCell{
    firstCell,
    firstCellInRowOdd,
    firstCellInRowEven,
    firstCellInColumn,
    ordinaryCell
};

class HexagonalCell: public IGridCell
{
public:
    HexagonalCell(OrientHexagon orient = OrientHexagon::pointy_topped);

    virtual QPolygonF calculateCoordinatesForVerticesOfPolygon(const QPointF& coordinatesOfCenter,
                                                               const QVector <float> edgeSize);
    ServiceDataForGridCell calculateServiceData(const QSizeF& sceneSize,
                                  int numberOfCellsAtColumn = 1,
                                  int numberOfCellsAtRow = 1);

private:
    OrientHexagon _orientHexagon;
    qreal calculateAngleDeg (const int numberAngle);
    void determiningCellType();
    ServiceDataForGridCell calculateEdgeForPointyTopped (const QSizeF& sceneSize,
                                                          int numberOfCellsAtColumn,
                                                          int numberOfCellsAtRow) const;
    TypeOfCell _typeOfCell;
    int _namberOfVertices{6};
    float calculateMinEdge(float a, float b) const;
};

#endif // HEXAGONALCELL_H

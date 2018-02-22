#ifndef HEXAGONALCELL_H
#define HEXAGONALCELL_H

#include "IGridCell.h"

enum class OrientHexagon {
    pointy_topped,
    flat_topped
    };

class HexagonalCell: public IGridCell
{
public:
    HexagonalCell(OrientHexagon orient = OrientHexagon::pointy_topped);

    virtual QPolygonF calculateCoordinatesForVerticesOfPolygon();
    ServiceDataForGridCell calculateServiceData(const QSizeF& sceneSize,
                                  int numberOfCellsAtColumn = 1,
                                  int numberOfCellsAtRow = 1);

private:
    OrientHexagon _orientHexagon;
    qreal calculateAngleDeg (const int numberAngle);
    ServiceDataForGridCell calculateEdgeForPointyTopped (const QSizeF& sceneSize,
                                                          int numberOfCellsAtColumn,
                                                          int numberOfCellsAtRow) const;
    float calculateMinEdge(float a, float b) const;
};

#endif // HEXAGONALCELL_H

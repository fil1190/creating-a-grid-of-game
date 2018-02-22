#ifndef IGRIDCELL_H
#define IGRIDCELL_H

#include <QPolygonF>
#include <QVector>

struct BiasFromCenter
{
    float inHeight{0};
    float inWidth{0};
    BiasFromCenter(){}
    BiasFromCenter(int width, int height):
        inHeight(height),
        inWidth(width){}
};

struct ServiceDataForGridCell
{
    BiasFromCenter biasFromCenter;
    QVector<float> edgesSize;
    QSizeF cellSize;
    QPointF coordinatesOfCenter;
    QPoint coordinatesOfCell;
};

class IGridCell
{
public:
    IGridCell(){}
    virtual ~IGridCell(){}

    inline QPoint getCoordinatesOfCell() const{
        return _coordinatesOfCell;
    }


    inline void setCoordinatesOfCell(QPoint coord){
        _coordinatesOfCell = coord;
    }

    virtual QPolygonF calculateCoordinatesForVerticesOfPolygon(const QPointF& coordinatesOfCenter,
                                                               const QVector <float> edgeSize) = 0;

    virtual ServiceDataForGridCell calculateServiceData(const QSizeF& sceneSize,
                                          int numberOfCellsAtColumn = 1,
                                          int numberOfCellsAtRow = 1) = 0;

protected:  
    QPointF _coordinatesOfCenter;
    QVector <float> _edgeSize;
    QPoint _coordinatesOfCell;

};

#endif // IGRIDCELL_H

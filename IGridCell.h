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

    inline QPolygonF getVerticesOfPolygon() const {
        return _verticesOfPolygon;
    }

    inline QPointF getCoordinatesOfCenter() const {
        return _coordinatesOfCenter;
    }

    inline QPoint getCoordinatesOfCell() const{
        return _coordinatesOfCell;
    }

    inline void setServiceData (const ServiceDataForGridCell &servData){
        _edgeSize = servData.edgesSize;
        _coordinatesOfCenter = servData.coordinatesOfCenter;
        _coordinatesOfCell = servData.coordinatesOfCell;
    }

    inline void setCoordinatesOfCell(QPoint coord){
        _coordinatesOfCell = coord;
    }

    virtual QPolygonF calculateCoordinatesForVerticesOfPolygon() = 0;
    virtual ServiceDataForGridCell calculateServiceData(const QSizeF& sceneSize,
                                          int numberOfCellsAtColumn = 1,
                                          int numberOfCellsAtRow = 1) = 0;

protected:  
    QPolygonF _verticesOfPolygon;
    QPointF _coordinatesOfCenter;
    QPoint _coordinatesOfCell;
    QVector <float> _edgeSize;
};

#endif // IGRIDCELL_H

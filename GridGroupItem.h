#ifndef GRIDGROUPITEM_H
#define GRIDGROUPITEM_H

#include <QGraphicsItemGroup>
#include <QWidget>
#include <QVector>
#include <QGraphicsView>
#include "GridItem.h"

enum class GridType{
    hexagonOddR,
    hexagonEvenR,
    hexagonOddQ,
    hexagonEvenQ
};

struct InputDataForGridGroup{
    QSizeF sceneSize;
    int numberOfColumns{1};
    int numberOfRows{1};
};

//************************************************************
//      ПАТЕРН СТРАТЕГИЯ
//************************************************************

class GridGroupItem : public QWidget, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    explicit GridGroupItem(InputDataForGridGroup inputData,
                           GridType typeGrid = GridType::hexagonOddR);

    QSizeF getSceneSize()const;

private:
    void creatingGrid();
    QPointF calculateNewCoordinatesForCenter(QPointF &oldCoordinates,
                                             const int numberTheRow,
                                             const int numberTheColumn);

    QPointF centerForHexagonOddR(QPointF& oldCoordinates,
                              const int numberTheRow,
                              const int numberTheColumn);

    void calculateServiceData();
    GridItem *creatingGridCell();
    IGridCell* creatingGridCellForServiceData();


    ServiceDataForGridCell _serviceData;
    QVector<QVector<GridItem *>> _grid;
    GridType _typeGrid;
    QGraphicsView* _graphicsView;
    InputDataForGridGroup _inputData;
};

#endif // GRIDGROUPITEM_H

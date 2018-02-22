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

struct NumberOfCells{
    int inColumn{1};
    int inRow{1};
    NumberOfCells(){}
    NumberOfCells(int column, int row):
        inColumn(column),
        inRow(row){}
};

//************************************************************
//      ПАТЕРН СТРАТЕГИЯ
//************************************************************

class GridGroupItem : public QWidget, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    explicit GridGroupItem(NumberOfCells numberOfCells,
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
    NumberOfCells _numberOfCells;
    QSizeF _sceneSize;
};

#endif // GRIDGROUPITEM_H

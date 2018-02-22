#include "GridGroupItem.h"
#include "HexagonalCell.h"

GridGroupItem::GridGroupItem(InputDataForGridGroup inputData,
                             GridType typeGrid):
    _typeGrid(typeGrid),
    _inputData((inputData))
{
    creatingGrid();
}

QSizeF GridGroupItem::getSceneSize() const
{
    QSize sceneSize;
    sceneSize.setWidth((_serviceData.cellSize.width() * _inputData.numberOfColumns)+0.5*_serviceData.cellSize.width());
    sceneSize.setHeight((_serviceData.cellSize.height()*3.0/4.0 * (_inputData.numberOfRows-1.0))+ _serviceData.cellSize.height());
    return sceneSize;
}


void GridGroupItem::creatingGrid()
{
    QPointF coordinates(0,0);
    QVector <GridItem*> gridLine;

    calculateServiceData();
    for (int i = 0; i < _inputData.numberOfRows; ++i)
    {
        for (int j = 0; j < _inputData.numberOfColumns; ++j)
        {
            _serviceData.coordinatesOfCenter = calculateNewCoordinatesForCenter(coordinates, i, j);
            gridLine.push_back(creatingGridCell());
            this->addToGroup(gridLine.at(j));
            gridLine.at(j)->setCoordinatesOfCell(QPoint(i,j));
        }
        _grid.push_back(gridLine);
        gridLine.clear();
    }
}

QPointF GridGroupItem::calculateNewCoordinatesForCenter(QPointF &oldCoordinates,
                                         const int numberTheRow,
                                         const int numberTheColumn){
    switch(_typeGrid){
    case GridType::hexagonOddR:
        centerForHexagonOddR(oldCoordinates, numberTheRow, numberTheColumn);
        break;
    default:
        //  FEX ME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return oldCoordinates;
        break;
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    return oldCoordinates;
}

QPointF GridGroupItem::centerForHexagonOddR(QPointF &oldCoordinates, const int numberTheRow, const int numberTheColumn)
{
    if (numberTheColumn)
        oldCoordinates.setX(oldCoordinates.x() + _serviceData.biasFromCenter.inWidth);
    else
    {
        if (!(numberTheRow%2))
            oldCoordinates.setX(0.0 + (_serviceData.biasFromCenter.inWidth/2.0));
        else
            oldCoordinates.setX(0.0 + _serviceData.biasFromCenter.inWidth);
        if(numberTheRow)
            oldCoordinates.setY(oldCoordinates.y() + _serviceData.biasFromCenter.inHeight);
        else
            oldCoordinates.setY(oldCoordinates.y() + _serviceData.biasFromCenter.inHeight*2.0/3.0);
    }
    return oldCoordinates;
}

void GridGroupItem::calculateServiceData()
{
    IGridCell *gridCell = creatingGridCellForServiceData();
    _serviceData = gridCell->calculateServiceData(_inputData.sceneSize,
                                                  _inputData.numberOfRows,
                                                  _inputData.numberOfColumns);
    delete gridCell;
}

GridItem* GridGroupItem::creatingGridCell()
{
    switch(_typeGrid)
    {
    case GridType::hexagonOddR:
        return (new GridItem(new HexagonalCell(), _serviceData));
        break;
    case GridType::hexagonEvenR:
        return (new GridItem(new HexagonalCell(), _serviceData));
        break;
    case GridType::hexagonOddQ:
        return (new GridItem(new HexagonalCell(OrientHexagon::flat_topped), _serviceData));
        break;
    case GridType::hexagonEvenQ:
        return (new GridItem(new HexagonalCell(OrientHexagon::flat_topped), _serviceData));
        break;
    default:
        // FEX ME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return (new GridItem(new HexagonalCell(), _serviceData));
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        break;
}
}

IGridCell* GridGroupItem::creatingGridCellForServiceData()
{
    switch(_typeGrid)
    {
    case GridType::hexagonOddR:
    case GridType::hexagonEvenR:
        return new HexagonalCell();
        break;
    case GridType::hexagonOddQ:
    case GridType::hexagonEvenQ:
        return new HexagonalCell(OrientHexagon::flat_topped);
        break;
    default:
        // FEX ME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return (new HexagonalCell());
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

}

#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include "GridGroupItem.h"

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView();

    inline void setGridGroupItem(GridGroupItem *gridGroup){
        _gridGroup = gridGroup;
    }

private:
    GridGroupItem *_gridGroup{nullptr};
};

#endif // MYGRAPHICSVIEW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "myItem.h"
#include "GridItem.h"
#include "MyGraphicsView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    GridGroupItem *item;
};

#endif // MAINWINDOW_H

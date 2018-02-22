#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HexagonalCell.h"
#include "GridGroupItem.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);



//    NumberOfCell inputData;
//    inputData.sceneSize = QSize(1000,1000);
//    inputData.numberOfColumns = 5;
//    inputData.numberOfRows = 3;
    item = new GridGroupItem(NumberOfCells(5,3));
    scene->addItem(item);
    QSizeF sceneSize = item->getSceneSize();
    scene->setSceneRect(0,0,sceneSize.width(),sceneSize.height());
    ui->graphicsView->setScene(scene);
}

void MainWindow::resizeEvent(QResizeEvent *) {
    ui->graphicsView->fitInView(item, Qt::KeepAspectRatio);
    ui->graphicsView->centerOn(500, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete item;
}

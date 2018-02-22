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



    InputDataForGridGroup inputData;
    inputData.sceneSize = QSize(1000,1000);
    inputData.numberOfColumns = 5;
    inputData.numberOfRows = 3;
    item = new GridGroupItem(inputData);

    scene->addItem(item);


//    ui->graphicsView->centerOn(0, 0);
    QSizeF sceneSize = item->getSceneSize();
    scene->setSceneRect(0,0,sceneSize.width(),sceneSize.height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(item, Qt::KeepAspectRatio);
}

//void MainWindow::resizeEvent(QResizeEvent *) {
////    QRectF bounds = scene->itemsBoundingRect();
////    bounds.setWidth(bounds.width()*0.9);         // to tighten-up margins
////    bounds.setHeight(bounds.height()*0.9);       // same as above
//    ui->graphicsView->fitInView(item, Qt::KeepAspectRatio);
//    ui->graphicsView->centerOn(500, 0);
//}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete item;
}

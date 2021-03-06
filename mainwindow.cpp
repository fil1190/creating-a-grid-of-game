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
    item = new GridGroupItem(NumberOfCells(100,100), this);

    scene->addItem(item);
    QSizeF sceneSize = item->getSceneSize();
    scene->setSceneRect(0,0,sceneSize.width(),sceneSize.height());
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

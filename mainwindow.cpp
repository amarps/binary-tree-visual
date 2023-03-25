#include "mainwindow.h"
#include <QScrollArea>
#include <qboxlayout.h>

MainWindow::MainWindow(QWidget *parent)
{
    canvas = new Canvas();
    auto scrollableArea = new QScrollArea;
    scrollableArea->setWidget(canvas);

    auto layout = new QVBoxLayout;
    layout->addWidget(scrollableArea);

    // Build the main window
    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
    this->setMinimumHeight(400);
    this->setWindowTitle("Binary Search Tree Visualization");


}

MainWindow::~MainWindow()
{
}
#include "mainwindow.h"
#include <QScrollArea>
#include <qboxlayout.h>
#include <QtDebug>
#include "sidebar.h"

MainWindow::MainWindow(QWidget *parent)
{
    canvas = new Canvas();
    sidebar = new Sidebar();

    // auto scrollableArea = new QScrollArea;
    // scrollableArea->setWidget(canvas);

    // scrollableArea->installEventFilter(canvas);

    auto layout = new QHBoxLayout;
    layout->addWidget(canvas);
    layout->addWidget(sidebar);

    // Build the main window
    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
    this->setMinimumHeight(400);
    this->setMinimumWidth(600);
    this->setWindowTitle("Binary Search Tree Visualization");

    this->canvas->repaint();


    this->show();
}

MainWindow::~MainWindow()
{
    delete canvas;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{\
    QMainWindow::resizeEvent(event);
    this->canvas->repaint();
}

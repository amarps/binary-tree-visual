#include "mainwindow.h"
#include <QScrollArea>
#include <qboxlayout.h>
#include <QtDebug>
#include <QObject>
#include <QStringList>
#include <QStringListIterator>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include "sidebar.h"

MainWindow::MainWindow(QWidget *parent)
{
    this->bst = new BinarySearchTree<int>;
    canvas = new Canvas(this->bst);
    sidebar = new Sidebar();

    auto scrollableArea = new QScrollArea;
    scrollableArea->setWidget(canvas);

    scrollableArea->installEventFilter(canvas);

    auto layout = new QHBoxLayout;
    layout->addWidget(canvas);
    layout->addWidget(sidebar);

    // // Build the main window
    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
    this->setMinimumHeight(400);
    this->setMinimumWidth(600);
    this->setWindowTitle("Binary Search Tree Visualization");

    this->canvas->repaint();

    // connect(this->sidebar->deleteButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
    connect(this->sidebar->insertButton, SIGNAL(clicked()), this, SLOT(insertClicked()));
    connect(this->sidebar->deleteButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
    connect(this->sidebar->inorderButton, SIGNAL(clicked()), this, SLOT(inorderTraversal()));
    connect(this->sidebar->postorderButton, SIGNAL(clicked()), this, SLOT(postorderTraversal()));
    connect(this->sidebar->preorderButton, SIGNAL(clicked()), this, SLOT(preorderTraversal()));
    connect(this->sidebar->stoporderButton, SIGNAL(clicked()), this, SLOT(stoporderTraversal()));


    this->show();
}

MainWindow::~MainWindow()
{
    // delete canvas;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    // this->canvas->repaint();
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::stoporderTraversal() const {
    qDebug() << "Preorder traversal";
    auto preorderVal =  this->bst->getPreOrderTraversal();
    auto preorderValList = preorderVal.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(preorderValList);

    while (iterator.hasNext())
    {
        auto s = iterator.next().toInt();
        this->bst->stopPreorderTraversal(s);
        this->canvas->repaint(); // repaint to show changes to tree
    }
}

void MainWindow::preorderTraversal() const {
    qDebug() << "Preorder traversal";
    auto preorderVal =  this->bst->getPreOrderTraversal();
    auto preorderValList = preorderVal.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(preorderValList);

    while (iterator.hasNext())
    {
        auto s = iterator.next().toInt();
        delay();
        this->bst->runPreorderTraversal(s);
        this->canvas->repaint(); // repaint to show changes to tree
    }
}


void MainWindow::inorderTraversal() const
{
    qDebug() << "Inorder traversal";
    auto preorderVal =  this->bst->getInOrderTraversal();
    auto preorderValList = preorderVal.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(preorderValList);

    while (iterator.hasNext())
    {
        auto s = iterator.next().toInt();
        delay();

        this->bst->runPreorderTraversal(s);
        this->canvas->repaint(); // repaint to show changes to tree
    }
}

void MainWindow::postorderTraversal() const
{
     qDebug() << "Inorder traversal";
    auto value =  this->bst->getPostOrderTraversal();
    auto valueList = value.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(valueList);

    while (iterator.hasNext())
    {
        auto s = iterator.next().toInt();
        delay();

        this->bst->runPreorderTraversal(s);
        this->canvas->repaint(); // repaint to show changes to tree
    }
}

void MainWindow::insertClicked() const
{
    // Get entire line of text and iterate through the list of
    // values separated by whitespace - inserting all the values
    QString values = this->sidebar->insertValueLineEdit->text();
    QStringList valueList = values.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(valueList);

    while (iterator.hasNext())
    {
        if(!this->bst->insert(iterator.next().toInt())) // inserts 0 if text isn't an int
            qDebug() << "empty";
        else
            qDebug() << "empty";
    }
    this->canvas->repaint(); // repaint to show changes to tree
    this->sidebar->insertValueLineEdit->setText(""); // clear text box
    return;
}

// Slot for delete button
void MainWindow::deleteClicked() const {
    QString value = this->sidebar->deleteValueLineEdit->text();

    if(!this->bst->deleteItem(value.toInt()))
        qDebug() << "Value is not in tree...";
    else
        qDebug() << "Value deleted.";

    this->canvas->repaint(); // repaint to show changes to tree
    this->sidebar->deleteValueLineEdit->setText(""); // clear text box
    return;
}
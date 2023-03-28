#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "canvas.h"
#include "sidebar.h"
#include "binarysearchtree.h"
class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void resizeEvent(QResizeEvent* event);

private:
    Canvas *canvas;
    Sidebar *sidebar;
    BinarySearchTree<int>* bst;

private slots:
    void insertClicked() const;
    void deleteClicked() const;

    void preorderTraversal() const;
    void inorderTraversal() const;
    void postorderTraversal() const;
    void stoporderTraversal() const;
};

#endif // MAINWINDOW_H

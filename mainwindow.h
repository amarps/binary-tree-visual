#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "canvas.h"
#include "sidebar.h"
class MainWindow: public QMainWindow {
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void resizeEvent(QResizeEvent* event);

private:
    Canvas *canvas;
    Sidebar *sidebar;
};

#endif // MAINWINDOW_H

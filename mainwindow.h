#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "canvas.h"
class MainWindow: public QMainWindow {
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Canvas *canvas;
};

#endif // MAINWINDOW_H

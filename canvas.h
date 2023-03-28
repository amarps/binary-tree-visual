#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QColor>
#include "binarysearchtree.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(BinarySearchTree<int> *bst, QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    QColor getBackgroundColor() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    BinarySearchTree<int> *bst;
    double scale = 1;
    QColor backgroundColor;
    void autoSize();
};

#endif // CANVAS_H

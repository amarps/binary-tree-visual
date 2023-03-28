#include "canvas.h"
#include <QStyleOption>
#include <QPainter>

Canvas::Canvas(BinarySearchTree<int> *bst, QWidget *parent)
{
    this->bst = bst;
    this->backgroundColor = Qt::white;
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize Canvas::sizeHint() const
{
    return QSize(50, 50);
}

QColor Canvas::getBackgroundColor() const
{
    return this->backgroundColor;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    // Only repaint the tree if it's not empty
    if (this->bst->isEmpty())
        return;
    QPainter painter(this);
    this->setStyleSheet("background-color: white;");

    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    QPen pen;
    pen.setColor(Qt::black);

    painter.setBrush(brush);
    painter.setPen(pen);

    this->bst->draw(&painter, this->scale);

    // Autosize the renderArea after the tree has been drawn.
    this->autoSize();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
}

void Canvas::autoSize()
{
    QSize size(bst->getTotalX(), bst->getTotalY());
    this->setMinimumSize(size);
    this->resize(size);
}

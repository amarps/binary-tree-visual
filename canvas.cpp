#include "canvas.h"
#include <QStyleOption>
#include <QPainter>

Canvas::Canvas()
{
    this->backgroundColor = Qt::green;
    this->setStyleSheet("background-color: white;");
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(400, 400);
}

QSize Canvas::sizeHint() const
{
    return QSize(400, 400);
}

QColor Canvas::getBackgroundColor() const
{
    return this->backgroundColor;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
}

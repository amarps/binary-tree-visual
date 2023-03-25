#include "canvas.h"

Canvas::Canvas()
{
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

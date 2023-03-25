#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QColor>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    QColor getBackgroundColor() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QColor backgroundColor;
};

#endif // CANVAS_H

#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Sidebar : public QWidget
{
    Q_OBJECT
private:

public:
    Sidebar();
    ~Sidebar();

    QLineEdit* insertValueLineEdit;
    QLineEdit* deleteValueLineEdit;
    QPushButton* insertButton;
    QPushButton* deleteButton;
    QPushButton* stoporderButton;
    QPushButton* preorderButton;
    QPushButton* inorderButton;
    QPushButton* postorderButton;
};


#endif // SIDEBAR_H

#include "sidebar.h"

Sidebar::Sidebar(/* args */)
{
    auto editorLayout = new QVBoxLayout();
    auto editorLabel = new QLabel("Modifier");

    insertButton = new QPushButton("&insert");
    insertValueLineEdit = new QLineEdit;
    insertValueLineEdit->setMaximumWidth(200);
    insertValueLineEdit->setToolTip("Enter single value or multiple values separated by space");

    deleteButton = new QPushButton("&delete");
    deleteValueLineEdit = new QLineEdit;
    deleteValueLineEdit->setMaximumWidth(200);
    deleteValueLineEdit->setToolTip("Enter value to delete");

    editorLabel->setMaximumHeight(10);
    editorLayout->addWidget(editorLabel);
    editorLayout->addWidget(insertButton);
    editorLayout->addWidget(insertValueLineEdit);
    editorLayout->addWidget(deleteButton);
    editorLayout->addWidget(deleteValueLineEdit);


    auto viewerLayout = new QVBoxLayout();
    auto viewerLabel = new QLabel("Traversal");
    stoporderButton = new QPushButton("&reset");
    preorderButton = new QPushButton("&preorder");
    inorderButton = new QPushButton("&indorder");
    postorderButton = new QPushButton("&postorder");
    viewerLabel->setMaximumHeight(10);
    viewerLayout->addWidget(viewerLabel);
    viewerLayout->addWidget(stoporderButton);
    viewerLayout->addWidget(preorderButton);
    viewerLayout->addWidget(inorderButton);
    viewerLayout->addWidget(postorderButton);

    auto mainlayout = new QVBoxLayout();
    editorLayout->setContentsMargins(0, 0, 0, 0);
    viewerLayout->setContentsMargins(0, 50, 0, 0);
    mainlayout->addLayout(editorLayout);
    mainlayout->addLayout(viewerLayout);
    this->setMaximumWidth(200);
    this->setLayout(mainlayout);
}

Sidebar::~Sidebar()
{
}
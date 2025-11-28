//
// Created by Ezra Kahn on 11/27/25.
//

#include "Pane.h"

#include <iostream>
#include <QPushButton>
#include <QLayout>

#include "ViewSplitter.h"

Pane::Pane(QWidget *parent) : QWidget(parent) {
    m_bgColor = QColor(random() % 256, random() % 256, random() % 256);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, m_bgColor); // You can also use QColor(r, g, b)
    this->setPalette(palette);

    // Make sure the background is visible
    this->setAutoFillBackground(true);    //etViewMode(QMdiArea::TabbedView);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(4);

    auto *buttonSplitH = new QPushButton("Split Horizontal", this);
    auto *buttonSplitV = new QPushButton("Split Vertical", this);

    buttonSplitH->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    buttonSplitV->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    //auto *container = new QWidget(this);
    layout->addWidget(buttonSplitH);
    layout->addWidget(buttonSplitV);

    //addSubWindow(container);
    //container->show();

    connect(buttonSplitH, &QPushButton::clicked, this, [this]() {
        split(Qt::Horizontal);
    });
    connect(buttonSplitV, &QPushButton::clicked, this, [this]() {
        split(Qt::Vertical);
    });
}

void Pane::split(Qt::Orientation orientation)
{
    std::cout << "Splitting pane" << std::endl;
    QWidget *container = this->parentWidget();
    if (!container) return;

    QSize originalSize = size();

    auto *newSplitter = new ViewSplitter(orientation, container);
    auto* newPane = new Pane();

    newSplitter->addWidget(this);
    newSplitter->addWidget(newPane);

    this->setParent(newSplitter);
    newSplitter->setParent(container);

    if (auto* parentSplitter = qobject_cast<QSplitter*>(container)) {
        // Replace this pane with the new splitter in the parent splitter
        int idx = parentSplitter->indexOf(this);
        if (idx >= 0) parentSplitter->replaceWidget(idx, newSplitter);
    } else if (auto* lay = container->layout()) {

        std::cout << "layout replace" << std::endl;
        // Replace this pane with the new splitter in the parent layout
        lay->addWidget(newSplitter);
        // Fallback: keep geometry and insert manually
        // newSplitter->setGeometry(this->geometry());
        // newSplitter->setParent(container);
    } else {
        std::cout << "fallback" << std::endl;
        // Fallback: keep geometry and insert manually
        newSplitter->setGeometry(this->geometry());
        newSplitter->setParent(container);
    }


    newSplitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    newSplitter->show();

    std::cout << "New Pane" << std::endl;
    container->dumpObjectTree();
}
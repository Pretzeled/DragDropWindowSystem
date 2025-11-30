//
// Created by Ezra Kahn on 11/27/25.
//

#include "Pane.h"

#include <iostream>
#include <QPushButton>
#include <QLayout>
#include <QLabel>

#include "ViewSplitter.h"

Pane::Pane(QWidget *parent, int index) : QWidget(parent) {
    this->m_index = index;
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

    auto *label = new QLabel(QString("Pane %1").arg(m_index), this);

    auto *buttonSplitH = new QPushButton("Split Horizontal", this);
    auto *buttonSplitV = new QPushButton("Split Vertical", this);

    buttonSplitH->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    buttonSplitV->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    //auto *container = new QWidget(this);
    layout->addWidget(label);
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

    auto *newSplitter = new ViewSplitter(orientation);
    auto *newPane = new Pane(newSplitter, this->m_index + 1);

    if (auto* parentSplitter = qobject_cast<QSplitter*>(container)) {
        // Replace this pane with the new splitter in the parent splitter
        int idx = parentSplitter->indexOf(this);
        std::cout << idx << std::endl;
        if (idx >= 0) parentSplitter->replaceWidget(idx, newSplitter);
    } else if (auto* lay = container->layout()) {
        // It's fine if we addWidget because the only time we aren't in a QSplitter is when the parent is ViewManager
        newSplitter->setParent(container);
        lay->addWidget(newSplitter);

    } else {
        // Fallback: keep geometry
        newSplitter->setParent(container);
        newSplitter->setGeometry(this->geometry());
    }

    newSplitter->addWidget(this);
    newSplitter->addWidget(newPane);


    // newSplitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    newSplitter->setSizes({1,1});
    this->show();
    newSplitter->show();

    std::cout << "New Pane" << std::endl;
    //container->dumpObjectTree();
}
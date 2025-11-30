//
// Created by Ezra Kahn on 11/28/25.
//

#include "FluidTabBar.h"

#include <QVBoxLayout>

#include "FloatingTabWidget.h"

FluidTabBar::FluidTabBar(QWidget *parent)
    : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    for (int i = 0; i < 3; ++i) {
        auto* tab = new FloatingTabWidget(QString("Tab %1").arg(i + 1), this);
        layout->addWidget(tab);
    }

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    layout->addStretch(1);

    auto bgColor = QColor(200, 200, 200);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, bgColor); // You can also use QColor(r, g, b)
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

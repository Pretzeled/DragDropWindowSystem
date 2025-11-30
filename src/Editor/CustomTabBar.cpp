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
}

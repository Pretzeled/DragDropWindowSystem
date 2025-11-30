//
// Created by Ezra Kahn on 11/27/25.
//

#include "ViewManager.h"

#include <QVBoxLayout>

#include "Pane.h"

ViewManager::ViewManager(QWidget *parent) : QWidget(parent) {
    auto *outerLayout = new QVBoxLayout(this);
    outerLayout->setContentsMargins(0,0,0,0);
    outerLayout->setSpacing(0);

    auto* pane = new Pane(this);
    pane->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    outerLayout->addWidget(pane);

    // Set the background color of only this QTextEdit
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, Qt::yellow); // For text input areas, use QPalette::Base
    this->setPalette(palette);
}
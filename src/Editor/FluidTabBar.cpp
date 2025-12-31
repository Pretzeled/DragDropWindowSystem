//
// Created by Ezra Kahn on 11/28/25.
//

#include "FluidTabBar.h"

#include <iostream>
#include <QVBoxLayout>

#include "FloatingTabWidget.h"

FluidTabBar::FluidTabBar(QWidget *parent)
    : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    for (int i = 0; i < 3; ++i) {
        // auto* tab = new FloatingTabWidget(i, this);
        // layout->addWidget(tab);
        addTab(i);
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

bool FluidTabBar::addTab(int modelIndex, bool selectTab) {
    auto* tab = new FloatingTabWidget(modelIndex, this);
    tab->_m_tabIndex = m_tabCount;
    connect(tab, &FloatingTabWidget::tabSelected, this, &FluidTabBar::slotSelectTab);

    if (selectTab)
    {
        tab->setChecked(true);
        if (m_tabCount >= 1)
        {
            static_cast<FloatingTabWidget*>(layout()->itemAt(m_tabCount - 1)->widget())->setChecked(false);
        }

        this->m_selectedTabIndex = m_tabCount;

    }
    m_tabCount++;
    layout()->addWidget(tab);
    return true;
}

void FluidTabBar::slotSelectTab(int tabIndex) {
    std::cout << tabIndex << std::endl;
    if (tabIndex < 0 || tabIndex >= m_tabCount) {
        return;
    }

    dynamic_cast<FloatingTabWidget*>(layout()->itemAt(m_selectedTabIndex)->widget())->setChecked(false);
    dynamic_cast<FloatingTabWidget*>(layout()->itemAt(tabIndex)->widget())->setChecked(true);

    m_selectedTabIndex = tabIndex;
}
//
// Created by Ezra Kahn on 11/28/25.
//

#include "FluidTabBar.h"

#include <iostream>
#include <qevent.h>
#include <QVBoxLayout>
#include <QStackedLayout>

#include "FloatingTabWidget.h"

FluidTabBar::FluidTabBar(QWidget *parent)
    : QWidget(parent) {

    QStackedLayout* stackLayout = new QStackedLayout(this);

    QWidget* tabContainer = new QWidget(this);

    tabLayout = new QHBoxLayout(tabContainer);

    stackLayout->setStackingMode(QStackedLayout::StackAll);
    stackLayout->addWidget(tabContainer);

    for (int i = 0; i < 3; ++i) {
        // auto* tab = new FloatingTabWidget(i, this);
        // layout->addWidget(tab);
        addTab(i);
    }

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tabLayout->setSpacing(0);
    tabLayout->setContentsMargins(0,0,0,0);
    tabLayout->addStretch(1);

    auto bgColor = QColor(200, 200, 200);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, bgColor); // You can also use QColor(r, g, b)
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

bool FluidTabBar::addTab(const int modelIndex, const bool selectTab) {
    // Create a tab based on given model index
    auto* tab = new FloatingTabWidget(modelIndex, this);
    tab->_m_tabIndex = m_tabCount;

    // Bind new tab click events
    connect(tab, &FloatingTabWidget::tabSelected, this, &FluidTabBar::slotSelectTab);

    if (selectTab)
    {
        tab->setChecked(true);
        if (m_tabCount >= 1)
        {
            dynamic_cast<FloatingTabWidget*>(tabLayout->itemAt(m_tabCount - 1)->widget())->setChecked(false);
        }

        this->m_selectedTabIndex = m_tabCount;

    }
    m_tabCount++;
    tabLayout->addWidget(tab);
    updateTabPositions(true);
    return true;
}

void FluidTabBar::slotSelectTab(const int tabIndex) {
    if (tabIndex < 0 || tabIndex >= m_tabCount) {
        return;
    }

    dynamic_cast<FloatingTabWidget*>(tabLayout->itemAt(m_selectedTabIndex)->widget())->setChecked(false);
    dynamic_cast<FloatingTabWidget*>(tabLayout->itemAt(tabIndex)->widget())->setChecked(true);

    m_selectedTabIndex = tabIndex;
}

void FluidTabBar::updateTabPositions(const bool tabCountChanged)
{
    if (tabCountChanged)
        m_tabEdgePosArr = new int[m_tabCount];

    int x = 0;
    for (int i = 0; i < m_tabCount; ++i)
    {
        x += tabLayout->itemAt(i)->sizeHint().width();
        m_tabEdgePosArr[i] = x;
    }
}

void FluidTabBar::dragEnterEvent(QDragEnterEvent* event)
{
    updateTabDropPositioning(event->position().x());
}

void FluidTabBar::dragMoveEvent(QDragMoveEvent* event)
{

}


void FluidTabBar::updateTabDropPositioning(const int xPos)
{
    int edgeX = 0;
    int index = -1;
    for (int i = 0; i < m_tabCount; ++i)
    {
        if (xPos < (edgeX + m_tabEdgePosArr[i]) / 2)
        {
            index = i;
            break;
        }
        edgeX = m_tabEdgePosArr[i];
    }
    if (index == -1)
    {
        index = m_tabCount;
    }

    m_tabDropPositioning.dropIndex = index;
    m_tabDropPositioning.markerX = edgeX;
    if (index > 0)
    {
        m_tabDropPositioning.dropRegionLeftEdge = m_tabEdgePosArr[index - 1];
    } else
    {
        m_tabDropPositioning.dropRegionLeftEdge = 0;
    }
    if (index < m_tabCount)
    {
        m_tabDropPositioning.dropRegionRightEdge = m_tabEdgePosArr[index];
    }else
    {
        m_tabDropPositioning.dropRegionRightEdge = -1;
    }
}

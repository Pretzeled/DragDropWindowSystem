//
// Created by Ezra Kahn on 11/28/25.
//

#ifndef TABBAR_H
#define TABBAR_H
#include <qboxlayout.h>
#include <QWidget>

struct TabDropPositioning
{
    int dropIndex;
    int markerX;
    int dropRegionLeftEdge;
    int dropRegionRightEdge;
};

class FluidTabBar: public QWidget{
    Q_OBJECT
public:
    FluidTabBar(QWidget *parent = nullptr);
    bool addTab(int modelIndex, bool selectTab = true);
protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
private:
    int m_selectedTabIndex = -1;
    int m_tabCount = 0;
    int* m_tabEdgePosArr;
    TabDropPositioning m_tabDropPositioning;
    void updateTabPositions(bool tabCountChanged = true);
    void updateTabDropPositioning(int xPos);
    QHBoxLayout* tabLayout;
public slots:
    void slotSelectTab(int tabIndex);
};



#endif //TABBAR_H

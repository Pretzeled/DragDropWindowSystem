//
// Created by Ezra Kahn on 11/28/25.
//

#ifndef TABBAR_H
#define TABBAR_H
#include <QWidget>

class FluidTabBar: public QWidget{
    Q_OBJECT
public:
    FluidTabBar(QWidget *parent = nullptr);
    bool addTab(int modelIndex, bool selectTab = true);
private:
    int m_selectedTabIndex = -1;
    int m_tabCount = 0;
public slots:
    void slotSelectTab(int tabIndex);
};



#endif //TABBAR_H

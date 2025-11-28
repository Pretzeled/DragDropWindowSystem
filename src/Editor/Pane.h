//
// Created by Ezra Kahn on 11/27/25.
//

#ifndef PANE_H
#define PANE_H
#include <QMdiArea>


class Pane: public QWidget {
    Q_OBJECT
public:
    Pane(QWidget *parent = nullptr);
private:
    QColor m_bgColor;
public slots:
    void split(Qt::Orientation orientation);
};



#endif //PANE_H

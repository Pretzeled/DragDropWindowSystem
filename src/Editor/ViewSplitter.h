//
// Created by Ezra Kahn on 11/27/25.
//

#ifndef VIEWSPLITTER_H
#define VIEWSPLITTER_H
#include <QSplitter>


class ViewSplitter: public QSplitter {
    Q_OBJECT
public:
    ViewSplitter(Qt::Orientation orientation, QWidget *parent = nullptr);
};



#endif //VIEWSPLITTER_H

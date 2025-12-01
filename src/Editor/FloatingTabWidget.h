//
// Created by Ezra Kahn on 11/28/25.
//

#ifndef FLOATINGTABWIDGET_H
#define FLOATINGTABWIDGET_H
#include <QPushButton>


class FloatingTabWidget: public QPushButton {
    Q_OBJECT
public:
    explicit FloatingTabWidget(int modelIndex, QWidget *parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    // void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *) override;

private:
    int m_modelIndex = -1;

    QPoint m_dragStart;
    bool m_dragging = false;
};



#endif //FLOATINGTABWIDGET_H

//
// Created by Ezra Kahn on 11/28/25.
//

#ifndef FLOATINGTABWIDGET_H
#define FLOATINGTABWIDGET_H
#include <QPushButton>


class FloatingTabWidget: public QPushButton {
    Q_OBJECT
public:
    explicit FloatingTabWidget(const QString &text, QWidget *parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
protected:
    // void mousePressEvent(QMouseEvent *event) override;
    // void mouseMoveEvent(QMouseEvent *event) override;
    // void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *) override;

private:
    QPoint dragStart;
    bool dragging = false;
};



#endif //FLOATINGTABWIDGET_H

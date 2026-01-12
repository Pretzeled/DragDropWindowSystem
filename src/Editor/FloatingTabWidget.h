//
// Created by Ezra Kahn on 11/28/25.
//

#ifndef FLOATINGTABWIDGET_H
#define FLOATINGTABWIDGET_H
#include <QDrag>
#include <QMimeData>
#include <QPushButton>

class FloatingTabWidget: public QPushButton {
    Q_OBJECT
public:
    explicit FloatingTabWidget(int modelIndex, QWidget *parent = nullptr);
    [[nodiscard]] QSize sizeHint() const override;
    [[nodiscard]] QSize minimumSizeHint() const override;

    int _m_tabIndex = -1;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    //void mouseReleaseEvent(QMouseEvent* event) override;
    // void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *) override;
private:
    int m_modelIndex = -1;

    QPoint m_dragStart;
signals:
    void tabSelected(int tabIndex);
};



#endif //FLOATINGTABWIDGET_H

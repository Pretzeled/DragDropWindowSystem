//
// Created by Ezra Kahn on 11/28/25.
//

#include "FloatingTabWidget.h"

#include <QMouseEvent>
#include <QPainter>

FloatingTabWidget::FloatingTabWidget(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    //setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    //setAttribute(Qt::WA_TranslucentBackground);
}

void FloatingTabWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);


    // Background
    p.setBrush(isDown() || isChecked() ? QColor(0xCC0000) : QColor(0xEEEEEE));
    p.setPen(QColor(0x444444));
    p.drawRect(rect().adjusted(0, 0, -1, -1));

    // Text
    p.drawText(rect(), Qt::AlignCenter, text());
}

// QSize FloatingTabWidget::minimumSizeHint() const {}

//
// void FloatingTabWidget::mousePressEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton) {
//         dragStart = event->globalPosition().toPoint() - frameGeometry().topLeft();
//         dragging = true;
//     }
// }
//
// void FloatingTabWidget::mouseMoveEvent(QMouseEvent *event)
// {
//     if (dragging)
//     {
//         move(event->globalPosition().toPoint() - dragStart);
//     }
// }
//
// void FloatingTabWidget::mouseReleaseEvent(QMouseEvent* event)
// {
//     if (event->button() == Qt::LeftButton) {
//         dragging = false;
//     }
// }
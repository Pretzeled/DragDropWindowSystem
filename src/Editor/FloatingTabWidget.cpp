//
// Created by Ezra Kahn on 11/28/25.
//

#include "FloatingTabWidget.h"

#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <qstyleoption.h>

FloatingTabWidget::FloatingTabWidget(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    setCheckable(true);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    setMinimumSize(sizeHint());

    //setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    //setAttribute(Qt::WA_TranslucentBackground);
}

void FloatingTabWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);


    // Background
    p.setBrush(isDown() || isChecked() ? QColor(0xCC0000) : QColor(0xEEEEEE));
    p.setPen(QColor(0x444444));
    p.drawRect(rect().adjusted(0, 0, -1, -1));
    // std::cout << "size of '" << text().toStdString() << "': " << width() << "x" << height() << std::endl;
    // Text
    p.drawText(rect(), Qt::AlignCenter, text());
}

QSize FloatingTabWidget::minimumSizeHint() const {
    // auto fm = fontMetrics();
    // int minHeight = fm.height() + 5;
    // int minWidth = fm.horizontalAdvance(text()) + 10;
    // return QSize(minWidth, minHeight);
    //std::cout << "minimum size hint: " << sizeHint().width() << "x" << sizeHint().height() << std::endl;
    return sizeHint();
}

QSize FloatingTabWidget::sizeHint() const {
    // auto fm = fontMetrics();
    // int minHeight = fm.height() + 5;
    // int minWidth = fm.horizontalAdvance(text()) + 30;
    // std::cout << "Size hint for '" << text().toStdString() << "': " << minWidth << "x" << minHeight << std::endl;
    // return QSize(minWidth, minHeight);

    QStyleOptionButton opt;
    opt.initFrom(this);
    opt.text = text();
    opt.icon = icon();
    QSize s = style()->sizeFromContents(QStyle::CT_PushButton, &opt, QPushButton::sizeHint(), this);
    return s;
}

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
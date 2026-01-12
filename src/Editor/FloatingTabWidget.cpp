//
// Created by Ezra Kahn on 11/28/25.
//

#include "FloatingTabWidget.h"

#include <iostream>
#include <QApplication>
#include <QListWidget>
#include <QMouseEvent>
#include <QPainter>
#include <qstyleoption.h>
#include <QDrag>
#include <QMimeData>

FloatingTabWidget::FloatingTabWidget(int modelIndex, QWidget *parent)
    : QPushButton(QString("MTab %1").arg(modelIndex + 1), parent)
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
    return sizeHint();
}

QSize FloatingTabWidget::sizeHint() const {
    QStyleOptionButton opt;
    opt.initFrom(this);
    opt.text = text();
    opt.icon = icon();
    QSize s = style()->sizeFromContents(QStyle::CT_PushButton, &opt, QPushButton::sizeHint(), this);
    return s;
}


void FloatingTabWidget::mousePressEvent(QMouseEvent *event)
{
    if (!isChecked()) { // Only toggle tab if it's not selected; clicking a selected tab should do nothing
        nextCheckState();
        if (isChecked()) {
            emit tabSelected(_m_tabIndex);
        }
    }

    if (event->button() == Qt::LeftButton) {
        //dragStart = event->globalPosition().toPoint() - frameGeometry().topLeft();
        m_dragStart = event->pos();
    }
}



void FloatingTabWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if ((event->pos() - m_dragStart).manhattanLength() < QApplication::startDragDistance())
        return;

    // VARS SHOULD NOT BE RECREATED
    auto* drag = new QDrag(this);


    auto* mimeData = new QMimeData;
    mimeData->setText(text()); // this should include file path at some point
    drag->setMimeData(mimeData);

    QPixmap pixmap(size());
    pixmap.fill(Qt::transparent);

    render(&pixmap);
    drag->setPixmap(pixmap);
    drag->setHotSpot(m_dragStart);
    drag->exec(Qt::MoveAction);
}


// void FloatingTabWidget::mouseReleaseEvent(QMouseEvent* event)
// {
//     if (event->button() == Qt::LeftButton) {
//         m_dragging = false;
//     }
// }
//
// Created by Ezra Kahn on 11/26/25.
//

#include "CodeSubWindow.h"

#include <QTextEdit>
#include <QVBoxLayout>

CodeSubWindow::CodeSubWindow(QWidget *parent,  const QString& title) : QMdiSubWindow(parent) {
    this->setWindowTitle(title);
    this->resize(400, 300);

    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);

    m_textEdit = new QPlainTextEdit();

    layout->addWidget(m_textEdit);

    this->setWidget(central);

}

//
// Created by Ezra Kahn on 11/26/25.
//

#ifndef CODESUBWINDOW_H
#define CODESUBWINDOW_H
#include <QMdiSubWindow>
#include <QPlainTextEdit>

class CodeSubWindow:    public QMdiSubWindow {
    Q_OBJECT
public:
    explicit CodeSubWindow(QWidget* parent, const QString& title = tr("Untitled"));

private:
    QPlainTextEdit* m_textEdit;
};



#endif //CODESUBWINDOW_H

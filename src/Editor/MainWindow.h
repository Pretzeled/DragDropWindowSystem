//
// Created by Ezra Kahn on 11/26/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qlistwidget.h>
#include <QMainWindow>
#include <qmdiarea.h>
#include <QMenuBar>
#include <__filesystem/path.h>


class MainWindow:  public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void openFile(const std::filesystem::path& filePath);
public slots:
    void newFile();
    void promptOpenFile();
private:
    QMenu* m_fileMenu;
    QToolBar* m_fileToolBar;
    QMdiArea* m_mainMDIArea;
};



#endif //MAINWINDOW_H

//
// Created by ezra on 11/26/2025.
//

#include "MainWindow.h"

#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Example");
    resize(800, 600);

    auto newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    //connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    auto fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);

    fileMenu->addSeparator();
}
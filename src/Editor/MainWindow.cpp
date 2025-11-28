//
// Created by Ezra Kahn on 11/26/25.
//

#include "MainWindow.h"

#include <iostream>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QStringListModel>
#include <QMdiArea>
#include <filesystem>
#include <QFile>
#include <QFileDialog>

#include "ViewManager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowTitle(tr("Editor"));
    this->resize(800, 600);

    auto newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    auto openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::promptOpenFile);

    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(newAct);
    m_fileMenu->addAction(openAct);

    auto* viewManager = new ViewManager(this);
    setCentralWidget(viewManager);

}

void MainWindow::newFile()
{
    std::cout << "New file triggered" << std::endl;
    this->dumpObjectTree();
    for (QWidget* w : this->findChildren<QWidget*>()) {
        std::cout << "Type: " << w->metaObject()->className() << " W: " << w->width()<< std::endl;
    }
}

void MainWindow::promptOpenFile()
{
    std::cout << "Open file triggered" << std::endl;
    auto fileName = QFileDialog::getOpenFileName(this,
    tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        //openFile(fileName.toStdString());
    }
}

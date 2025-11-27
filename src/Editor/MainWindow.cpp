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

#include "CodeSubWindow.h"
#include "CodeSubWindow.h"

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

    // m_fileToolBar = addToolBar(tr("File"));
    // fileToolBar->addAction(newAct);
    // fileToolBar->addAction(openAct);
    // fileToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea | Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // addToolBar(Qt::TopToolBarArea, fileToolBar);

    m_mainMDIArea = new QMdiArea(this);
    m_mainMDIArea->setViewMode(QMdiArea::TabbedView);
    m_mainMDIArea->setTabsClosable(true);
    m_mainMDIArea->setTabsMovable(true);
    setCentralWidget(m_mainMDIArea);

    auto *codeSubWindowA = new CodeSubWindow(this, tr("FileA.cpp"));
    auto *codeSubWindowB = new CodeSubWindow(this, tr("FileA.cpp"));

    m_mainMDIArea->addSubWindow(codeSubWindowA);
    m_mainMDIArea->addSubWindow(codeSubWindowB);

}

void MainWindow::newFile()
{
    std::cout << "New file triggered" << std::endl;
}

void MainWindow::promptOpenFile()
{
    std::cout << "Open file triggered" << std::endl;
    auto fileName = QFileDialog::getOpenFileName(this,
    tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        openFile(fileName.toStdString());
    }
}

void MainWindow::openFile(const std::filesystem::path &filePath)
{
    auto* file = new QFile(QString::fromStdString(filePath.string()));
    auto* sub = new CodeSubWindow(this, file->fileName());
    m_mainMDIArea->addSubWindow(sub);
    delete file;
}
#include <iostream>
#include <QApplication>
#include <QTabWidget>
#include <QTextEdit>
#include <QPushButton>

#include <QMainWindow>

// #include <DockWidget.h>
#include "../Editor/MainWindow.h"
// #include <DockManager.h>
// #include <QLabel>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow = new MainWindow();
    //QMainWindow mainWindow;

    mainWindow.resize(800, 600);

    mainWindow.show();
    return app.exec();

}

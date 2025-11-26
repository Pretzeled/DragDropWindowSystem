#include <iostream>
#include <QApplication>
#include <QTabWidget>
#include <QTextEdit>
#include "../Editor/MainWindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    // QTabWidget tabWidget(&mainWindow);
    // tabWidget.resize(800, 600);
    // for (int i = 1; i <= 3; ++i) {
    //     auto* edit = new QTextEdit();
    //     tabWidget.addTab(edit, QString("Tab %1").arg(i));
    // }
    mainWindow.show();
    return app.exec();
}
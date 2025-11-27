#include <iostream>
#include <QApplication>
#include <QTabWidget>
#include <QTextEdit>
#include <QPushButton>

#include "../Editor/MainWindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow = new MainWindow();

    mainWindow.show();
    return app.exec();
}

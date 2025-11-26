#include <iostream>
#include <QApplication>
#include <QTabWidget>
#include <QTextEdit>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTabWidget tabWidget;
    for (int i = 1; i <= 3; ++i) {
        auto* edit = new QTextEdit();
        tabWidget.addTab(edit, QString("Tab %1").arg(i));
    }
    tabWidget.show();
    return app.exec();
}
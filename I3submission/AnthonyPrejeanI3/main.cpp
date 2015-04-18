#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.resize( 1200, 1024 );
    mainWin.show();
    return app.exec();
}



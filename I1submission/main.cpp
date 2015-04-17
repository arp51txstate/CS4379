#include "i1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    I1 w;
    w.show();

    return a.exec();
}

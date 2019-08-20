#include "characterwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    characterwindow w;
    w.show();

    return a.exec();
}

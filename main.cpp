#include "sampleapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SampleApp w;
    w.show();

    return a.exec();
}

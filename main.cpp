#include "spaceInvader.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    spaceInvader w;
    w.show();
    return a.exec();
}

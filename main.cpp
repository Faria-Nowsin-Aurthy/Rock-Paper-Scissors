#include "Rock_Paper_Scissors.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Rock_Paper_Scissors w;
    w.show();
    return a.exec();
}

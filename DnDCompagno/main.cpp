#include "View/dnd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DND w(nullptr, new Modello());
    w.show();
    return a.exec();
}

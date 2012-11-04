#include <QtGui/QApplication>
#include "wordbook.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WordBook w;
    w.show();
    
    return a.exec();
}

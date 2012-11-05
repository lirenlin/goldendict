#include <QtGui/QApplication>
//#include "wordbook.h"
#include "wordbookdock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wordbookDock dock;
    dock.show();
    
    return a.exec();
}

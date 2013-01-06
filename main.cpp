#include "mainwindow.h"
#include "startview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    StartView startView;
    startView.show();
    
    return a.exec();
}

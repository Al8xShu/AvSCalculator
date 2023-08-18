#include <QApplication>
#include "calcmainwindow.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    CalcMainWindow appWindow;

    appWindow.setWindowIcon(QIcon(":/MainIcon.ico"));
    appWindow.setWindowTitle("AVS Calculator");

    appWindow.show();

    return a.exec();

}

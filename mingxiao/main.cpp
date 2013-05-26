#include <QApplication>
#include "mainwindow.h"
#include <QTextStream>
#include <QFile>
#include "simplemenu.h"
#include <calculator.h>
#include <karenina.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   MainWindow w;
//    Calculator w;
   // Karenina w;
    SimpleMenu w;

    w.resize(850, 650);
    w.setWindowTitle("Simple example");


    // w.setWindowIcon(QIcon("g.jpg"));

//    QTextStream outt(stdout);
//    outt << "console application oooo\n";

//    QFile data("testtxt");

//       if (data.open(QFile::WriteOnly)) {
//         outt << "yygyh\n";
//         QTextStream out(&data);
//         out << "You make me want to be a better man." << endl;
//       }else  outt << "nnnn\n";


   // w.show();
    w.show();
    return a.exec();
}

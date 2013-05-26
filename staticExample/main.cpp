#include <QCoreApplication>
#include <iostream>
#include <QDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   // std::cout<<"gg"<<std::endl;
   // qDebug()<<"ddd qdebug\n";
    printf("printf: %s %d\n", "this is a string", 23);

//    fflush(stdout);
    //std::cout.flush();
    return a.exec();
//    return 0;
}

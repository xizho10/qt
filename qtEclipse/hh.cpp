#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    window.resize(250, 150);
    window.setWindowTitle("Simple example");
    window.show();

    return app.exec();
}


//g++ -m64 -Wl,-O1 -o qtEclipse hh.o    -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
//qmake -project
//qmake
//make

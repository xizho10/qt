#include "simplemenu.h"
#include <QMenu>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QProcess>
#include <QDebug>

 static QLabel  *label;
 bool falg;
SimpleMenu::SimpleMenu(QWidget *parent)
    : QMainWindow(parent)
{
//  QAction *quit = new QAction("&Quit", this);

//  QMenu *file;
//  file = menuBar()->addMenu("&File");
//  file->addAction(quit);

//  connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

  QHBoxLayout *hbox = new QHBoxLayout();

  QPushButton *settings = new QPushButton("hhh", this);
  settings->setSizePolicy(QSizePolicy::Expanding,
      QSizePolicy::Expanding);
settings->setGeometry(100, 50, 100, 100);



QPixmap pixmap("/home/sweden/qt/mingxiao/g.jpg");

label = new QLabel(this);
label->setPixmap(pixmap);
label->setGeometry(200, 100, 400, 400);



  // hbox->addWidget(label);
   //setLayout(hbox);
      connect(settings, SIGNAL(clicked(bool)), this, SLOT(pushBt_clicked(bool)));
      //connect(settings, SIGNAL(clicked()), this, SLOT(pushBt_clicked(1)));
}

void SimpleMenu::pushBt_clicked(bool val){
//    QString program = "./NNN";
//      QProcess *myProcess = new QProcess();
//       myProcess->start(program,0);
    QObject *parent;
    QString program = "/home/sweden/qt/mingxiao/NNN";
    QStringList arguments;
    arguments << "";//-b" << "-t" << "input.txt";

    QProcess *myProcess = new QProcess(parent);
    myProcess->start(program, arguments);



    if(myProcess->waitForStarted(5000))
    {
    QByteArray out_data = myProcess->readAllStandardOutput();
    QString out_string(out_data);
    qDebug() << out_string.toStdString().c_str();
    }
    else
    {
    qDebug() << "myProcess did not start in time";
    }
    QProcess::execute("gcc /home/sweden/hh.c -o /home/sweden/ggg");
    system("/home/sweden/ggg");

    //this->close();

    if(falg==true){

        QPixmap pixmap("/home/sweden/qt/mingxiao/bobo.jpg");
        label->setPixmap(pixmap);
        falg = false ;
        return;

    }else {

        QPixmap pixmap("/home/sweden/qt/mingxiao/g.jpg");
        label->setPixmap(pixmap);
        falg = true;
        return;
    }





}

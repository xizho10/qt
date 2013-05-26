#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLayout>
#include <QDialog>
#include <QListWidget>
#include <calculator.h>
#include <QLineEdit>
#include <QStatusBar>
  QLabel *label;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *vbox = new QVBoxLayout();
      //vbox->setSpacing(1);

      QPushButton *settings = new QPushButton("Settings", this);
      settings->setSizePolicy(QSizePolicy::Expanding,
          QSizePolicy::Expanding);
      settings->setGeometry(10, 10, 100, 30);
      QPushButton *accounts = new QPushButton("Accounts", this);
      accounts->setSizePolicy(QSizePolicy::Expanding,
          QSizePolicy::Expanding);
      accounts->setGeometry(10, 50, 100, 30);
      QPushButton *loans = new QPushButton("Loans", this);
      loans->setSizePolicy(QSizePolicy::Expanding,
          QSizePolicy::Expanding);
      loans->setGeometry(10, 90, 100, 30);
      QPushButton *cash = new QPushButton("Cash", this);
      cash->setSizePolicy(QSizePolicy::Expanding,
          QSizePolicy::Expanding);
      cash->setGeometry(10, 130, 100, 30);
      QPushButton *debts = new QPushButton("Debts", this);
      debts->setSizePolicy(QSizePolicy::Expanding,
          QSizePolicy::Expanding);
      debts->setGeometry(10, 170, 100, 30);

      vbox->addWidget(settings);
      vbox->addWidget(accounts);
      vbox->addWidget(loans);
      vbox->addWidget(cash);
      vbox->addWidget(debts);
////////////////////////////////////////////////////
        QHBoxLayout *hbox = new QHBoxLayout();
      QListWidget *lw = new QListWidget(this);
      lw->addItem("The Omen");
      lw->addItem("The Exorcist");
      lw->addItem("Notes on a scandal");
      lw->addItem("Fargo");
      lw->addItem("Capote");
    lw->setGeometry(170, 40, 170, 130);
      hbox->addWidget(lw);
      hbox->addSpacing(15);
      hbox->addLayout(vbox);

     // setLayout(vbox);

    QPushButton *plus = new QPushButton("+", this);
     plus->setGeometry(250, 210, 75, 30);


     label = new QLabel("0", this);
     label->setGeometry(220, 210, 20, 30);


//     QTextEdit *edit = new QTextEdit(this);
//     edit->setGeometry(5, 5, 200, 150);

      connect(plus, SIGNAL(clicked()), this, SLOT(pttushButton_clicked()));

      QVBoxLayout *vvbox = new QVBoxLayout();


    QPushButton*  ok = new QPushButton("OK", this);
    QPushButton*  apply = new QPushButton("Apply", this);
ok->setGeometry(210, 240, 70, 30);
apply->setGeometry(280, 240, 70, 30);

connect(ok, SIGNAL(clicked()), this, SLOT(TestFunction()));
//////////////////////
spinbox = new QSpinBox(this);
spinbox->setGeometry(150, 200, 60, 30);

connect(spinbox, SIGNAL(valueChanged(int)),
     this, SLOT(setTitle(int)));
//////////////////////////////
QLabel *name = new QLabel("Name:", this);
QLabel *age = new QLabel("Age:", this);
QLabel *occupation = new QLabel("Occupation:", this);

QLineEdit *le1 = new QLineEdit(this);
QLineEdit *le2 = new QLineEdit(this);
QLineEdit *le3 = new QLineEdit(this);
name->setGeometry(200, 280, 60, 30);
age->setGeometry(200, 320, 60, 30);
occupation->setGeometry(200, 360, 60, 30);

le1->setGeometry(280, 280, 60, 30);
le2->setGeometry(280, 320, 60, 30);
le3->setGeometry(280, 360, 60, 30);
QGridLayout *grid = new QGridLayout();

grid->addWidget(name, 0, 0);
grid->addWidget(le1, 0, 1);
grid->addWidget(age, 1, 0);
grid->addWidget(le2, 1, 1);
grid->addWidget(occupation, 2, 0);
grid->addWidget(le3, 2, 1);
statusBar();

////////////////pixmap

QPixmap pixmap("bobo.jpg");

  QLabel *label = new QLabel(this);
  label->setPixmap(pixmap);
label->setGeometry(280, 360, 100, 100);
  hbox->addWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTitle(int val)
{
  setWindowTitle(QString::number(val));
  statusBar()->showMessage("OK button pressed", 200);

}

void MainWindow::TestFunction(){

    Calculator* win = new Calculator();
    win->show();

}
void MainWindow::pttushButton_clicked()
{
    int val = label->text().toInt();

    val++;
    label->setText(QString::number(val));

}

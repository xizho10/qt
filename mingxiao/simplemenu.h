#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

#include <QMainWindow>
#include <QApplication>

class SimpleMenu : public QMainWindow
{
    Q_OBJECT

  public:
    SimpleMenu(QWidget *parent = 0);
private slots:
    void pushBt_clicked(bool val);
};

#endif

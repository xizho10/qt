#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include <QSpinBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void pttushButton_clicked();
    void  TestFunction();
    void setTitle(int val);

private:
    Ui::MainWindow *ui;
     QSpinBox *spinbox;


};

#endif // MAINWINDOW_H

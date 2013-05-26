#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QMenu>
#include <QtGui>
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		MainWindow();
		void addDocument(const QString &filename);
        void setDockSize(QDockWidget* dock, int setWidth,int setHeight);
        void returnToOldMaxMinSizes();
	private slots:
		void newAction();
		void openAction();
		void saveAction();
        void gccAction();
        void spreadAction();
		
	private:
		QTabWidget* tabs;
		QToolBar* toolbar;
		void createToolbar();
        QPushButton *add;
         QMenu *menu;
         QDockWidget *dock0 ;
         QDockWidget *dock ;
         QTextEdit  *ConsoleText ;
         QTextEdit  *ErrorText ;
         QString runfileText;
         QString runfileName ;
};

#endif

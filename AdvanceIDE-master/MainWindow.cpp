#include <QFile>
#include <QMenu>
#include <QFileDialog>
#include <QToolButton>
#include <QAction>
#include <QIcon>
#include <QTextStream>

#include <iostream>

#include "CodeEditor.h"
#include "MainWindow.h"
#include "highlighter.h"
#include <QProcess>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QtGui>

using namespace std;

MainWindow::MainWindow() : QMainWindow(){
	tabs = new QTabWidget();
	tabs->setDocumentMode(true);
    add = new QPushButton(QString::fromUtf8("中文测试"), this);


    add->setGeometry(400, 0, 130, 30);
	this->setCentralWidget(tabs);
	this->createToolbar();


//QStatusBar *statusBar = this->statusBar();
    QMenu *file;
    QAction *quit = new QAction("&Quit", this);
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
//////////////////////////
    this->toolbar = addToolBar(tr("File"));
    this->toolbar->setFloatable(false);
    this->toolbar->setMovable(false);
    CodeEditor* doc1 = new CodeEditor();
    //tabs->addTab(doc1, "output");
    //this->toolbar->addAction(doc1);


//    QHBoxLayout *hbox = new QHBoxLayout(this);
QStatusBar *statusBar = this->statusBar();
   // hbox->addWidget(table);
   // hbox->addWidget(tabs);
    //hbox->addWidget(tabs);
   // setLayout(hbox);
//this->addDockWidget();
dock0 = new QDockWidget(tr("Error"), this);
dock0->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
ErrorText = new QTextEdit(new QTextEdit());
addDockWidget(Qt::RightDockWidgetArea, dock0);
dock0->setWidget(ErrorText);

dock = new QDockWidget(tr("console"), this);
ConsoleText = new QTextEdit(new QTextEdit());

addDockWidget(Qt::RightDockWidgetArea, dock);
dock->setWidget(ConsoleText);

}

void MainWindow::createToolbar(){
	this->toolbar = addToolBar(tr("File"));
	this->toolbar->setFloatable(false);
	this->toolbar->setMovable(false);
	
    QAction *newAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-new.png"), tr("&New..."), this);
	newAct->setStatusTip(tr("Create a new file"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newAction()));
	this->toolbar->addAction(newAct);
	
    QAction *openAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-open.png"), tr("&Open..."), this);
	openAct->setStatusTip(tr("Open an existing file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(openAction()));
	this->toolbar->addAction(openAct);
	
    QAction *saveAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-save.png"), tr("&Save..."), this);
	saveAct->setStatusTip(tr("Create a new file"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(saveAction()));
	this->toolbar->addAction(saveAct);
	
    QAction *saveAllAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-save-all.png"), tr("&Save all..."), this);
	saveAct->setStatusTip(tr("Create a new file"));
	this->toolbar->addAction(saveAllAct);
	
	this->toolbar->addSeparator();
	
    menu = menuBar()->addMenu("&Build");//new QMenu();
	

    QAction *buildAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-build.png"), tr("&Build"), this);
    //buildAct->setStatusTip(tr("Create a new file"));
	menu->addAction(buildAct);
    connect(buildAct, SIGNAL(triggered()), this, SLOT(gccAction()));
    //
	
    QAction *buildAllAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-build.png"), tr("&Build All"), this);
    //buildAllAct->setStatusTip(tr("Create a new file"));
	menu->addAction(buildAllAct);
	
    QAction *buildCleanAct = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-build.png"), tr("&Build Clean"), this);
    //buildCleanAct->setStatusTip(tr("Create a new file"));
	menu->addAction(buildCleanAct);

    menu->addSeparator();
    QAction *quit = new QAction(QIcon("/home/sweden/qt/AdvanceIDE-master/images/document-build.png"), tr("&quit"), this);
    //buildCleanAct->setStatusTip(tr("Create a new file"));
    menu->addAction(quit);
    quit->setShortcut(tr("CTRL+Q"));

   // menu->addSeparator();

	QToolButton* toolButton = new QToolButton();
	toolButton->setMenu(menu);
    toolButton->setDefaultAction(buildAct);
	this->toolbar->addWidget(toolButton);
    connect(toolButton, SIGNAL(clicked()), this, SLOT(spreadAction()));
    addDocument("/home/sweden/qt/AdvanceIDE-master/new.c");
    //
}
void MainWindow::spreadAction(){
    //this->toolbar->addWidget(menu);

}

void MainWindow::gccAction(){
    std::cout<<"hhh";
     system("rm /home/sweden/qt/AdvanceIDE-master/a.out");
    QFile file0("/home/sweden/qt/AdvanceIDE-master/input");
    QFile file("/home/sweden/qt/AdvanceIDE-master/output");
    file.resize(file.pos());
    file0.resize(file0.pos());
   system("gcc /home/sweden/qt/AdvanceIDE-master/new.c 2>/home/sweden/qt/AdvanceIDE-master/input");

//system("gcc /home/sweden/qt/AdvanceIDE-master/new.c -o pp");
   if (file0.open(QFile::ReadOnly | QFile::Text))
       ErrorText->setPlainText(file0.readAll());
   file0.close();
   dock0->setWidget(ErrorText);

    system("/home/sweden/qt/AdvanceIDE-master/a.out>>/home/sweden/qt/AdvanceIDE-master/output");

system("/home/sweden/a.out>>/home/sweden/qt/AdvanceIDE-master/output");
    if (file.open(QFile::ReadOnly | QFile::Text))
        ConsoleText->setPlainText(QString::fromUtf8(file.readAll()));
    file.close();
    dock->setWidget(ConsoleText);
}

void MainWindow::newAction(){
	addDocument("new document");
}

void MainWindow::openAction(){	
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open File"), "/home/webpigeon", tr("C++ Files (*.cpp *.c *.h)"));
	if(!fileName.isEmpty()){
		addDocument(fileName);
	}
}

void MainWindow::saveAction(){
	int index = tabs->currentIndex();
	QString filename = tabs->tabText(index);
	CodeEditor* ce = (CodeEditor*)tabs->widget(index);
	
    //QFile file(filename);
    QFile file("/home/sweden/qt/AdvanceIDE-master/new.c");
	if (file.open(QFile::WriteOnly | QFile::Text)){
		QTextStream out(&file);
		out << ce->toPlainText();
		out.flush();
	}
	file.close();
}

void MainWindow::addDocument(const QString &filename){
	CodeEditor* doc = new CodeEditor();
	
	QFile file(filename);
    if (file.open(QFile::ReadOnly | QFile::Text))
        doc->setPlainText(QString::fromUtf8(file.readAll()));
    file.close();

	Highlighter *highlighter = new Highlighter(doc->document());
	tabs->addTab(doc, filename);


}

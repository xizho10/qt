#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget( new QTextEdit( this ) );

      QStatusBar *statusBar = this->statusBar();

//      QProgressBar *progressBar = new QProgressBar();
//      QLabel *mode = new QLabel( tr("  EDIT  ") );
//      QLabel *modified = new QLabel( tr("  Y  ") );
//      QLabel *size = new QLabel( tr("  999999kB  ") );

//      mode->setMinimumSize( mode->sizeHint() );
//      mode->setAlignment( Qt::AlignCenter );
//      mode->setText( tr("EDIT") );
//      mode->setToolTip( tr("The current working mode.") );

//      statusBar->addPermanentWidget( mode );

//      modified->setMinimumSize( modified->sizeHint() );
//      modified->setAlignment( Qt::AlignCenter );
//      modified->setText( tr("N") );
//      modified->setToolTip( tr("Indicates if the current document has been modified or not.") );

//      size->setMinimumSize( size->sizeHint() );
//      size->setAlignment( Qt::AlignRight | Qt::AlignVCenter );
//      size->setText( tr("%1kB ").arg(0) );
//      size->setToolTip( tr("The memory used for the current document.") );

//      progressBar->setTextVisible( false );
//      progressBar->setRange( 0, 0 );

//      statusBar->addWidget( progressBar, 1 );
//      statusBar->addWidget( modified );
//      statusBar->addWidget( size );

//      statusBar->showMessage( tr("Ready"), 2000 );
}

MainWindow::~MainWindow()
{
    delete ui;
}

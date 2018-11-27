#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle(tr("NBS window"));


    openAction = new QAction(QIcon(":/images/favicon.png"),tr("&Open..."),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open file"));

    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);


    QToolBar *toolBar = addToolBar(tr("&File"));

    toolBar->addAction(openAction);

    statusBar();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QMessageBox::information(this,tr("NBS info"),tr("open"));
}

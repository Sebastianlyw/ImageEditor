#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define DefaultColor QColor(200, 0, 0, 200)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), ui->imageArea, SLOT(Open()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetPenSize()
{
    qDebug()<<ui->penSizeScrollBar->value();

    ui->imageArea->SetPenSize(ui->penSizeScrollBar->value(), DefaultColor);
}

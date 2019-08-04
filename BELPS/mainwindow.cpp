#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>
#include <QButtonGroup>

#define DefaultColor QColor(200, 0, 0, 200)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), ui->imageArea, SLOT(Open()));

    penColor = DefaultColor;
    SetPenSize();

    //Choose pen or eraser
    QButtonGroup *gp = new QButtonGroup(this);
    gp->addButton(ui->penButton);
    gp->addButton(ui->eraserButton);
    gp->setExclusive(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetPenSize()
{
    status = PEN;
    ui->penButton->setChecked(true);
    qDebug()<<ui->penSizeScrollBar->value();

    ui->imageArea->SetPenSize(ui->penSizeScrollBar->value(), penColor);
}

void MainWindow::SetPenColor()
{
    penColor = QColorDialog::getColor(Qt::red, this);
    QString style = QString("background-color:rgba(%1,%2,%3,%4)")
            .arg(penColor.red()).arg(penColor.green()).arg(penColor.blue()).arg(penColor.alpha());
    ui->colorButton->setStyleSheet(style);
    SetPenSize();
}

void MainWindow::SetEraser()
{
    status = ERARSER;
    ui->eraserButton->setChecked(true);
    ui->imageArea->SetEraser(ui->penSizeScrollBar->value());
}

#include "belImage.h"
#include <QPainter>
#include <QFileDialog>
#include <QMouseEvent>

//New QWidget component for displaying the image.
belImage::belImage(QWidget *parent) : QWidget(parent)
{

}

belImage::~belImage()
{

}

void belImage::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    if(!outputImage.isNull())
    {
        //Redner origin image in editor.
        p.drawImage(0,0, outputImage);
    }

}

void belImage::mouseMoveEvent(QMouseEvent *e)
{
    if(outputImage.isNull())
    {
        return;
    }

    QPainter p(&outputImage);


    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(pen);


    if(mouseOldPos.isNull())
    {
        mouseOldPos  = e->pos();
    }

    p.drawLine(QLine(mouseOldPos, e->pos()));
    mouseOldPos = e->pos();
    update();
}

void belImage::mouseReleaseEvent(QMouseEvent *ev)
{
    //Clean ending position when evertime mouse is released.
    //Otherwise this ending position will be used as starting position when
    //new mouse clicked event triggered.
    mouseOldPos = QPoint();
}

//Open image to edit.
void belImage::Open()
{
    QString fileName =  QFileDialog::getOpenFileName(this, "Open image file",
                                 "","Supported format(*.png *.jpg *.bmp)");

    if(fileName.isEmpty() || !srcImage.load(fileName))
    {
        return;
    }
    mouseOldPos = QPoint();

    resize(srcImage.size());
    outputImage  = srcImage.copy();
    update();
}

void belImage::Save()
{
    if(outputImage.isNull())
    {
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Save file","","Supported format(*.png *.jpg *.bmp)");
    if(fileName.isNull() || !outputImage.save(fileName))
    {
        return;
    }

}


void belImage::SetPenSize(int size, QColor color)
{
    //Setting Qpen
    pen.setWidth(size);
    pen.setBrush(color);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
}

void belImage::SetEraser(int size)
{
    //Setting Qpen
    pen.setWidth(size);
    //Use origin image as brush
    pen.setBrush(QBrush(srcImage));
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
}


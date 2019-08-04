#include "belImage.h"
#include <QPainter>
#include <QFileDialog>

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
    if(!srcImage.isNull())
    {
        //Redner origin image in editor.
        p.drawImage(0,0, srcImage);
    }

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

    resize(srcImage.size());
    update();





}

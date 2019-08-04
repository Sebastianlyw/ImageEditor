#ifndef BELIMAGE_H
#define BELIMAGE_H

#include <QWidget>

class belImage : public QWidget
{
    Q_OBJECT
public:
    belImage(QWidget *parent = nullptr);
    ~belImage();
    void paintEvent(QPaintEvent *ev);

signals:

public slots:
    void Open();

protected:
    QImage srcImage;

};

#endif // BELIMAGE_H

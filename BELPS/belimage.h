#ifndef BELIMAGE_H
#define BELIMAGE_H

#include <QWidget>
#include <QPen>

class belImage : public QWidget
{
    Q_OBJECT
public:
    belImage(QWidget *parent = nullptr);
    ~belImage();
    void paintEvent(QPaintEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:

public slots:
    void Open();
    void SetPenSize(int size, QColor color);
    void SetEraser(int size);
    void Save();
protected:
    QImage srcImage;
    QImage outputImage;

    QPoint mouseOldPos;
    QPen pen;
};

#endif // BELIMAGE_H

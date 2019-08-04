#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum BELSTATUS
{
    PEN,
    ERARSER,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    BELSTATUS status = PEN;

public slots:
    void SetPenSize();
    void SetPenColor();
    void SetEraser();
    void Save();
private:
    QColor penColor;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

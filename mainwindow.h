#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<double> coor_x;
    QVector<double> coor_y;
    QVector<double> time;
    QVector<double> batery;
    int busquedaBinaria(QVector<double> &time, double value);
    double interpolar(QVector<double> &time, QVector<double>&y, int n, double value);

private slots:
    void graficar();
    void search();
    void integral();

};
#endif // MAINWINDOW_H

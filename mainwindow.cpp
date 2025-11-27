#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btplot, SIGNAL(clicked()), this, SLOT(graficar()));
    connect(ui->btsearch, SIGNAL(clicked()), this, SLOT(search()));
    connect(ui->compute, SIGNAL(clicked()), this, SLOT(integral()));

    ui->plot_1->setInteraction(QCP::iRangeDrag,true);
    ui->plot_1->setInteraction(QCP::iRangeZoom,true);

    ui->plot_2->setInteraction(QCP::iRangeDrag,true);
    ui->plot_2->setInteraction(QCP::iRangeZoom,true);

    ui->plot_3->setInteraction(QCP::iRangeDrag,true);
    ui->plot_3->setInteraction(QCP::iRangeZoom,true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::graficar()
{
    FILE *a = fopen("C:\\Users\\roman\\Desktop\\Desktop\\Qt Info II\\2doParcial_Reyes_Roman\\registro_dron.dat", "rb");
    if(a==NULL){
        printf("Error al abrir el archivo.\n");
        return;
    }
    float tmp;

    coor_x.clear();
    coor_y.clear();
    time.clear();
    batery.clear();

    while(fread(&tmp, sizeof(float), 1, a) == 1){
        coor_x.append((double)tmp);
        if(fread(&tmp, sizeof(float), 1, a) != 1) break;
        coor_y.append((double)tmp);
        if(fread(&tmp, sizeof(float), 1, a) != 1) break;
        time.append((double)tmp);
        if(fread(&tmp, sizeof(float), 1, a) != 1) break;
        batery.append((double)tmp);
    }

    fclose(a);
    ui->plot_1->addGraph();
    ui->plot_1->graph(0)->setData(time, coor_x);
    ui->plot_1->graph(0)->setPen(QPen(Qt::blue));
    ui->plot_1->rescaleAxes();
    ui->plot_1->replot();

    ui->plot_2->addGraph();
    ui->plot_2->graph(0)->setData(time, coor_y);
    ui->plot_2->graph(0)->setPen(QPen(Qt::red));
    ui->plot_2->rescaleAxes();
    ui->plot_2->replot();

    ui->plot_3->addGraph();
    ui->plot_3->graph(0)->setData(time, batery);
    ui->plot_3->graph(0)->setPen(QPen(Qt::magenta));
    ui->plot_3->rescaleAxes();
    ui->plot_3->replot();
}


void MainWindow::search()
{
    double value = ui->time_search->text().toDouble();

    // usa el tamaño actual de time como n
    int n = time.size();
    double x_res = interpolar(time, coor_x, n, value);
    double y_res = interpolar(time, coor_y, n, value);
    double batery_res = interpolar(time, batery, n, value);

    ui->xcoord->setText(QString::number(x_res, 'f', 4));
    ui->ycoord->setText(QString::number(y_res, 'f', 4));
    ui->baterylvl->setText(QString::number(batery_res, 'f', 4));
}


double MainWindow::interpolar(QVector<double> &time, QVector<double> &y, int n, double value)
{
    if (value < time.first() || value > time.last()) {
        qDebug() << "Valor fuera del dominio:" << value;
        return NAN;
    }

    if (value == time.last()) {
        return y.last();
    }

    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (time[mid] <= value) left = mid + 1;
        else right = mid - 1;
    }
    int i = right;
    if (i < 0) i = 0;
    if (i >= n - 1) i = n - 2;

    double x1 = time[i];
    double x2 = time[i + 1];
    double y1 = y[i];
    double y2 = y[i + 1];

    if (x2 == x1){
        return y1;
    }
    double t = (value - x1) / (x2 - x1);
    double y_new = y1 + t * (y2 - y1);
    return y_new;
}

void MainWindow::integral()
{
    int n = time.size();
    double tmin = ui->txt_tmin->text().toDouble();
    double tmax = ui->txt_tmax->text().toDouble();
    double batery_tmin = interpolar(time, batery, n, tmin);
    double batery_tmax = interpolar(time, batery, n, tmax);

    QVector<double> time_values; //estos vectores son para interpolar los vectores sin modificar los oroginales
    QVector<double> batery_values;
    time_values.append(tmin);
    batery_values.append(batery_tmin);

    for (int i = 0; i < n; ++i) {
        double ti = time[i];
        if (ti > tmin && ti < tmax) {
            time_values.append(ti);
            batery_values.append(batery[i]);
        }
    }

    time_values.append(tmax);
    batery_values.append(batery_tmax);

    // integración trapezoidal sobre la malla tvals/bvals
    double suma = 0.0;
    for (int i = 0; i < time_values.size() - 1; ++i) {
        double dt = time_values[i + 1] - time_values[i];
        suma += dt * 0.5 * (batery_values[i] + batery_values[i + 1]);
    }
    ui->integral->setText(QString::number(suma, 'f', 4));
}

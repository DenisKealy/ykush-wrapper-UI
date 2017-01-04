#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ykushinvoker.h"

YkushInvoker YKI;
int secondsOfPower;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->init();
}

void MainWindow::init() {

    //Setup Range for timed busrt
    int min = 1;
    int max = 30;

    ui->horizontalSlider1->setRange(min, max);
    ui->horizontalSlider2->setRange(min, max);
    ui->horizontalSlider3->setRange(min, max);

    ui->spinBox1->setRange(min, max);
    ui->spinBox2->setRange(min, max);
    ui->spinBox3->setRange(min, max);

    //Synchronise Sliders with Spinners
    QObject::connect(ui->horizontalSlider1, SIGNAL(valueChanged(int)), ui->spinBox1, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider2, SIGNAL(valueChanged(int)), ui->spinBox2, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider3, SIGNAL(valueChanged(int)), ui->spinBox3, SLOT(setValue(int)));

    QObject::connect(ui->spinBox1, SIGNAL(valueChanged(int)), ui->horizontalSlider1, SLOT(setValue(int)));
    QObject::connect(ui->spinBox2, SIGNAL(valueChanged(int)), ui->horizontalSlider2, SLOT(setValue(int)));
    QObject::connect(ui->spinBox3, SIGNAL(valueChanged(int)), ui->horizontalSlider3, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_smellButton1_clicked()
{
    secondsOfPower = ui->spinBox1->value();
    YKI.timedBurst(1, secondsOfPower);
}

void MainWindow::on_smellButton2_clicked()
{
    secondsOfPower = ui->spinBox2->value();
    YKI.timedBurst(2, secondsOfPower);
}

void MainWindow::on_smelButton3_clicked()
{
    secondsOfPower = ui->spinBox3->value();
    YKI.timedBurst(3, secondsOfPower);
}

void MainWindow::on_stopAllButton_clicked()
{
    YKI.powerDownAll();
}


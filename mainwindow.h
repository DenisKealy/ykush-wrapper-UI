#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_smellButton1_clicked();

    void on_smellButton2_clicked();

    void on_smelButton3_clicked();

    void on_stopAllButton_clicked();

private:
    Ui::MainWindow *ui;
    void init();
};

#endif // MAINWINDOW_H

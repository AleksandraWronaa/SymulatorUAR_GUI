#ifndef SYMULATOR_H
#define SYMULATOR_H

#include <QMainWindow>
#include <QTimer>
#include "klasy.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Symulator;
}
QT_END_NAMESPACE



class Symulator : public QMainWindow
{
    Q_OBJECT

public:
    Symulator(QWidget *parent = nullptr);
    ~Symulator();
    //void liczenie();
private slots:

    void nextStep();

    void on_spinbox_A_valueChanged(double value);

    void on_spinbox_B_valueChanged(double value);

    void on_list_WartoscZadana_currentRowChanged(int currentRow);

    void on_button_zapisz_clicked();

    void on_button_wczytaj_clicked();

    void on_button_reset_clicked();

    void on_button_start_clicked();

    void on_button_stop_clicked();

    void on_spinbox_interval_valueChanged(double arg1);


    void on_spinbox_maksimumY_valueChanged(double arg1);

private:
    Ui::Symulator *ui;
    QTimer *timer = nullptr;
    UkladSterowania uklad;
    std::vector<double> A;
    std::vector<double> B;
    rodzajeWartosci WartoscZadana;
    int krok = 0;
    double obecnaWartosc;
};
#endif // SYMULATOR_H

#include "symulator.h"
#include "ui_symulator.h"

Symulator::Symulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Symulator)
{
    ui->setupUi(this);

    QStringList WartoscZadana ={"Skok jednostkowy","Sinusoidalny","Sygnał prostokątny"};    //Ustawianie tekstu dla tabeli Wartość Zadana
    foreach(QString item, WartoscZadana){
        ui->list_WartoscZadana->addItem(item);
    }

}

Symulator::~Symulator()
{
    delete ui;
}

void Symulator::liczenie(){
    uklad.setARX(A,B,ui->spinbox_k->value());
    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());
   // std::vector<double> wyniki = uklad.symulacja(100);
}



void Symulator::on_spinbox_A_valueChanged(double value)
{
    A.push_back(value);
}


void Symulator::on_spinbox_B_valueChanged(double value)
{
    B.push_back(value);
}

void Symulator::on_list_WartoscZadana_currentRowChanged(int currentRow)
{
    if(currentRow==0) WartoscZadana=rodzajeWartosci::skok;
    else
    (currentRow==1)? WartoscZadana=rodzajeWartosci::sinus : WartoscZadana=rodzajeWartosci::kwadrat;
}


void Symulator::on_button_zapisz_clicked()
{
    uklad.zapiszPlik("arx.txt", "pid.txt", "wartosc.txt");
}


void Symulator::on_button_wczytaj_clicked()
{
    uklad.wczytajPlik("arx.txt", "pid.txt", "wartosc.txt");

    //przypisanie wartosci do przyciskow
    ui->spinbox_P->setValue(uklad.get_kp());
    ui->spinbox_I->setValue(uklad.get_ki());
    ui->spinbox_D->setValue(uklad.get_kd());
    ui->spinbox_A->setValue(uklad.get_lastA());
    ui->spinbox_B->setValue(uklad.get_lastB());
    ui->spinbox_minimum->setValue(uklad.get_dolnyLimit());
    ui->spinbox_maksimum->setValue(uklad.get_gornyLimit());
    ui->spinbox_maksimumY->setValue(uklad.get_max());

    //ui->spinbox_okres->setValue(uklad.get);   //tu dopisac bo idk pod jaka zmienna sie zapisuje okres
    ui->spinbox_okres->setValue(0.01);
    ui->list_WartoscZadana->setCurrentRow(uklad.get_rodzajLiczba());


}


void Symulator::on_button_reset_clicked()
{
    uklad.reset();
    //dodac reset do wykresu
}


void Symulator::on_button_start_clicked()
{
    uklad.setARX(A,B,ui->spinbox_k->value());
    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());
   // std::vector<double> wyniki = uklad.symulacja(1);
}


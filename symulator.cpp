#include "symulator.h"
#include "ui_symulator.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <sstream>
#include <vector>
#include <QDebug>
#include <QVector>

std::vector<double> parseValues(const std::string& input) {
    std::vector<double> values;
    std::istringstream iss(input);
    std::string token;
    while (std::getline(iss, token, ',')) {
        try {
            values.push_back(std::stod(token));
        } catch (...) {
            std::cerr << "Nieprawidłowa wartość: " << token << std::endl;
        }
    }
    return values;
}

Symulator::Symulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Symulator),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    QStringList WartoscZadana ={"Skok jednostkowy","Sinusoidalny","Sygnał prostokątny"};    //Ustawianie tekstu dla tabeli Wartość Zadana
    foreach(QString item, WartoscZadana){
        ui->list_WartoscZadana->addItem(item);
    }
    connect(timer, SIGNAL(timeout()),this,SLOT(nextStep()));
    timer->setInterval(100);
    ui->button_stop->setEnabled(false);
    ui->button_reset->setEnabled(false);
    ui->spinbox_interval->setValue(timer->interval());

    ui->wykres->legend->setVisible(true);
    ui->wykres->addGraph();
    ui->wykres->addGraph();
    ui->wykres->graph(0)->setPen(QPen(Qt::blue));
    ui->wykres->graph(0)->setName("Wyjście układu");
    ui->wykres->graph(1)->setPen(QPen(Qt::green));
    ui->wykres->graph(1)->setName("Wartość zadana");

    ui->wykres->xAxis->setLabel("Czas");
    ui->wykres->xAxis->setRange(0,100);

    ui->wykres->yAxis->setLabel("Wartosc");
    ui->wykres->yAxis->setRange(uklad.get_max()*0.5*-1,std::max(uklad.get_wartoscZadana(), obecnaWartosc));



    ui->wykres_kontroler->legend->setVisible(true);
    ui->wykres_kontroler->addGraph();
    ui->wykres_kontroler->addGraph();
    ui->wykres_kontroler->addGraph();
    ui->wykres_kontroler->graph(0)->setPen(QPen(Qt::green));
    ui->wykres_kontroler->graph(0)->setName("Część Proporcjonalna");
    ui->wykres_kontroler->graph(1)->setPen(QPen(Qt::red));
    ui->wykres_kontroler->graph(1)->setName("Część Całkująca");
    ui->wykres_kontroler->graph(2)->setPen(QPen(Qt::yellow));
    ui->wykres_kontroler->graph(2)->setName("Część Różniczkująca");

    ui->wykres_kontroler->xAxis->setLabel("Czas");
    ui->wykres_kontroler->xAxis->setRange(0,100);

    ui->wykres_kontroler->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler->yAxis->setRange(-1,uklad.get_max());

    ui->wykres_uchyb->legend->setVisible(true);
    ui->wykres_uchyb->addGraph();
    ui->wykres_uchyb->graph(0)->setName("Uchyb");
    ui->wykres_uchyb->xAxis->setLabel("Czas");
    ui->wykres_uchyb->xAxis->setRange(0,100);

    ui->wykres_uchyb->yAxis->setLabel("Wartosc");
    ui->wykres_uchyb->yAxis->setRange(-1,uklad.get_wartoscZadana()-obecnaWartosc+0.2*(uklad.get_wartoscZadana()-obecnaWartosc));


    ui->wykres_kontroler_suma->legend->setVisible(true);
    ui->wykres_kontroler_suma->addGraph();
    ui->wykres_kontroler_suma->graph(0)->setName("Wyjście kontrolera");
    ui->wykres_kontroler_suma->xAxis->setLabel("Czas");
    ui->wykres_kontroler_suma->xAxis->setRange(0,100);

    ui->wykres_kontroler_suma->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler_suma->yAxis->setRange(-1,uklad.get_max());

}

Symulator::~Symulator()
{
    delete ui;
}

//void Symulator::liczenie(){
//    uklad.setARX(A,B,ui->spinbox_k->value());
//    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
//    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());
   // std::vector<double> wyniki = uklad.symulacja(100);
//}

void Symulator::nextStep()
{
    obecnaWartosc = uklad.symulacja(krok);
    krok++;
    //ui->label_wartosc->setNum(obecnaWartosc);
    uklad.setARX(A,B,ui->spinbox_k->value());
    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());

    ui->wykres->graph(0)->addData(krok, obecnaWartosc);
    ui->wykres->graph(1)->addData(krok, uklad.get_wartoscZadana());
    ui->wykres->yAxis->setRange(uklad.get_max()*0.5*-1,std::max(uklad.get_max(), obecnaWartosc)*1.2);
    if (krok>100)
        ui->wykres->xAxis->setRange(krok-100,krok+100);
    ui->wykres->replot();

    ui->wykres_kontroler->graph(0)->addData(krok, uklad.getBlad());
    ui->wykres_kontroler->graph(1)->addData(krok, uklad.getCalka());
    ui->wykres_kontroler->graph(2)->addData(krok, uklad.getPochodna());


    ui->wykres_kontroler->yAxis->setRange(uklad.get_max()*0.5*-1,std::max(std::max(uklad.getBlad(), uklad.getCalka()), uklad.getPochodna())*1.2);
    if (krok>100)
        ui->wykres_kontroler->xAxis->setRange(krok-100,krok+100);
    ui->wykres_kontroler->replot();



    ui->wykres_uchyb->graph(0)->addData(krok, uklad.get_wartoscZadana()-obecnaWartosc);
    ui->wykres_uchyb->yAxis->setRange(std::min(-1.0,((uklad.get_wartoscZadana()-obecnaWartosc)*-1.2)),std::max(1.0,((uklad.get_wartoscZadana()-obecnaWartosc)*1.2)));
    if (krok>100)
        ui->wykres_uchyb->xAxis->setRange(krok-100,krok+100);
    ui->wykres_uchyb->replot();


    ui->wykres_kontroler_suma->graph(0)->addData(krok, uklad.getWyjscie());
    ui->wykres_kontroler_suma->yAxis->setRange(std::min(-1.0,((uklad.getWyjscie())*-1.2)),std::max(1.0,((uklad.getWyjscie())*1.2)));
    if (krok>100)
        ui->wykres_kontroler_suma->xAxis->setRange(krok-100,krok+100);
    ui->wykres_kontroler_suma->replot();
}

/*void Symulator::on_spinbox_A_valueChanged(double value)
{
    A.push_back(value);
    //uklad.setA(A);
}


void Symulator::on_spinbox_B_valueChanged(double value)
{
    B.push_back(value);
    //uklad.setB(B);
}*/

void Symulator::on_list_WartoscZadana_currentRowChanged(int currentRow)
{
    if(currentRow==0) WartoscZadana=rodzajeWartosci::skok;
    else
    (currentRow==1)? WartoscZadana=rodzajeWartosci::sinus : WartoscZadana=rodzajeWartosci::kwadrat;
    //uklad.setRodzaj(WartoscZadana);
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
    //ui->lineEdit_A->setValue(uklad.get_lastA());
    //ui->lineEdit_B->setValue(uklad.get_lastB());
    ui->spinbox_minimum->setValue(uklad.get_dolnyLimit());
    ui->spinbox_maksimum->setValue(uklad.get_gornyLimit());
    ui->spinbox_maksimumY->setValue(uklad.get_max());
    ui->spinbox_okres->setValue(uklad.get_okres());
    ui->list_WartoscZadana->setCurrentRow(uklad.get_rodzajLiczba());


}


void Symulator::on_button_reset_clicked()
{
    ui->button_start->setEnabled(true);
    ui->button_stop->setEnabled(false);
    ui->button_reset->setEnabled(false);
    timer->stop();

    uklad.reset();
    krok = 0;

    //A.push_back(ui->spinbox_A->value());
    //B.push_back(ui->spinbox_B->value());
    // Reset współczynników A i B
    A = parseValues(ui->lineEdit_A->text().toStdString());
    B = parseValues(ui->lineEdit_B->text().toStdString());

    uklad.setARX(A, B, ui->spinbox_k->value());
    uklad.setARX(A,B,ui->spinbox_k->value());
    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());

    ui->wykres->graph(0)->data()->clear();
    ui->wykres->graph(1)->data()->clear();

    ui->wykres->xAxis->setLabel("Czas");
    ui->wykres->xAxis->setRange(0,100);

    ui->wykres->yAxis->setLabel("Wartosc");
    ui->wykres->yAxis->setRange(0,uklad.get_max());
    ui->wykres->replot();

    ui->wykres_kontroler->graph(0)->data()->clear();
    ui->wykres_kontroler->graph(1)->data()->clear();
    ui->wykres_kontroler->graph(2)->data()->clear();

    ui->wykres_kontroler->xAxis->setLabel("Czas");
    ui->wykres_kontroler->xAxis->setRange(0,100);

    ui->wykres_kontroler->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler->yAxis->setRange(0,uklad.get_max());
    ui->wykres_kontroler->replot();

    ui->wykres_uchyb->graph(0)->data()->clear();

    ui->wykres_uchyb->xAxis->setLabel("Czas");
    ui->wykres_uchyb->xAxis->setRange(0,100);

    ui->wykres_uchyb->yAxis->setLabel("Wartosc");
    ui->wykres_uchyb->yAxis->setRange(0,uklad.get_max());
    ui->wykres_uchyb->replot();

    ui->wykres_kontroler_suma->graph(0)->data()->clear();

    ui->wykres_kontroler_suma->xAxis->setLabel("Czas");
    ui->wykres_kontroler_suma->xAxis->setRange(0,100);

    ui->wykres_kontroler_suma->yAxis->setLabel("Wartosc");
    ui->wykres_kontroler_suma->yAxis->setRange(0,uklad.get_max());
    ui->wykres_kontroler_suma->replot();
}


void Symulator::on_button_start_clicked()
{
    ui->button_reset->setEnabled(true);
    ui->button_start->setEnabled(false);
    ui->button_stop->setEnabled(true);
    timer->start();
    uklad.setARX(A,B,ui->spinbox_k->value());
    uklad.setPID(ui->spinbox_P->value(),ui->spinbox_I->value(),ui->spinbox_D->value(),ui->spinbox_minimum->value(),ui->spinbox_maksimum->value());
    uklad.setWartosc(WartoscZadana,ui->spinbox_maksimumY->value(),ui->spinbox_okres->value());


}


void Symulator::on_button_stop_clicked()
{
    ui->button_start->setEnabled(true);
    ui->button_stop->setEnabled(false);
    timer->stop();
}



void Symulator::on_spinbox_interval_valueChanged(double arg1)
{
    timer->setInterval(arg1);
}




void Symulator::on_spinbox_maksimumY_valueChanged(double arg1)
{
        ui->wykres->yAxis->setRange(0,arg1+0.2*arg1);
}


void Symulator::on_checkBox_stateChanged(int arg1)
{
    uklad.setFiltr(arg1);
}

void Symulator::on_lineEdit_A_editingFinished() {
    std::string inputA = ui->lineEdit_A->text().toStdString();
    std::vector<double> newA = parseValues(inputA);
    A = newA;
    uklad.setARX(A, B, ui->spinbox_k->value());
}

void Symulator::on_lineEdit_B_editingFinished() {
    std::string inputB = ui->lineEdit_B->text().toStdString();
    std::vector<double> newB = parseValues(inputB);
    B = newB;
    uklad.setARX(A, B, ui->spinbox_k->value());
}

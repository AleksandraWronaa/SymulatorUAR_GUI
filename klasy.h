#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <vector>
#include <deque>
#include <random>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>

class ARXModel {
private:
    std::vector<double> A;
    std::vector<double> B;
    std::deque<double> u_hist;
    std::deque<double> y_hist;
    std::default_random_engine generator;
    std::normal_distribution<double> dystrybucja;
public:
    ARXModel(const std::vector<double>& a, const std::vector<double>& b, double szum = 0.01)
        : A(a), B(b), dystrybucja(0.0, szum)
    {
        size_t maxSize = std::max(A.size(), B.size());
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }
    ARXModel()
        : dystrybucja(0.0, 0.01)
    {
        A = std::vector<double>({ 0.0 });
        B = std::vector<double>({ 0.0 });
        size_t maxSize = std::max(A.size(), B.size());
        u_hist = std::deque<double>(maxSize, 0.0);
        y_hist = std::deque<double>(maxSize, 0.0);
    }

    double get_lastA() const{return A.back();}
    double get_lastB() const{return B.back();}

    void setModel(const std::vector<double>& a, const std::vector<double>& b, double szum = 0.01)
    {
        A = a;
        B = b;
        dystrybucja = std::normal_distribution<double>(0.0, szum);
    }


    double krok(double input) {
        u_hist.pop_front();
        u_hist.push_back(input);
        double szum = dystrybucja(generator);
        double y_k = 0.0;
        for (size_t i = 0; i < A.size(); i++) {
            y_k -= A[i] * y_hist[y_hist.size() - 1 - i];
        }
        for (size_t i = 0; i < B.size(); i++) {
            y_k += B[i] * u_hist[u_hist.size() - 1 - i];
        }
        y_k += szum;
        y_hist.pop_front();
        y_hist.push_back(y_k);
        return y_k;
    }

    void zapiszText(const std::string& nazwaPliku) {
        std::ofstream ofs(nazwaPliku);
        if (!ofs) return;
        ofs << A.size() << "\n";
        for (const auto& a : A) ofs << a << "\n";
        ofs << B.size() << "\n";
        for (const auto& b : B) ofs << b << "\n";
        ofs << dystrybucja.mean() << "\n" << dystrybucja.stddev() << "\n";
    }

    void wczytajText(const std::string& nazwaPliku) {
        std::ifstream ifs(nazwaPliku);
        if (!ifs) return;
        size_t rozmiarA, rozmiarB;
        ifs >> rozmiarA;
        double wartA, wartB;
        A.clear();
        A.reserve(rozmiarA);
        for (size_t i = 0; i < rozmiarA; ++i)
        {
            ifs >> wartA;
            A.push_back(wartA);
        }
        ifs >> rozmiarB;
        B.clear();
        B.reserve(rozmiarB);
        for (size_t i = 0; i < rozmiarB; ++i)
        {
            ifs >> wartB;
            B.push_back(wartB);
        }
        double mean, stddev;
        ifs >> mean >> stddev;
        dystrybucja = std::normal_distribution<double>(mean, stddev);
    }
    void reset()
    {
        A.clear();
        B.clear();
        u_hist.clear();
        y_hist.clear();
    }

};

template <typename T>
T filtr(T wartosc, T dolny, T gorny) {
    return std::max(dolny, std::min(wartosc, gorny));
}

enum class rodzajeWartosci
{
    skok = 0,
    sinus = 1,
    kwadrat = 2,
};

class WartZadana
{
public:
    WartZadana(rodzajeWartosci typ = rodzajeWartosci::skok, double maximum = 1, int cykl = 20)
    {
        rodzaj = typ;
        min = 0;
        max = maximum;
        okres = cykl;
    };

    void setWart(rodzajeWartosci typ = rodzajeWartosci::skok, double maximum = 1, int cykl = 20)
    {
        rodzaj = typ;
        min = 0;
        max = maximum;
        okres = cykl;
    }

    double obliczWartosc(int krok)
    {
        if (rodzaj == rodzajeWartosci::skok)
        {
            return max;
        }
        else if (rodzaj == rodzajeWartosci::kwadrat)
        {

            if (krok % (okres/2) == 0)
            {
                minMax = !minMax;
            }
            if (minMax == 0)
            {
                return min;
            }
            else
            {
                return max;
            }
        }
        else
        {
            double amplituda = (max - min) / 2;
            double przesuniecie = (max + min) / 2;
            double kat = (static_cast<double>(krok) / okres) * 2.0 * 3.14;
            return amplituda * sin(kat) + przesuniecie;
        }
    }

    void zapiszText(const std::string& filename) {
        std::ofstream ofs(filename);
        if (!ofs) return;
        ofs << min << "\n" << max << "\n" << okres << "\n" << static_cast<int>(rodzaj) << "\n";

    }

    void wczytajText(const std::string& nazwaPliku) {
        std::ifstream ifs(nazwaPliku);
        if (!ifs) return;
        int typ;
        ifs >> min >> max >> okres >> typ;
        rodzaj = static_cast<rodzajeWartosci>(typ);
    }

    int get_rodzajLiczba() const { return (int)rodzaj;}
    double get_max() const{return max;}
    int get_okres() const{return okres;}

private:
    rodzajeWartosci rodzaj = rodzajeWartosci::skok;
    double min = -1, max = 1;
    int okres;
    bool minMax = 0;
};

class PIDController {
private:
    double kp, ki, kd;
    double calka, bladPoprzedzajacy;
    double dolnyLimit, gornyLimit;
    bool flagaPrzeciwNasyceniowa;
    //WartZadana* wartosc;

public:
    PIDController(double kp, double ki, double kd, double dolnyLimit = -1.0, double gornyLimit = 1.0)
        : kp(kp), ki(ki), kd(kd), dolnyLimit(dolnyLimit), gornyLimit(gornyLimit),
        calka(0.0), bladPoprzedzajacy(0.0), flagaPrzeciwNasyceniowa(true)
    {
    }
    PIDController()
        : kp(0.0), ki(0.0), kd(0.0), dolnyLimit(-1.0), gornyLimit(1.0),
        calka(0.0), bladPoprzedzajacy(0.0), flagaPrzeciwNasyceniowa(true)
    {
    }

    double get_kp() const{return kp;}
    double get_ki() const{return ki;}
    double get_kd() const{return kd;}
    double get_dolnyLimit() const{return dolnyLimit;}
    double get_gornyLimit() const{return gornyLimit;}

    void ustawLimity(double nizszy, double wyzszy) {
        dolnyLimit = nizszy;
        gornyLimit = wyzszy;
    }

    void setKontroler(double _kp, double _ki, double _kd)
    {
        kp = _kp;
        ki = _ki;
        kd = _kd;
    }


    void reset() {
        calka = 0.0;
        bladPoprzedzajacy = 0.0;
    }

    double oblicz(double ustawWartosc, double wartoscProcesu) {
        double blad = ustawWartosc - wartoscProcesu;
        calka += blad;
        double pochodna = blad - bladPoprzedzajacy;
        bladPoprzedzajacy = blad;
        double wyjscie = kp * blad + ki * calka + kd * pochodna;
        if (flagaPrzeciwNasyceniowa) {
            wyjscie = filtr(wyjscie, dolnyLimit, gornyLimit);
        }
        return wyjscie;
    }
    void zapiszText(const std::string& filename) {
        std::ofstream ofs(filename);
        if (!ofs) return;
        ofs << kp << "\n" << ki << "\n" << kd << "\n";
        //ofs << calka << "\n" << bladPoprzedzajacy << "\n";
        ofs << dolnyLimit << "\n" << gornyLimit << "\n";
        ofs << flagaPrzeciwNasyceniowa << "\n";
    }

    void wczytajText(const std::string& nazwaPliku) {
        std::ifstream ifs(nazwaPliku);
        if (!ifs) return;
        ifs >> kp >> ki >> kd;
        //ifs >> calka >> bladPoprzedzajacy;
        ifs >> dolnyLimit >> gornyLimit;
        ifs >> flagaPrzeciwNasyceniowa;
    }

};
class UkladSterowania
{
public:

    UkladSterowania()
    {};
    ~UkladSterowania()
    {};
    void setPID(double kp, double ki, double kd, double dolnyLimit = -1.0, double gornyLimit = 1.0)
    {
        kontroler.setKontroler(kp, ki, kd);
        kontroler.ustawLimity(dolnyLimit, gornyLimit);
    }

    void setARX(const std::vector<double>& a, const std::vector<double>& b, double szum = 0.01)
    {
        model.setModel(a, b, szum);
    }

    void setWartosc(rodzajeWartosci rodzaj, double max, int okres)
    {
        wartosc.setWart(rodzaj, max, okres);
    }

    void zapiszPlik(const std::string& nazwaPlikuARX, const std::string& nazwaPlikuPID, const std::string& nazwaPlikuWartosc)
    {
        model.zapiszText(nazwaPlikuARX);
        kontroler.zapiszText(nazwaPlikuPID);
        wartosc.zapiszText(nazwaPlikuWartosc);
    }
    void wczytajPlik(const std::string& nazwaPlikuARX, const std::string& nazwaPlikuPID, const std::string& nazwaPlikuWartosc)
    {
        model.wczytajText(nazwaPlikuARX);
        kontroler.wczytajText(nazwaPlikuPID);
        wartosc.wczytajText(nazwaPlikuWartosc);
    }
    double symulacja(size_t krok)
    {

        wartoscZadana = wartosc.obliczWartosc(krok);
        double sygnalKontrolny = kontroler.oblicz(wartoscZadana, wartoscProcesu);
        wartoscProcesu = model.krok(sygnalKontrolny);
        /*
            std::cerr << "Krok: " << i
                << " -> Sterowanie: " << sygnalKontrolny
                << " Wyjscie: " << wartoscProcesu
                << std::endl;
                */
        obliczone = wartoscProcesu;
        return obliczone;
    }

    void reset(){
        kontroler.reset();
        model.reset();
        wartoscProcesu = 0.0;
        obliczone = 0.0;
        wartoscZadana=0.0;
    }

    int get_rodzajLiczba() const { return wartosc.get_rodzajLiczba();}
    double get_max() const{return wartosc.get_max();}
    double get_kp() const{return kontroler.get_kp();}
    double get_ki() const{return kontroler.get_ki();}
    double get_kd() const{return kontroler.get_kd();}
    double get_dolnyLimit() const{return kontroler.get_dolnyLimit();}
    double get_gornyLimit() const{return kontroler.get_gornyLimit();}
    double get_lastA() const{return model.get_lastA();}
    double get_lastB() const{return model.get_lastB();}
    int get_okres() const{return wartosc.get_okres();}
    double get_wartoscZadana() const{return wartoscZadana;}
private:
    ARXModel model;
    PIDController kontroler;
    WartZadana wartosc;
    double wartoscProcesu = 0.0;
    double wartoscZadana = 0.0;
    double obliczone;
};


#include "NPV.h"
#include <cstdlib>
#include <iostream>
#include <climits>

NPV::NPV() {

    irate = 0.042; //memberinitalizer_list
    inv = std::vector<double> {};
    
}

void NPV::zahlenreihe(int x) {

    int zahl{0};

    for (int i = 0; i < x; i++) {
        std::cout << "Zahl eingeben:" << std::endl;
        std::cin >> zahl;
        if (!zahl) {
            throw std::string{"Only integers allowed!"};
        }
        if (zahl > INT_MAX) {
            throw std::string{"Entered number is out of range!"};
        }
        inv.push_back(zahl);
    }
}

void NPV::zinssatz(double x) {
    if (!x) {
        throw std::string{"Only floating points allowed!"};
    }
    irate = x;
}

void NPV::berechnen() {

    double wert{0.0};
    double jahresiratewert{0.0};
    int counter{1};
    if (inv.size() != 0) {
        std::cout << "Der Kapitalwert wird nun berechnet:" << std::endl;
        for (int a = 0; a < inv.size(); a++) {
            for (int b = 0; b < counter; b++) {
                if (b == 0) {
                    jahresiratewert = 1.0;
                } else {
                    jahresiratewert = jahresiratewert * (1 + irate);
                }
            }
            wert = wert + (inv[a] / jahresiratewert);
            counter++;
        }
        std::cout << "C0: " << wert << std::endl;
    } else {
        std::cout << "Es wurden noch keine Werte für die Berechnung eingegeben!" << std::endl;
    }
}

void NPV::randomzahlen() {
    double iratewert = 0.0;
    int zahl = 0;

    std::cout << "Es wird eine Zahlenreihe von 10 Zufallszahlen generiert und in der Liste abgespeichert!" << std::endl;


    for (int i = 0; i < 10; i++) {
        zahl = (rand() % 100) + 1;
        inv.push_back(zahl);
    }

    std::cout << "Es wird ein automatisch generierter Zinssatz erzeugt und der Kapitalwert berechnet:" << std::endl;
    irate = (rand() / RAND_MAX);
    berechnen();
}
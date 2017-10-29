/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: max
 *
 * Created on 12. Oktober 2017, 09:05
 */

#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include "NPV.h"
#include <climits>
#include <cfloat>
#include <limits>

using namespace std;

/*
 * 
 */
int main() {
    try {
        srand(time(NULL));
        char eingabe{'a'};
        double zins{0.042};
        int anzahl{0};
        NPV kapital;
        do {

            cout << "Menü:" << endl;
            cout << "1. Zahlen in Zahlenreihe eingeben (a)" << endl;
            cout << "2. Zinssatz eingeben in Gleitkommaform angeben (Bsp.: 0.0143 = 1.43%) (b)" << endl;
            cout << "3. Kapitalwert berechnen (c)" << endl;
            cout << "4. 10 Zufallszahlen generieren und berechnen (d)" << endl;
            cout << "5. Beenden (x)" << endl;
            cin >> eingabe; //if(!cin) einfügen
            if (eingabe != 'a' && eingabe != 'b' && eingabe != 'c' && eingabe != 'd' && eingabe != 'x') {
                throw string{"Use only available chars for input!"};
            } else {
                switch (eingabe) {



                    case 'a':
                        cout << "Wieviele Zahlen möchten Sie in die Zahlenreihe eingeben?" << endl;
                        cin >> anzahl;
                        if (!anzahl) {
                            throw string{"Only integers allowed!"};
                        }
                        if (anzahl > INT_MAX || anzahl < INT_MIN) {
                            throw string{"Entered number is out of range!"};
                        }
                        kapital.zahlenreihe(anzahl);
                        break;
                    case 'b':
                        cout << "Geben Sie den gewünschten Zinssatz in Gleitkommaform an (Bsp.: 0.0143 = 1.43%)" << endl;
                        cin >> zins;
                        if (zins > numeric_limits<double>::max() || zins < numeric_limits<double>::lowest()) {
                            throw string{"Entered number is out of range!"};
                        }
                        kapital.zinssatz(zins);
                        break;
                    case 'c':
                        kapital.berechnen();
                        break;
                    case 'd':
                        kapital.randomzahlen();
                        break;
                    case 'x':
                        break;
                }
            }
            cin.clear();
        } while (eingabe != 'x');
    } catch (string& s) {
        cerr << s; //Meldung und Programmende
        return -1;
    }
    return 0;
}


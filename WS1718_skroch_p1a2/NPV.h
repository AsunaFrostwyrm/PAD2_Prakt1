/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPV.h
 * Author: max
 *
 * Created on 12. Oktober 2017, 09:10
 */

#ifndef NPV_H
#define NPV_H
#include <vector>


class NPV{
public:
    NPV(); //Constructor
    void zahlenreihe(int x);
    void zinssatz(double x);
    void berechnen();
    void randomzahlen();
    
private:
    std::vector<double> inv;
    double irate;
};


#endif /* NPV_H */


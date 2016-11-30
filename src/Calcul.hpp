/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calcul.hpp
 * Author: mignotju
 *
 * Created on November 30, 2016, 6:47 PM
 */
#include "pnl/pnl_random.h"
#include "pnl/pnl_matrix.h"
#include "pnl/pnl_vector.h"

#ifndef CALCUL_HPP
#define CALCUL_HPP


class Calcul {
public:
    Calcul();
    Calcul(const Calcul& orig);
    virtual ~Calcul();
    void shiftAsset(PnlMat* shiftPlus_, PnlMat* path_, int i, double h, double t, double H);
    double payoff(PnlMat* mat);
    void asset(PnlMat* path_, double t, double T, int nbTimeSteps_, PnlRng* rng_, const PnlMat *past);
    void asset(PnlMat* path_, double T, int nbTimeSteps_, PnlRng* rng_);
private:

};

#endif /* CALCUL_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Couverture.hpp
 * Author: mignotju
 *
 * Created on November 30, 2016, 6:47 PM
 */

#include "pnl/pnl_random.h"
#include "pnl/pnl_matrix.h"
#include "pnl/pnl_vector.h"
#include "Calcul.hpp"

#ifndef COUVERTURE_HPP
#define COUVERTURE_HPP

class Couverture {
public:
    Couverture();
    Couverture(const Couverture& orig);
    virtual ~Couverture();
    void delta(const PnlMat *past, double t, PnlVect *delta);
    
    double fdStep_; /*! pas de différence finie */
    size_t nbSamples_; /*! nombre de tirages Monte Carlo */
    Calcul* calculUtils; 
    PnlMat *path_;
    double T; // Maturité
    int nbTimeSteps_; /// nombre de pas de temps de discrétisation
    PnlRng* rng_;
    int size; // dimension du modèle
    PnlMat *shiftPlus_;
    PnlMat *shiftMoins_;
    double r_;
private:

};

#endif /* COUVERTURE_HPP */


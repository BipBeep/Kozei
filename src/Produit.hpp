/* 
 * File:   Produit.hpp
 * Author: lucas
 *
 * Created on December 12, 2016, 3:39 PM
 */
#include "pnl/pnl_random.h"

#ifndef PRODUIT_HPP
#define	PRODUIT_HPP

class Produit {
    // Methodes    
    virtual void simuler(PnlMat *path, double T, int nbTimeSteps, PnlRng *rng) = 0;
    // Calcul du payoff du produit
    virtual double payoff(const PnlMat *path) = 0;
};


#endif	/* PRODUIT_HPP */


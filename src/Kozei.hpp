/* 
 * File:   Kozei.hpp
 * Author: lucas
 *
 * Created on December 12, 2016, 3:06 PM
 */

#include "pnl/pnl_matrix.h"
#include "Produit.hpp"

#ifndef KOZEI_HPP
#define	KOZEI_HPP

class Kozei : public Produit {
public:
    int nbActions;
    
    Kozei();
    Kozei(const Kozei& orig);
    virtual ~Kozei();
    
    // Equivalent de asset
    virtual void simuler(PnlMat *path, double T, int nbTimeSteps, PnlRng *rng);
    
    // Calcul du payoff du produit
    virtual double payoff(const PnlMat *path);
private:

};

#endif	/* KOZEI_HPP */


/* 
 * File:   Kozei.cpp
 * Author: lucas
 * 
 * Created on December 12, 2016, 3:06 PM
 */

#include "Kozei.hpp"

Kozei::Kozei() {

}

Kozei::Kozei(const Kozei& orig) {
}

Kozei::~Kozei() {
}

double Kozei::payoff(const PnlMat* path) {
    double flux = 0;
    PnlVect *cours0 = pnl_vect_create(path->n);
    // Cours en 0 pour calculer performance
    pnl_mat_get_row(cours0, path, 0);
    
    PnlVect *perf_tmp = pnl_vect_create(path->n);
    double perf = 0;
    for (int i = 0; i < path->m; i++) {
        pnl_mat_get_row(perf_tmp, path, i);
        pnl_vect_minus_vect(perf_tmp, cours0);
        pnl_vect_div_vect_term(perf_tmp, cours0);
        // On ajoute à la performance totale, la moyenne des performances des titres a chaque date de constatation
        // Seulement si c'est positif
        if (pnl_vect_sum(perf_tmp)/path->n > 0)
            perf += pnl_vect_sum(perf_tmp)/path->n;
    }
    return perf/(path->m-1);
}

void Kozei::simuler(PnlMat* path, double T, int nbTimeSteps, PnlRng* rng) {
    return;
}
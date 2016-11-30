/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Couverture.cpp
 * Author: mignotju
 * 
 * Created on November 30, 2016, 6:03 PM
 */

#include "Couverture.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Recuperer les donnees (simulees avec asset dans CALCUL)
 * Calcul delta
 * calcul intervalle de confiance
 */

Couverture::Couverture() {
    fdStep_ = 0.01;
    nbSamples_ = 50000;
    calculUtils = new Calcul();
}

Couverture::Couverture(const Couverture& orig) {
}

Couverture::~Couverture() {
}


void Couverture::delta(const PnlMat *past, double t, PnlVect *delta) {
    double h = fdStep_;
    double payoff = 0;
    double prec = 0;

    PnlVect *sum_square = pnl_vect_create_from_zero(delta->size);
    PnlVect *ic = pnl_vect_create_from_zero(delta->size);

    pnl_vect_set_all(delta, 0);
    // Moyenne des payoffs
    for (int j = 0; j < nbSamples_; j++) {
        // Simulation du path
        if (t == 0) {
            this->calculUtils->asset(path_, this->T, this->nbTimeSteps_, rng_);
        } else {
            this->calculUtils->asset(path_, t, this->T, this->nbTimeSteps_, rng_, past);
        }

        // Shift_path
        for (int i = 0; i < this->size; i++) {
            // Création des trajectoires shiftées
            this->calculUtils->shiftAsset(shiftPlus_, path_, i, h, t, this->T / this->nbTimeSteps_);
            this->calculUtils->shiftAsset(shiftMoins_, path_, i, -h, t, this->T / this->nbTimeSteps_);
            payoff = this->calculUtils->payoff(shiftPlus_) - this->calculUtils->payoff(shiftMoins_);
            prec = pnl_vect_get(delta, i);
            pnl_vect_set(delta, i, prec + payoff);

            //pour l'intervalle de confiance
            pnl_vect_set(sum_square, i, pnl_vect_get(sum_square, i) + pow(payoff, 2));
        }
    }
    //Pour l'intervalle de confiance en 0
    if (t == 0) {
        for (int i = 0; i < this->size; i++) {
            pnl_vect_set(ic, i, sqrt((pnl_vect_get(sum_square, i) / nbSamples_) - (pow(pnl_vect_get(delta, i), 2) / pow(nbSamples_, 2))));
        }
    }

    double coeff = exp(-r_ * (T - t)) / (2 * nbSamples_ * h);

    pnl_vect_mult_scalar(ic, 2 * coeff * nbSamples_ * 1.96 / sqrt(nbSamples_));
    pnl_vect_mult_scalar(delta, coeff);
    PnlVect *copy = pnl_vect_create_from_zero(past->n);
    pnl_mat_get_row(copy, past, past->m - 1);

    pnl_vect_div_vect_term(delta, copy);

    pnl_vect_div_vect_term(ic, copy);
    if (t == 0) {
        cout << "largeur des intervalles de confiance pour DELTA en t=0 : " << endl;
        pnl_vect_print(ic);
    }

    pnl_vect_free(&copy);
    pnl_vect_free(&sum_square);
    pnl_vect_free(&ic);

}

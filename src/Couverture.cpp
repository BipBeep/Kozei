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

#include "Couverture.h"

/**
 * Recuperer les donnees (simulees avec asset dans CALCUL)
 * Calcul delta
 * calcul intervalle de confiance
 */

Couverture::Couverture() {
}

Couverture::Couverture(const Couverture& orig) {
}

Couverture::~Couverture() {
}


void Couverture::delta(PnlMat* past, PnlVect* delta)

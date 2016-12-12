/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Portefeuille.cpp
 * Author: mignotju
 * 
 * Created on November 30, 2016, 6:02 PM
 */

#include "Portefeuille.hpp"
#include "Kozei.hpp"

Portefeuille::Portefeuille() {
    this->produits = new Kozei();
}

Portefeuille::Portefeuille(const Portefeuille& orig) {
}

Portefeuille::~Portefeuille() {
}

void Portefeuille::price(double& prix) {
    
}
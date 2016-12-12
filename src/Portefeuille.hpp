/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Portefeuille.hpp
 * Author: mignotju
 *
 * Created on November 30, 2016, 6:47 PM
 */
#include "pnl/pnl_matrix.h"
#include "Produit.hpp"
#include "Couverture.hpp"
#include "Calcul.hpp"
#include <iostream>
#include <list>

using namespace std;

#ifndef PORTEFEUILLE_HPP
#define PORTEFEUILLE_HPP

class Portefeuille {
public:
    // Attributs
    Produit* produits;
    Couverture couv;
    Calcul calculs;
    
    // Methodes
    Portefeuille();
    Portefeuille(const Portefeuille& orig);
    virtual ~Portefeuille();
    
    // Prix du portefeuille
    void price(double &prix);
private:

};

#endif /* PORTEFEUILLE_HPP */


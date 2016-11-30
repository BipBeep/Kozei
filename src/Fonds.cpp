/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calcul.cpp
 * Author: mignotju
 *
 * Created on November 30, 2016, 6:02 PM
 */

#include <cstdlib>
#include "Couverture.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    PnlMat * mat = pnl_mat_create(1,1);
    PnlVect * vect = pnl_vect_create(1);
    Couverture* couv = new Couverture();
    couv->delta(mat,0,vect);

    return 0;
}


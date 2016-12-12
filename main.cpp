/* 
 * File:   main.cpp
 * Author: lucas
 *
 * Created on December 12, 2016, 1:53 PM
 */

#include <cstdlib>
#include "src/Portefeuille.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Portefeuille* pf = new Portefeuille();
    PnlMat *path = pnl_mat_create(1, 16);
    double prix;
    pf->price(prix);
    
    cout << "Affichage de la matrice simulée : " << endl;
    pnl_mat_print(path);
    
    return 0;
}


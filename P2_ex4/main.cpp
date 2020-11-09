/* 
 * File:   main.cpp
 * Author: JORGEC
 *
 * Created on 9 de abril de 2020, 16:11
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "LinkedList.h"
#include "Position.h"
#include "NodeList.h"
#include "Registry.h"

using namespace std;

/*1. La complexitat de la inserció ordenada comptant l'hem de recòrrer fins a trobar
 *   el seu lloc corresponen serà de O(n) al pitjor cas.
 * 
  2. Segons els criteris d'eficiència, en el cas d'haver de fer merge dels registres
 *   r1 i r2, si el registre r1 conté menys elements que el r2 m'interessa fer 
 *   r2.merge(r1); ja que vaig iterant pel registre ficat com a paràmetre(r1) i fent
 *   la funció insert() en el registre que executa el mètode(r2). 
 *   El registre que hauré de ficar com a paràmetre sempre ha de ser el que 
 *   menys elements tingui.
/*
 * 
 */
int main(int argc, char** argv) {
    
    Registry reg1;
    reg1.insert("jaja");    
    reg1.insert("zamoa");
    reg1.insert("lama");
    reg1.insert("kaka");
    reg1.insert("barbudo");
    reg1.insert("alba");
    reg1.print();
    
    Registry reg2;
    reg2.insert("pepe");
    reg2.insert("australia");
    reg2.insert("azerbayan");
    reg2.insert("oslo");
    reg2.insert("tolk");
    reg2.print();
    
    if (reg1.operator ==(reg2)) cout << "El reg1 i reg2 són iguals." << endl;
    
    Registry reg3;
    reg3.insert("jaja");    
    reg3.insert("zamoa");
    reg3.insert("lama");
    reg3.insert("kaka");
    reg3.insert("barbudo");
    reg3.insert("alba");
    reg3.print();
    
    if (reg1.operator ==(reg3)) cout << "El reg1 i reg3 són iguals." << endl;
    
    cout << "Barreja de registres reg1 i reg2: " << endl;
    reg1.merge(reg2);
    reg1.print();
    
    return 0;
}



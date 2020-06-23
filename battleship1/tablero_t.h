//
// Created by Fabrizio on 6/22/20.
//

#ifndef BATTLESHIP1_TABLERO_T_H
#define BATTLESHIP1_TABLERO_T_H
#include "controller_t.h"
#include "casilla_t.h"

using table_t = std::vector<std::vector<casilla_t>>;

class tablero_t: public casilla_t {
    table_t table_;
public:
    tablero_t(int);
    void add_ship();
    void print();
};


#endif //BATTLESHIP1_TABLERO_T_H

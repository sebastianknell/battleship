//
// Created by Fabrizio on 6/22/20.
//

#include "tablero_t.h"

tablero_t::tablero_t(int i):casilla_t(i) {
    table_.resize(10,std::vector<casilla_t>(10,0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            table_[i][j].busy = t_bool::FALSE;
            table_[i][j].damaged = t_bool::FALSE;
            table_[i][j].failed = t_bool::FALSE;
            table_[i][j].ship = t_ship::VACIO;
            table_[i][j].value = 0;
        }
    }
}


void tablero_t::print() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            std::cout<<table_[i][j].value;
        }
        std::cout<<std::endl;
    }
}

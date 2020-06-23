//
// Created by Fabrizio on 6/22/20.
//

#ifndef BATTLESHIP1_CASILLA_T_H
#define BATTLESHIP1_CASILLA_T_H

enum class t_bool {TRUE,FALSE};
enum class t_ship {A=4,B=3,S=2,T=1,VACIO};

struct casilla_t {

    t_bool failed;
    t_bool damaged;
    t_bool busy;
    t_ship ship;
    int value;

    casilla_t();
    casilla_t(int i);
};


#endif //BATTLESHIP1_CASILLA_T_H

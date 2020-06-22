//
// Created by Fabrizio on 6/21/20.
//

#ifndef BATTLESHIP1_PLAYER_T_H
#define BATTLESHIP1_PLAYER_T_H
#include "common_types.h"
#include "ship_t.h"

class player_t {
public:
    path_type path_;
    text_type token_;
    text_type prefix_;
    uuint_type next;
    std::vector<ship_t> fleet_;
    player_t(const path_type& ,const text_type& );
};


#endif //BATTLESHIP1_PLAYER_T_H

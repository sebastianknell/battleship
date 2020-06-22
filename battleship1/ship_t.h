//
// Created by Fabrizio on 6/21/20.
//

#ifndef BATTLESHIP1_SHIP_T_H
#define BATTLESHIP1_SHIP_T_H
#include "common_types.h"

class ship_t {
public:
    char ship_type_;
    position_type ship_position_;
    char ship_orientation_;
    ship_t(const char &, const position_type&, const char&);
};


#endif //BATTLESHIP1_SHIP_T_H

//
// Created by Fabrizio on 6/21/20.
//

#include "ship_t.h"

ship_t::ship_t(const char& ship_type, const position_type& ship_position, const char & ship_orientation) {
    ship_type_ = ship_type;
    ship_position_ = ship_position;
    ship_orientation_ = ship_orientation;
}

//
// Created by Fabrizio on 6/22/20.
//

#ifndef BATTLESHIP1_UTILS_H
#define BATTLESHIP1_UTILS_H


#include <type_traits>
#include <random>

template <typename integer_t,typename = std::enable_if_t<std::is_integral<integer_t>::value >>
integer_t rand_int(integer_t first, integer_t last) {
    std::random_device dev;
    std::mt19937_64 eng(dev());
    std::uniform_int_distribution<integer_t> gen{ first, last };
    return gen(eng);
}

#endif //BATTLESHIP1_UTILS_H

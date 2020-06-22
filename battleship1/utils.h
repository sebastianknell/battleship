//
// Created by Fabrizio on 6/22/20.
//

#ifndef BATTLESHIP1_UTILS_H
#define BATTLESHIP1_UTILS_H


#include <type_traits>
#include <random>
#include <ctime>


template <typename integer_t,typename = std::enable_if_t<std::is_integral<integer_t>::value >>
integer_t rand_int(integer_t first, integer_t last) {
    std::random_device dev;
    std::mt19937_64 eng(dev());
    std::uniform_int_distribution<integer_t> gen{ first, last };
    return gen(eng);
}

char rand_char_column(){
    char columns[10] = {'A','B','C','D','E','F','G','H','I','J'};
    return columns[rand_int(0,9)];
}


char rand_char_ship(){
    auto position =  rand()%ships.size();
    auto ship = ships[position];
    //ships.erase(ships.begin() + position);
    return position;
}

char rand_char_orientation(){
    char orientations[2]={'V','H'};
    return orientations[rand_int(0,1)];
}

#endif //BATTLESHIP1_UTILS_H

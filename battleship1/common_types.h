//
// Created by Fabrizio on 6/21/20.
//

#ifndef BATTLESHIP1_COMMON_TYPES_H
#define BATTLESHIP1_COMMON_TYPES_H
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <string_view>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <numeric>
#include <random>
#include <sstream>
#include <future>
#include <optional>
#include <regex>        // regular expression
#include <utility>
#include<filesystem>
#include <type_traits>
#include <queue>
#include <deque>


namespace filesystem = std::filesystem;

using text_type = std::string;
using character_type = char;
using uuint_type = size_t;
using path_type = filesystem::path;
class statement_t ;
using statement_item_type = std::pair<uuint_type ,statement_t>;
using statement_list_type = std::queue<statement_item_type>;
using position_type = std::pair<char,uuint_type>;


class statement_t{
public:
    text_type token_;
    text_type action_;
    text_type message;
};


/*
text_type HANDSHAKE_TEXT = "HANDSHAKE=";
text_type TOKEN_TEXT = "TOKEN=";
text_type PLACEFLEET_TEXT = "PLACEFLEET=";
text_type ATTACK_TEXT = "ATTACK=";

//txt temporales
text_type NOMBRE_PLAYER_TEXT = "RoyalFleet";
*/

#endif //BATTLESHIP1_COMMON_TYPES_H

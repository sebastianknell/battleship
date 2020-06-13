#ifndef TYPES_H
#define TYPES_H

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

namespace filesystem = std::filesystem;
using text_t = std::string;
using position_t = size_t;
using length_t = size_t;
using input_file_t = std::ifstream;
using output_file_t = std::ofstream;
using path_t = filesystem::path;
using uuid_t = size_t;

enum class orientation_t { horizontal = 'H', vertical = 'V'};
enum class status_t { model_full, fleet_full, busy, outside, ok, winner, game_over };
enum class model_t { aircraft_carrier = 'A', battle_cruiser = 'B', submarine = 'S', torped_boat = 'T' };
enum class navy_status_t { healthy, damaged, destroyed };
enum class action_t { start, build, attack };

struct location_t {
    position_t x;
    position_t y;
    bool operator<(const location_t& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

struct dimension_t {
    length_t w;
    length_t h;
};

using model_size_t = std::pair<size_t, dimension_t>;
using rectangle_t = std::pair<location_t, dimension_t>;

#endif
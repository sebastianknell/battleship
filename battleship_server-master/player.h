//
// Created by rudri on 11/15/2019.
//

#ifndef BATTLESHIP_SERVER_PLAYER_H
#define BATTLESHIP_SERVER_PLAYER_H

#include "common_types.h"

extern std::map<model_t, model_size_t> predefined_fleet;

using layout_t = std::map<location_t, bool>;

class navy_t {
private:
    // attributes
    location_t location_;
    navy_status_t status_;
    model_t model_;
    dimension_t dimension_;
    layout_t layout_;
    // methods
    bool is_detroyed();
    // friends
    friend class player_t;
public:
    // constructor
    navy_t(const location_t& location, const model_t& model, const orientation_t& orientation);
    // methods
    navy_status_t get_status();
};

using hit_result_t = std::pair<std::unique_ptr<navy_t>&&, bool>;
using fleet_t = std::vector<std::unique_ptr<navy_t>>;
using fleet_size_t = std::map<model_t, size_t>;

class player_t {
private:
    // attributes
    text_t name_;
    fleet_t fleet_;
    fleet_size_t fleet_size_;
    size_t id_;
    size_t sequence_;
    path_t path_;
    text_t prefix_;

    // methods
    bool is_navy_outside(const rectangle_t& rect, const rectangle_t& battle_field);
    bool is_navy_overlap(const rectangle_t& rect);
    status_t can_add_navy(const model_t& model, const rectangle_t& rect, const rectangle_t& battle_field);
public:
    // constructor
    player_t(const path_t& path, const text_t& prefix);
    // methods
    bool is_fleet_full();
    bool is_model_full(const model_t& model);
    status_t add_navy(const location_t& location, const model_t& model, const orientation_t& orientation, const rectangle_t& battle_field);
    hit_result_t hit_navy(location_t location);
    size_t get_fleet_size();
    void list_fleet();
    size_t get_id();
    void set_id(size_t value);
    text_t get_name();
    void set_name(const text_t& value);
    path_t get_path();
    text_t get_prefix();
    size_t& sequence();
    bool is_fleet_destroyed();
};

#endif //BATTLESHIP_SERVER_PLAYER_H

//
// Created by rudri on 11/15/2019.
//

#include "player.h"

std::map<model_t, model_size_t> predefined_fleet
{
    {model_t::aircraft_carrier, {1, {4, 1}}},
    {model_t::battle_cruiser,   {1, {3, 1}}},
    {model_t::submarine,        {1, {2, 1}}},
    {model_t::torped_boat,      {1, {1, 1}}}
};

layout_t generate_layout(const location_t& l, const dimension_t& d)
{
    layout_t layout;
    for (size_t i = 0; i < d.w; ++i)
        for (size_t j = 0; j < d.h; ++j)
            layout[{l.x + i, l.y + j}] = false;
    return layout;
}

bool is_inside(const location_t& location, const rectangle_t& rectangle)
{
    auto [x, y] = location;
    auto [l, d] = rectangle;
    return (x >= l.x && x < l.x + d.w && y >= l.y && y < l.y + d.h);
}

bool are_intersected(const rectangle_t& r1, const rectangle_t& r2)
{
    if (r1.first.x > r2.first.x + r2.second.w - 1 ||
        r2.first.x > r1.first.x + r1.second.w - 1)
        return false;
    if (r1.first.y > r2.first.y + r2.second.h - 1 ||
        r2.first.y > r1.first.y + r1.second.h - 1)
        return false;
    return true;
}

dimension_t calculate_dimension(const model_t& model, const orientation_t& orientation)
{
    auto dim = predefined_fleet[model].second;
    return orientation == orientation_t::horizontal ?
        dimension_t{ dim.w, dim.h } :
        dimension_t{ dim.h, dim.w };
}

navy_t::navy_t(const location_t& location, const model_t& model, const orientation_t& orientation) :
    location_{ location },
    status_{ navy_status_t::healthy },
    model_{ model },
    dimension_{ calculate_dimension(model, orientation) },
    layout_{ generate_layout(location_, dimension_) }
{
}

navy_status_t navy_t::get_status() { return status_; }

bool navy_t::is_detroyed()
{
    return std::all_of(begin(layout_), end(layout_),
        [](auto status) { return status.second == true; });
}

status_t player_t::can_add_navy(const model_t& model, const rectangle_t& rect, const rectangle_t& battle_field)
{
    if (is_model_full(model))
        return status_t::model_full;
    else if (is_fleet_full())
        return status_t::fleet_full;
    else if (is_navy_outside(rect, battle_field))
        return status_t::outside;
    else if (is_navy_overlap(rect))
        return status_t::busy;
    return status_t::ok;
}

size_t player_t::get_fleet_size() { return fleet_.size(); }

player_t::player_t(const path_t& path, const text_t& prefix):
    id_{0}, sequence_{1}, path_{path}, prefix_{prefix}
{
}

bool player_t::is_fleet_full() {
    auto total = 0u;
    for (const auto m : predefined_fleet)
        total += m.second.first;
    return fleet_.size() == total;
}

bool player_t::is_model_full(const model_t& model) {
    return (fleet_size_[model] + 1 > predefined_fleet[model].first);
}

bool player_t::is_navy_outside(const rectangle_t& rect, const rectangle_t& battle_field)
{
    auto [loc, dim] = rect;
    auto x1 = loc.x;
    auto y1 = loc.y;
    auto x2 = x1 + dim.w - 1;
    auto y2 = y1 + dim.h - 1;
    return !(
        is_inside({ x1, y1 }, battle_field) &&
        is_inside({ x1, y2 }, battle_field) &&
        is_inside({ x2, y1 }, battle_field) &&
        is_inside({ x2, y2 }, battle_field));
}

bool player_t::is_navy_overlap(const rectangle_t& rect)
{
    for (const auto& n : fleet_)
        if (are_intersected(rect, { n->location_, n->dimension_ }))
            return true;
    return false;
}

status_t player_t::add_navy(const location_t& location, const model_t& model,
    const orientation_t& orientation, const rectangle_t& battle_field)
{
    auto d = calculate_dimension(model, orientation);
    auto s = can_add_navy(model, { location, d }, battle_field);
    if (s != status_t::ok) return s;

    fleet_.emplace_back(std::make_unique<navy_t>(location, model, orientation));
    fleet_size_[model]++;
    return s;
}

hit_result_t player_t::hit_navy(location_t location)
{
    for (auto& n : fleet_) {
        if (is_inside(location, { n->location_, n->dimension_ })) {
            n->layout_[location] = true;
            n->status_ = n->is_detroyed() ?
                navy_status_t::destroyed :
                navy_status_t::damaged;
            return { std::move(n), true };
        }
    }
    return { std::unique_ptr<navy_t>(), false };
}

void player_t::list_fleet()
{
    for (const auto& n : fleet_)
        std::cout << "x: " << n->location_.x << " y: " << n->location_.y << '\n';
}

size_t player_t::get_id()
{
    return id_;
}

void player_t::set_id(size_t value)
{
    id_ = value;
}

text_t player_t::get_name()
{
    return name_;
}

void player_t::set_name(const text_t& value)
{
    name_ = value;
}

path_t player_t::get_path()
{
    return path_;
}

text_t player_t::get_prefix()
{
    return prefix_;
}

size_t& player_t::sequence()
{
    return sequence_;
}

bool player_t::is_fleet_destroyed()
{
    return std::all_of(begin(fleet_), end(fleet_),
        [](auto& navy) { return navy->get_status() == navy_status_t::destroyed; });
}

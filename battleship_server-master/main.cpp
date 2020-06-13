#include <iostream>
#include "player.h"
#include "controller.h"

const std::map<navy_status_t, std::string> status{
	{navy_status_t::healthy, "healthy"},
	{navy_status_t::damaged, "damaged"},
	{navy_status_t::destroyed, "destroyed"}
};

int main() {
    controller_t ctrl(10, "J", "first", "second");
    ctrl.execute();
/*
    auto path_ = std::filesystem::current_path();

    std::unique_ptr<player_t> arr[2];

    player_t p1(path_, "FirstPlayer");
	rectangle_t battle_field{ {0, 0}, {10, 10} };
	auto s1_ = p1.add_navy({ 1, 3 },
		model_t::aircraft_carrier,
		orientation_t::horizontal, battle_field);
	auto s2_ = p1.add_navy({ 9, 3 },
		model_t::battle_crusier,
		orientation_t::vertical, battle_field);
	auto s3_ = p1.add_navy({ 5, 5 },
		model_t::submarine,
		orientation_t::vertical, battle_field);
	auto s4_ = p1.add_navy({ 7, 7 },
		model_t::torped_boat,
		orientation_t::vertical, battle_field);
	auto s5_ = p1.add_navy({ 8, 8 },
		model_t::torped_boat,
		orientation_t::vertical, battle_field);

	for (size_t i = 0; i < 4; ++i) {
		auto [navy, is_hit] = p1.hit_navy({ 1 + i, 3 });
		std::cout << "status: " << status[navy->get_status()] << std::endl;
	}

 	if (p1.is_fleet_full())
		std::cout << "fleet has been completed\n";
	p1.list_fleet();
 */
	return 0;
}
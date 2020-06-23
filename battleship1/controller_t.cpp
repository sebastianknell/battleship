//
// Created by Fabrizio on 6/21/20.
//

#include "controller_t.h"
#include "utils.h"
#include "tablero_t.h"
std::string global_token;
std::queue<packet_t> packet_ships;
std::vector<char>ships = {'A','B','B','S','S','S','T','T','T','T'};
uuint_type position_g = 0;

static int TAM = 0;
controller_t::controller_t(const text_type &player_one, const text_type& player_two, const char& columns , const uuint_type& filas){
    players_.push_back(std::make_unique<player_t>(filesystem::current_path() / player_one,"FirstPlayer"));
    players_.push_back(std::make_unique<player_t>(filesystem::current_path() / player_two,"SecondPlayer"));

    TAM = filas;
    for(const auto& player:players_) {
        if(!filesystem::exists(player->path_ /"in")) {
            filesystem::create_directories(player->path_ / "in");
        }
        if(!filesystem::exists(player->path_ / "out")) {
            filesystem::create_directories(player->path_ / "out");
        }
    }
}


void controller_t::start(const statement_item_type &item) {
    //Accediendo al jugador
    auto &player = players_[item.first];    //item.first representa el numbero de jugador que se determinara una vez que se crea
    text_type filename = player->prefix_ + std::to_string(++player->next) + ".in";
    std::ofstream file_write;
    file_write.open(player->path_ / "in" / filename);
    file_write<< "HANDSHAKE=" << "RoyalFleet" ;
}

void controller_t::build(const statement_item_type &item) {

    std::unique_ptr<player_t> &player = players_[item.first];
    std::string token_text = "TOKEN=";
    std::string placefleet_text = "PLACEFLEET=";

    std::string name = player->prefix_ + std::to_string(++player->next) + ".in";
    std::ofstream file_write(player->path_ / "in" / name);
    position_g = rand_char_ship();
    auto ship = ships[position_g];
    auto column = rand_char_column();
    auto row = rand_int(1, TAM);
    /*while(tablero.getTable()[row][column].busy == t_bool::TRUE) {
        column = rand_char_column();
        row = rand_int(1, TAM);
    }*/
    auto orientation = rand_char_orientation();

    packet_ships.push(packet_t(ship,column,row,orientation));
    player->fleet_.emplace_back(ship,std::make_pair(column,row),orientation);
    file_write << token_text<<global_token<<std::endl;
    file_write << placefleet_text<<ship<<"-"<<column<<row<<"-"<<orientation;
}


void controller_t::load_tokens() {
    auto end_ = filesystem::directory_iterator{};
    std::error_code e;
    //while (true) {
        /*try {
            filesystem::directory_iterator first_{ players_[0]->path_ / "in"};
            filesystem::directory_iterator second_{ players_[1]->path_ / "in"};
            while (first_ != end_ || second_ != end_) {
                if (first_ != end_) {
                    statements_.push({ 0u, push_statement(*first_) });
                    filesystem::remove(*first_++, e);
                    if (e)
                        std::cerr << e.message() << "\n";
                }
                if (second_ != end_) {
                    statements_.push({ 1u, push_statement(*second_) });
                    filesystem::remove(*second_++, e);
                    if (e)
                        std::cerr << e.message() << "\n";
                }
            }
        }*/
        int i = 0;
        while( i < TAM) {
            try {
                filesystem::directory_iterator first_{players_[0]->path_ / "out"};
                //while (first_ != end_) {
                if (first_ != end_) {
                    statements_.push({0u, push_statement(*first_)});
                    //filesystem::remove(*first_++, e);
                    if (e)
                        std::cerr << e.message() << "\n";
                }
                //}
            }

            catch (const std::exception &e) {
                std::cerr << e.what();
            }
            ++i;
        }
    //}
}

void controller_t::save_tokens() {
    auto end_ = filesystem::directory_iterator{};
    int i =0;
    while(i < TAM ) {
        //while (true) {
        try {
            while (!statements_.empty()) {
                auto item = statements_.front();
                statements_.pop();
                if (item.second.action_ == "start")
                    start(item);

                else if (item.second.action_ == "build")
                    build(item);
            }
        }
        catch (const std::exception &e) {
            std::cerr << e.what();
        }
    ++i;
    }
    //}
}


void controller_t::execute(){
    //auto load_ = std::async([&] { load_tokens(); });
    //auto save_ = std::async([&] { save_tokens(); });
    load_tokens();
    save_tokens();
}

statement_t controller_t::push_statement(const filesystem::path &entry) {
    std::ifstream file_read;
    file_read.open(entry.generic_string());

    if (!file_read.is_open())
        throw std::runtime_error("no open");


    std::string line;
    std::string line_status,status;
    std::string line_token,token;
    std::string line_message,message;



    std::getline(file_read,line);

    statement_t statement;

    if(line == "HANDSHAKE"){
        std::getline(file_read,line_status);
        std::getline(file_read,line_token);

        status = line_status.substr(line_status.find('=')+1);
        token = line_token.substr(line_token.find('=')+1);
        if(status == "ACCEPTED") {
            statement.token_ = token;
            global_token = token;
            statement.action_ = "build";
        }
        else if(status == "REJECTED"){
            statement.action_ = "start";
        }

    }else if (line == "PLACEFLEET"){
        std::getline(file_read,line_status);
        std::getline(file_read,line_message);
        status = line_status.substr(line_status.find('=')+1);
        message = line_message.substr(line_message.find('=')+1);
        if(status == "ACCEPTED"){
            statement.message = message;
            if(message == "FULL"){
                statement.action_ = "attack";
            }
            else if(message == "CONTINUE"){
                statement.action_ = "build";
                ships.erase(ships.begin() + position_g );
            }else{
                statement.action_ = "build";
            }
        }
        else if(status == "REJECTED"){

            statement.action_ = "build";
        }
    }
    file_read.close();
    return statement;
}




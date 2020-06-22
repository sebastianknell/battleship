//
// Created by Fabrizio on 6/21/20.
//

#ifndef BATTLESHIP1_CONTROLLER_T_H
#define BATTLESHIP1_CONTROLLER_T_H
#include "common_types.h"
#include "player_t.h"
#include "utils.h"

using players_type = std::vector<std::unique_ptr<player_t>>;

extern std::string global_token;



class controller_t {
private:
    players_type players_;
    uuint_type nrows_;
    character_type ncolumns_;
    statement_list_type statements_;

    void start(const statement_item_type &);
    void build(const statement_item_type &);
    statement_t push_statement(const path_type &);

public:
    controller_t(const text_type&,const text_type&, const char&, const uuint_type&);
    void load_tokens();
    void save_tokens();
    void execute() ;

};


#endif //BATTLESHIP1_CONTROLLER_T_H

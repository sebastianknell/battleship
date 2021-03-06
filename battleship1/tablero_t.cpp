//
// Created by Fabrizio on 6/22/20.
//

#include "rlutil.h"
#include "tablero_t.h"

tablero_t::tablero_t(int i):casilla_t(i) {
    table_.resize(10,std::vector<casilla_t>(10,0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            table_[i][j].busy = t_bool::FALSE;
            table_[i][j].damaged = t_bool::FALSE;
            table_[i][j].failed = t_bool::FALSE;
            table_[i][j].ship = t_ship::VACIO;
            table_[i][j].value = '0';
        }
    }
}

void tablero_t::add_ship() {
    while(!packet_ships.empty()){
        auto item = packet_ships.front();
        packet_ships.pop();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10 ; ++j) {
                if(item.ship_type_ == 'A') {
                    if (item.orientation_ == 'V') {
                        if(item.row_+3 < 10){
                            if(i >= item.row_-1 && i <=  item.row_+3-1 && table_[i][j].busy == t_bool::FALSE && j == (item.column_)-64-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::A;
                                table_[i][j].value = 'A';
                            }
                        }
                    }
                    else if (item.orientation_ == 'H') {
                        if((item.column_+3)-64 < 10){
                            if( j >= (item.column_)-64-1 && j <= (item.column_-64+3)-1 && table_[i][j].busy == t_bool::FALSE && i == item.row_-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::A;
                                table_[i][j].value = 'A';
                            }
                        }
                    }
                }
                else if(item.ship_type_ == 'B'){
                    if (item.orientation_ == 'V') {
                        if(item.row_+2 < 10){
                            if(i >= item.row_-1 && i <=  item.row_+2-1 && table_[i][j].busy == t_bool::FALSE && j == (item.column_)-64-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::B;
                                table_[i][j].value = 'B';
                            }
                        }
                    }
                    else if (item.orientation_ == 'H') {
                        if((item.column_+2)-64 < 10){
                            if( j >= (item.column_)-64-1 && j <= (item.column_-64+2)-1 && table_[i][j].busy == t_bool::FALSE && i == item.row_-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::B;
                                table_[i][j].value = 'B';
                            }
                        }
                    }
                }

                else if (item.ship_type_ == 'S'){
                    if (item.orientation_ == 'V') {
                        if(item.row_+1 < 10){
                            if(i >= item.row_-1 && i <=  item.row_+1-1 && table_[i][j].busy == t_bool::FALSE && j == (item.column_)-64-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::S;
                                table_[i][j].value = 'S';
                            }
                        }
                    }
                    else if (item.orientation_ == 'H') {
                        if((item.column_+1)-64 < 10){
                            if( j >= (item.column_)-64-1 && j <= (item.column_-64+1)-1 && table_[i][j].busy == t_bool::FALSE && i == item.row_-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::S;
                                table_[i][j].value = 'S';
                            }
                        }
                    }
                }
                else if(item.ship_type_ == 'T'){
                    if (item.orientation_ == 'V') {
                        if(item.row_ < 10){
                            if(i >= item.row_-1 && i <=  item.row_-1 && table_[i][j].busy == t_bool::FALSE && j == (item.column_)-64-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::T;
                                table_[i][j].value = 'T';
                            }
                        }
                    }
                    else if (item.orientation_ == 'H') {
                        if((item.column_)-64 < 10){
                            if( j >= (item.column_)-64-1 && j <= (item.column_-64)-1 && table_[i][j].busy == t_bool::FALSE && i == item.row_-1 ) {
                                table_[i][j].busy = t_bool::TRUE;
                                table_[i][j].ship = t_ship::T;
                                table_[i][j].value = 'T';
                            }
                        }
                    }
                }
            }
        }
    }
}

/*
uuint_type convert_char_to_uuint(const char &e){
    uuint_type i {};
    if(e == 'A'){
        i = 1;
    }
    else if(e == 'B'){
        i == 2;
    }
    else if (e == 'C'){
        i = 3;
    }
}*/

void tablero_t::print() 
{
    rlutil::setColor(7);
    std::cout << "   A B C D E F G H I J" << std::endl;
    for (int i = 0; i < 10; ++i) 
    {
        rlutil::setColor(7);
        std::cout << i+1 << " ";
        if  (i < 9)
        {
            std::cout << " ";
        }
        
        for (int j = 0; j < 10 ; ++j) 
        {
            rlutil::setColor(15);
            if (table_[i][j].value == 'A')
            {
                rlutil::setColor(10);
            }
            
            else if (table_[i][j].value == 'B')
            {
                rlutil::setColor(11);
            }
            
            else if (table_[i][j].value == 'S')
            {
                rlutil::setColor(14);
            }      
            
            else if (table_[i][j].value == 'T')
            {
                rlutil::setColor(13);
            }            
            std::cout << table_[i][j].value << " ";
        }
        std::cout << std::endl;
    }
}

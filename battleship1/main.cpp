#include <iostream>
#include "controller_t.h"
#include "tablero_t.h"

using namespace std;
int main() {

    srand(time(NULL));
    controller_t controller("firstPlayer","secondPlayer",'J',2);
    controller.execute();
    /*while(!packet_ships.empty()){
        auto item = packet_ships.front();
        cout<<item.ship_type_<<"-"<<item.column_<<item.row_<<"-"<<item.orientation_<<std::endl;
        packet_ships.pop();
    }*/

    tablero_t tablero(0);
    tablero.add_ship();
    tablero.print();

    return 0;
}


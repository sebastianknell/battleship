#include <iostream>
#include "controller_t.h"


using namespace std;
int main() {
    controller_t controller("firstPlayer","secondPlayer",'J',10);
    controller.execute();
    while(!packet_ships.empty()){
        auto item = packet_ships.front();
        cout<<item.ship_type_<<"-"<<item.column_<<item.row_<<"-"<<item.orientation_<<std::endl;
        packet_ships.pop();
    }



    return 0;
}


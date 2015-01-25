//Author: Wojciech Ceret
//Represent move object on the board
#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"
#include "../../view/items/truckcaritem.h"

struct Truck : public Vehicle {
    Truck(int id, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
       Vehicle(id, speed, start_point, target_point)
    {}

    ITrafficParticipantItem* createItem(const QRectF& rect) {
        return new TruckCarItem(rect);
    }
};

#endif // TRUCK_H

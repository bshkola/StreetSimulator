//Author: Wojciech Ceret
//Represent move object on the board
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include "../../view/items/passengercaritem.h"

struct Car : public Vehicle {
    Car(int id, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
       Vehicle(id, speed, start_point, target_point) {
    }
    ITrafficParticipantItem* createItem(const QRectF& rect) {
        return new PassengerCarItem(rect);
    }
};

#endif // CAR_H

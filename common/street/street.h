//Author: Wojciech Ceret
//Represent streen on the board
#ifndef STREET_H
#define STREET_H

#include "../direction.h"

struct Street {
    Direction direction;
protected:
    Street() {};
};

#endif // STREET_H

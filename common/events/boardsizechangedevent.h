//Author: Bogdan Shkola
//Event got when board size is changed
#ifndef BOARDSIZECHANGEDEVENT_H
#define BOARDSIZECHANGEDEVENT_H

#include "ievent.h"

class BoardSizeChangedEvent : public IEvent
{
public:
    BoardSizeChangedEvent(int boardSize);
    std::string getName();
    int getBoardSize();
private:
    int boardSize_;
};

#endif // BOARDSIZECHANGEDEVENT_H

#include "boardsizechangedevent.h"

BoardSizeChangedEvent::BoardSizeChangedEvent(int boardSize) : boardSize_(boardSize)
{
}

std::string BoardSizeChangedEvent::getName()
{
    return "BoardSizeChanged";
}

int BoardSizeChangedEvent::getBoardSize()
{
    return boardSize_;
}

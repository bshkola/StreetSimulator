#ifndef IVIEW_H
#define IVIEW_H

#include "../common/board.h"

class IView
{
public:
    IView();
    virtual void show() = 0;
    virtual void showBoard(const Board& board) = 0;
};

#endif // IVIEW_H

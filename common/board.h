#ifndef BOARD_H
#define BOARD_H

#include <QObject>

class Board
{
public:
    Board() {}
    Board(int size);

    bool** boardMap_;
    int size_;
};

#endif // BOARD_H

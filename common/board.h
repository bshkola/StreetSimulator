#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    Board() {}
    Board(int size);

    bool** boardMap_;
    int size_;
};

#endif // BOARD_H

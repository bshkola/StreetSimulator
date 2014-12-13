#include "board.h"

Board::Board(int size) : size_(size)
{
    boardMap_ = new bool*[size_];
    for (int i = 0; i < size_; ++i) {
        boardMap_[i] = new bool[size_];
    }

    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            boardMap_[i][j] = false;
        }
    }
}

#include "board.h"

bool cellArray = false;

bool should_cell_be_alive(bool currentState, int liveNeighbors){
    if ((currentState && liveNeighbors==2) || liveNeighbors==3){
        return true;
    }
    return false;
}

bool get_status(int board_row, int board_column)
{
    return cellArray;
}

void set_status(int board_row, int board_column, bool futureStatus){
    cellArray = futureStatus;
}
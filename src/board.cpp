#include "board.h"

bool cellArray[32][64];

void initializeBoard(){
    for(int i = 0; i < 32; i++){
        for (int j = 0; j < 64; j++){
            cellArray[i][j] = false;
        }
    }
}

bool should_cell_be_alive(bool currentState, int liveNeighbors){
    if ((currentState && liveNeighbors==2) || liveNeighbors==3){
        return true;
    }
    return false;
}

bool get_status(int board_row, int board_column)
{
    return cellArray[board_row][board_column];
}

void set_status(int board_row, int board_column, bool futureStatus){
    cellArray[board_row][board_column] = futureStatus;
}
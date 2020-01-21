#include "board.h"


bool should_cell_be_alive(bool currentState, int liveNeighbors){
    if ((currentState && liveNeighbors==2) || liveNeighbors==3){
        return true;
    }
    return false;
}
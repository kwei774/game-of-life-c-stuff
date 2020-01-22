#ifndef _BOARD_H_
#define _BOARD_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>
    extern bool cellArray[32][64];

    void initializeBoard();
    bool should_cell_be_alive(bool, int);
    bool get_status(int, int);
    void set_status(int, int, bool);
    int get_alive_neighbors(int, int);

#ifdef __cplusplus
}
#endif

#endif
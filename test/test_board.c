#include "unity_fixture.h"
#include "board.h"
#include "Arduino.h"
#include <stdbool.h>

TEST_GROUP(Board);

TEST_SETUP(Board) {}

TEST_TEAR_DOWN(Board) {}

TEST(Board, live_cell_with_fewer_than_2_alive_neighbors_returns_dead){
    TEST_ASSERT_FALSE(should_cell_be_alive(true, 0));
    TEST_ASSERT_FALSE(should_cell_be_alive(true, 1));
}

TEST(Board, live_cell_with_2or3_alive_neighbors_returns_alive){
    TEST_ASSERT_TRUE(should_cell_be_alive(true, 2));
    TEST_ASSERT_TRUE(should_cell_be_alive(true, 3));
}

TEST(Board, dead_cell_with_2_alive_neighbors_returns_dead){
    TEST_ASSERT_FALSE(should_cell_be_alive(false, 2));
}

TEST(Board, board_initializes_as_all_dead){
    initializeBoard();
    TEST_ASSERT_FALSE(get_status(0, 0));
    TEST_ASSERT_FALSE(get_status(31, 63));
}

TEST(Board, set_board_single_cell_value){
    initializeBoard();
    TEST_ASSERT_FALSE(get_status(0, 0));
    set_status (0,0,true);
    TEST_ASSERT_TRUE(get_status(0, 0));
}

TEST(Board, set_board_with_multiple_cells){
    initializeBoard();
    TEST_ASSERT_FALSE(get_status(0, 0));
    TEST_ASSERT_FALSE(get_status(31, 63));
    set_status(0, 0, true);
    TEST_ASSERT_TRUE(get_status(0, 0));
    TEST_ASSERT_FALSE(get_status(31, 64));

}

TEST_GROUP_RUNNER(Board)
{
    RUN_TEST_CASE(Board, live_cell_with_2or3_alive_neighbors_returns_alive)
    RUN_TEST_CASE(Board, live_cell_with_fewer_than_2_alive_neighbors_returns_dead)
    RUN_TEST_CASE(Board, dead_cell_with_2_alive_neighbors_returns_dead)
    RUN_TEST_CASE(Board, board_initializes_as_all_dead)
    RUN_TEST_CASE(Board, set_board_single_cell_value)
    RUN_TEST_CASE(Board, set_board_with_multiple_cells)
}
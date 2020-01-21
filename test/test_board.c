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

TEST_GROUP_RUNNER(Board)
{
    RUN_TEST_CASE(Board, live_cell_with_2or3_alive_neighbors_returns_alive)
    RUN_TEST_CASE(Board, live_cell_with_fewer_than_2_alive_neighbors_returns_dead)
    RUN_TEST_CASE(Board, dead_cell_with_2_alive_neighbors_returns_dead)
}
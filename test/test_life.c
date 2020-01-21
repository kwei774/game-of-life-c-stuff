#include "unity_fixture.h"
#include "life.h"
#include "Arduino.h"
#include <stdbool.h>

TEST_GROUP(Life);

TEST_SETUP(Life) {}

TEST_TEAR_DOWN(Life) {}

TEST(Life, lifesetup_seeds_srand_from_analogRead)
{
    analogRead_will_return(17);

    life_setup(NULL);
    TEST_ASSERT_EQUAL_INT(17, srand_called_with());
}

TEST(Life, live_cell_with_fewer_than_2_alive_neighbors_returns_dead){
    TEST_ASSERT_FALSE(should_cell_be_alive(true, 0));
    TEST_ASSERT_FALSE(should_cell_be_alive(true, 1));
}

TEST(Life, live_cell_with_2or3_alive_neighbors_returns_alive){
    TEST_ASSERT_TRUE(should_cell_be_alive(true, 2));
    TEST_ASSERT_TRUE(should_cell_be_alive(true, 3));
}

TEST(Life, dead_cell_with_2_alive_neighbors_returns_dead){
    TEST_ASSERT_FALSE(should_cell_be_alive(false, 2));
}

TEST_GROUP_RUNNER(Life)
{
    RUN_TEST_CASE(Life, lifesetup_seeds_srand_from_analogRead)
    RUN_TEST_CASE(Life, live_cell_with_2or3_alive_neighbors_returns_alive)
    RUN_TEST_CASE(Life, live_cell_with_fewer_than_2_alive_neighbors_returns_dead)
    RUN_TEST_CASE(Life, dead_cell_with_2_alive_neighbors_returns_dead)
    // RUN_TEST_CASE(Life, dead_cell_with_3_alive_neighbors_returns_alive)
}

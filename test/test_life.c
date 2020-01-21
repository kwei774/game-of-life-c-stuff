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

TEST_GROUP_RUNNER(Life)
{
    RUN_TEST_CASE(Life, lifesetup_seeds_srand_from_analogRead)
}

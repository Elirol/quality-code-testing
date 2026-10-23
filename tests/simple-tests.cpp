#include "function.h"
#include "catch2/catch_test_macros.hpp"

SCENARIO("Basic condition coverage", "[condition_function]") {

    GIVEN("Test 1: a = 5, b = 3 (a > 0: T, a < b: F, b < 10: T, b < a: T)") {
        int a = 5;
        int b = 3;

        WHEN("The function is called") {
            char result = condition_function(a, b);

            THEN("The result should be 1") {
                REQUIRE(result == 1);
            }
        }
    }

    GIVEN("Test 2: a = 0, b = 10 (a > 0: F, a < b: T, b < 10: F, b < a: F)") {
        int a = 0;
        int b = 10;

        WHEN("The function is called") {
            char result = condition_function(a, b);

            THEN("The result should be 0") {
                REQUIRE(result == 0);
            }
        }
    }
}
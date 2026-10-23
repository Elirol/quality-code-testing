#include "function.h"
#include "catch2/catch_test_macros.hpp"

SCENARIO("MC/DC tests", "[condition_function]") {

    GIVEN("CASE 1: a = 5, b = 5") {
        int a = 5;
        int b = 5;

        WHEN("a > 0 is true, a < b is false, b < 10 is true, b < a is false") {
            REQUIRE(condition_function(a, b) == 0);
        }
    }

    GIVEN("CASE 2: a = 1, b = 5") {
        int a = 1;
        int b = 5;

        WHEN("a > 0 is true, a < b is true, b < 10 is true, b < a is false") {
            REQUIRE(condition_function(a, b) == 1);
        }
    }

    GIVEN("CASE 3: a = 0, b = 5") {
        int a = 0;
        int b = 5;

        WHEN("a > 0 is false, a < b is true, b < 10 is true, b < a is false") {
            REQUIRE(condition_function(a, b) == 0);
        }
    }

    GIVEN("CASE 4: a = 5, b = 3") {
        int a = 5;
        int b = 3;

        WHEN("a > 0 is true, a < b is false, b < 10 is true, b < a is true") {
            REQUIRE(condition_function(a, b) == 1);
        }
    }

    GIVEN("CASE 5: a = 15, b = 12") {
        int a = 15;
        int b = 12;

        WHEN("a > 0 is true, a < b is false, b < 10 is false, b < a is true") {
            REQUIRE(condition_function(a, b) == 0);
        }
        
    }

}
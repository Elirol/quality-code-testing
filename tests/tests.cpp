#include <time.h>

#include "passwords.h"
#include "catch2/catch_test_macros.hpp"

SCENARIO("P1: Generating a password with NULL pointer to allowed symbols", "[passwords]") {
    
    srand((unsigned int) time(NULL)); // Seed the random number generator

    GIVEN("On case: NULL pointer to allowed symbols and 5 length") {
        const char* symbols = NULL;
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    GIVEN("Off case: Empty string for allowed symbols and 5 length") {
        const char* symbols = "";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    // No In or Out case exist since we are using a pointer - it is either valid or NULL.

}

SCENARIO("P2: Generating a password with an empty allowed symbols string.", "[passwords]") {
    
    srand((unsigned int) time(NULL)); // Seed the random number generator

    GIVEN("On case: An empty string for allowed symbols and 5 length") {
        const char* symbols = "";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    GIVEN("Off case: A string with only one symbol for allowed symbols and 5 length") {
        const char* symbols = "a";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    // An In case cannot exist since a string cannot be more empty than 0 characters.

    GIVEN("Out case: A string with multiple symbols for allowed symbols and 5 length") {
        const char* symbols = "abc123";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            free(password);
        }
    }
}

SCENARIO("P3: Generating a password with a non-empty allowed symbols string.", "[passwords]") {
    
    srand((unsigned int) time(NULL)); // Seed the random number generator

    GIVEN("On case: A string with one symbol for allowed symbols and 5 length") {
        const char* symbols = "a";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            free(password);
        }
    }

    GIVEN("Off case: A string with no symbols for allowed symbols and 5 length") {
        const char* symbols = "";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    GIVEN("In case: A string with multiple symbols for allowed symbols and 5 length") {
        const char* symbols = "abc123";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            free(password);
        }
    }

    GIVEN("Out case: A NULL pointer for allowed symbols and 5 length") {
        const char* symbols = NULL;
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }
}

SCENARIO("P4: Generating a password with length 0.", "[passwords]") {
    
    srand((unsigned int) time(NULL)); // Seed the random number generator

    GIVEN("On case: A string with multiple symbols for allowed symbols and 0 length") {
        const char* symbols = "abc123";
        size_t length = 0;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    GIVEN("Off case: A string with multiple symbols for allowed symbols and 1 length") {
        const char* symbols = "abc123";
        size_t length = 1;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            free(password);
        }
    }

    // An In case cannot exist since a password cannot be generated with length less than 0.

    GIVEN("Out case: A string with multiple symbols for allowed symbols and 5 length") {
        const char* symbols = "abc123";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            free(password);
        }
    }
}

/*

P5: length $ \geq $ 1   & ("abc123", 1) & ("abc123", 0) & ("abc123", 5) & ("abc123", SIZE\_MAX) \\
P6: length SIZE\_MAX   & ("abc123", SIZE\_MAX) & ("abc123", SIZE\_MAX - 1) & - & ("abc123", 5) \\
        
*/
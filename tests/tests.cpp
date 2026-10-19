#include <time.h>

#include "passwords.h"
#include "catch2/catch_test_macros.hpp"

SCENARIO("P1: Generating a password with NULL pointer to allowed symbols", "[passwords]") {
    
    // Tests the validity of the pointer and not any value pointed to by the pointer.

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

    GIVEN("Off case: Valid pointer for allowed symbols and 5 length") {
        const char* symbols = "a";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }
        }
    }

    // No In or Out case exist since we are using a pointer - it is either valid or NULL.

}

SCENARIO("P2: Generating a password with an empty allowed symbols string.", "[passwords]") {
    
    // Tests the validity of an empty string for allowed symbols

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

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbol") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(password[i] == 'a');
                }
            }
            
            free(password);
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

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(strchr(symbols, password[i]) != NULL);
                }
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

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbol") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(password[i] == 'a');
                }
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

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(strchr(symbols, password[i]) != NULL);
                }
            }

            free(password);
        }
    }

    // No Out case exists since a cannot be more empty than 0 character.

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

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                REQUIRE(strchr(symbols, password[0]) != NULL);
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

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(strchr(symbols, password[i]) != NULL);
                }
            }

            free(password);
        }
    }
}

SCENARIO("P5: Generating a password with length greater than or equal to 1.", "[passwords]") {
    
    srand((unsigned int) time(NULL)); // Seed the random number generator

    GIVEN("On case: A string with multiple symbols for allowed symbols and 1 length") {
        const char* symbols = "abc123";
        size_t length = 1;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                REQUIRE(strchr(symbols, password[0]) != NULL);
            }

            free(password);
        }
    }

    GIVEN("Off case: A string with multiple symbols for allowed symbols and 0 length") {
        const char* symbols = "abc123";
        size_t length = 0;

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

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(strchr(symbols, password[i]) != NULL);
                }
            }

            free(password);
        }
    }

    // No Out case.

}

SCENARIO("P6: Generating a password with length SIZE_MAX.", "[passwords]") {
    
    srand((unsigned int) time(NULL)); // Seed the random number generator

    GIVEN("On case: A string with multiple symbols for allowed symbols and SIZE_MAX length") {
        const char* symbols = "abc123";
        size_t length = SIZE_MAX;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    GIVEN("Off case: A string with multiple symbols for allowed symbols and SIZE_MAX - 1 length") {
        const char* symbols = "abc123";
        size_t length = SIZE_MAX - 1;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            // According to specification, this should work, but no machine could ever allocate this much memory, so it will return NULL.
            THEN("The password should be NULL") {
                REQUIRE(password == NULL);
            }
        }
    }

    // No Out case.

    GIVEN("Out case: A string with multiple symbols for allowed symbols and 5 length") {
        const char* symbols = "abc123";
        size_t length = 5;

        WHEN("A password is generated") {
            char* password = generate_password(symbols, length);

            THEN("The password should not be NULL") {
                REQUIRE(password != NULL);
            }

            THEN("The size of the password should be equal to the length") {
                REQUIRE(strlen(password) == length);
            }

            THEN("The password should only contain the allowed symbols") {
                for (size_t i = 0; i < length; i++) {
                    REQUIRE(strchr(symbols, password[i]) != NULL);
                }
            }

            free(password);
        }
    }

}

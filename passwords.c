#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passwords.h"

char* generate_password(const char* allowed_symbols, size_t length) {
    // Generates a random password with size [length] using the symbols in the [allowed_symbols] list

    // Check for valid initial conditions
    if (allowed_symbols == NULL || length == 0) {
        return NULL;
    }

    // Check for valid amount of symbols
    size_t nr_symbols = strlen(allowed_symbols);
    if (nr_symbols <= 0) {
        return NULL;
    }

    // Allocate space for new password
    char* new_password = (char*) malloc(sizeof(char)*(length+1));
    if (new_password == NULL) {
        return NULL;
    }

    for (int i = 0; i < length; i++) {
        new_password[i] = allowed_symbols[rand() % nr_symbols];
    }

    // Null terminate the password
    new_password[length] = '\0';

    return new_password;
}


int password_strength(const char* password, size_t minimal_length) {
    // Simple scoring function for assessing the strength of a password. 
    // Additional score if is has the minimal length

    return 0;
}

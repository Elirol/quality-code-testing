#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passwords.h"

char* generate_password(const char* allowed_symbols, size_t length) {
    // Generates a random password with size [length] using the symbols in the [allowed_symbols] list
    /*
    * Specification *
    Arguments:
        [allowed_symbols]: A constant pointer to a null-terminated array of the symbols
        allowed in the generated password.
        [length]: The length of the generated password excluding the null termination character.

    Output:
        Returns a pointer to a null-terminated password with the given length. May return NULL if
        the allowed symbols are invalid, has 0 length, the given length parameter is 0, or the
        memory allocation process failed.

    Importat note:
        The function uses rand() and does not set a seed. Set a seed before calling this function 
        to function properly.
    */

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

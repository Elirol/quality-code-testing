#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "passwords.h"

int main(int argc, char* argv[]) {

    srand((unsigned int) time(NULL));

    char* symbols = "abcdefghijklmnopqrstuvwxyz1234567890\0";
    char* password = generate_password(symbols, 8);

    printf("New password %s\n", password);

    return 0;
}

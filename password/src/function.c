#include "function.h"

char condition_function(int a, int b) {
    // Simple function with a compound condition

    if ((a > 0 && a < b ) || (b < 10 && b < a)) {
        return 1;
    }

    return 0;
}
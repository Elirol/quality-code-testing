#ifndef PASSWORDS_H
#define PASSWORDS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

char* generate_password(const char* allowed_symbols, size_t length);

#ifdef __cplusplus
}
#endif

#endif
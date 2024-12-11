#ifndef MINI_GMP_HELPERS
#define MINI_GMP_HELPERS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "mini-gmp.h"
#include "sha2.h"

void byte_array_to_mpz(mpz_t result, const uint8_t *bytes, size_t byte_len);
void mpz_to_byte_array(mpz_t num, uint8_t *out, size_t out_size);

#endif
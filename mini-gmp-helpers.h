#ifndef MINI_GMP_HELPERS
#define MINI_GMP_HELPERS

#include "mini-gmp.h"
#include "sha2.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Converts input byte array to mpz_t
 */
void byte_array_to_mpz(mpz_t result, const uint8_t *bytes, size_t byte_len);

/**
 * @brief Creates byte array from input mpz_t
 */
void mpz_to_byte_array(const mpz_t num, uint8_t *out, size_t out_size);

#endif
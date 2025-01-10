#include "mini-gmp-helpers.h"

void byte_array_to_mpz(mpz_t result, const uint8_t *bytes, size_t byte_len) {
  mpz_import(result, byte_len, 1, 1, 1, 0, bytes);
}

void mpz_to_byte_array(const mpz_t num, uint8_t *out, size_t out_size) {
  size_t countp;

  // Export the mpz_t value to the byte array
  mpz_export(out, &countp, 1, 1, 1, 0, num);

  // Ensure that the output is padded with leading zeros if necessary
  // If the exported size is smaller than the desired output size, fill in
  // leading zeros
  if (countp < out_size) {
    size_t diff = out_size - countp;
    memmove(out + diff, out, countp);
    memset(out, 0, diff);
  }
}
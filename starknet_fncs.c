#include "starknet_fncs.h"

bool grind_key(const uint8_t *grind_seed, uint8_t *out) {
    uint8_t key[32] = {0};
    mpz_t strk_limit;
    mpz_t strk_key;
    mpz_t stark_order;

    // Initialize stark_order
    mpz_init_set_str(stark_order, "0800000000000010FFFFFFFFFFFFFFFFB781126DCAE7B2321E66A241ADC64D2F", 16);

    // Initialize strk_limit
    mpz_init_set_str(strk_limit, "F80000000000020EFFFFFFFFFFFFFFF738A13B4B920E9411AE6DA5F40B0358B1", 16);

    SHA256_CTX ctx = {0};
    mpz_init(strk_key);
    for (uint8_t itr = 0; itr < 200; itr++) {
        sha256_Init(&ctx);
        sha256_Update(&ctx, grind_seed, 32);
        sha256_Update(&ctx, &itr, 1);
        sha256_Final(&ctx, key);

        byte_array_to_mpz(strk_key, key, 32);
        if (mpz_cmp(strk_key, strk_limit) == -1) {
            mpz_t f_key;
            mpz_init(f_key);
            mpz_mod(f_key, strk_key, stark_order);
            mpz_to_byte_array(f_key, out, 32);
            return true;
        }
    }
    
    // starknet_send_error(ERROR_COMMON_ERROR_UNKNOWN_ERROR_TAG, 0);
    printf("ERROR: grind 200 iterations failed\n");
    // LOG_CRITICAL("grind 200 failed");
    return false;
}

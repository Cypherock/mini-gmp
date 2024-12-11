#include "starknet_fncs.h"

void print_byte_array(const uint8_t *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", array[i]);
    }
    printf("\n");
}

int32_t main()
{
    uint8_t grind_seed[32] = {
    0xc3, 0x52, 0x88, 0xc4, 0x7b, 0x0c, 0x3f, 0x6f,
    0x7e, 0x98, 0x4b, 0x27, 0xb6, 0x7d, 0x50, 0xe8,
    0xe9, 0x39, 0xf5, 0x3c, 0x89, 0x0b, 0x1f, 0x80,
    0xa2, 0x2c, 0x47, 0x90, 0x46, 0xad, 0x37, 0xdc
    };
    uint8_t out[32] = {0};

    if (grind_key(grind_seed, out)) {
        printf("Test Case: grind_key succeeded\n");
        printf("Resulting Key: ");
        print_byte_array(out, 32);
        // printf("\n");
        // byte_array_to_hex_string(out, 32, str, 65);
        // printf("Hexadecimal representation: %s\n", str);
    } else {
        printf("Test Case: grind_key failed after 200 iterations\n");
    }

    return 0;
}


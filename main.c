/**
 * \brief test
 *
 * by lyzh
 */
#include <string.h>
#include <stdio.h>

#include "aes128.h"

uint8_t key[16] = {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,23
};

static void do_en(uint8_t *dst, const uint8_t *src)
{
    struct aes128 aes128;
    aes128_init(&aes128);
    aes128_set_key(&aes128, key);

    aes128_encrypt(&aes128, dst, src);
}
static void do_de(uint8_t *dst, const uint8_t *src)
{
    struct aes128 aes128;
    aes128_init(&aes128);
    aes128_set_key(&aes128, key);
    aes128_decrypt(&aes128, dst, src);
}


int main(int argc, char *argv[])
{
    uint8_t out1[17];
    uint8_t out2[17];
    int i;
    uint8_t src[17] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
    };

    memset( out1, 0x00, sizeof(out1));
    memset( out2, 0x00, sizeof(out2));
    do_en(out1, src);
    do_de(out2, out1);

    printf("before: %s\n", src);
    printf("ciphertext: ");
    for (i=0; i<16; i++){
        printf("%02x ", out1[i]);
    }
    
    printf("\ndecode:%s\n", out2);
    return 0;
}

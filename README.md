# AES-128

[![Build Status](https://travis-ci.org/openluopworld/aes_128.svg?branch=master)](https://travis-ci.org/openluopworld/aes_128) [![Coverity Scan Build Status](https://img.shields.io/coverity/scan/11502.svg)](https://scan.coverity.com/projects/openluopworld-aes_128)

C implementation of AES-128. THis code has been tested with valgrind-3.11.0.

```C
/**
 * \brief aes128 structrue
 *
 * remember the key
 */
struct aes128
{
    uint8_t roundkeys[176;
};

void aes128_init(struct aes_crypt *p_this);
void aes128_destroy(struct aes_crypt *p_this);

/**
 * \brief set key
 * 
 * @purpose:            Key schedule for AES-128
 * @par[in]p_this:      obj
 * @par[in]key:         16 bytes of master keys
 * @par[out]roundkeys:  176 bytes of round keys
 */
void aes128_set_key(struct aes_crypt *p_this, const uint8_t key[16] );

/**
 * @purpose:            Encryption. The length of plain and cipher should be one block (16 bytes).
 *                      The plaintext and ciphertext may point to the same memory
 * @par[in]p_this:      obj
 * @par[in]plaintext:   plain text
 * @par[out]ciphertext: cipher text
 */
void aes128_encrypt(const struct aes_crypt *p_this, uint8_t *ciphertext, const uint8_t *plaintext );

/**
 * @purpose:            Decryption. The length of plain and cipher should be one block (16 bytes).
 *                      The ciphertext and plaintext may point to the same memory
 * @par[in]p_this:      obj
 * @par[in]ciphertext:  cipher text
 * @par[out]plaintext:  plain text
 */
void aes128_decrypt(const struct aes_crypt *p_this, uint8_t *plaintext, const uint8_t *ciphertext );

```

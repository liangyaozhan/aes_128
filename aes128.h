/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * lyzh, 2017-01-18, change api. ivws02@126.com
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in May 2016
 *
 */
#ifndef AES_128_H
#define AES_128_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * \brief aes128 structrue
 *
 * remember the key
 */
struct aes128
{
    uint8_t roundkeys[176];
};

void aes128_init(struct aes128 *p_this);
void aes128_destroy(struct aes128 *p_this);

/**
 * \brief set key
 * 
 * @purpose:            Key schedule for AES-128
 * @par[in]p_this:      obj
 * @par[in]key:         16 bytes of master keys
 * @par[out]roundkeys:  176 bytes of round keys
 */
void aes128_set_key(struct aes128 *p_this, const uint8_t key[16] );

int aes128_block_size(struct aes128 *p_this);

/**
 * @purpose:            Encryption. The length of plain and cipher should be one block (16 bytes).
 *                      The plaintext and ciphertext may point to the same memory
 * @par[in]p_this:      obj
 * @par[in]plaintext:   plain text
 * @par[out]ciphertext: cipher text
 */
void aes128_encrypt(const struct aes128 *p_this, uint8_t *ciphertext, const uint8_t *plaintext );

/**
 * @purpose:            Decryption. The length of plain and cipher should be one block (16 bytes).
 *                      The ciphertext and plaintext may point to the same memory
 * @par[in]p_this:      obj
 * @par[in]ciphertext:  cipher text
 * @par[out]plaintext:  plain text
 */
void aes128_decrypt(const struct aes128 *p_this, uint8_t *plaintext, const uint8_t *ciphertext );


#ifdef __cplusplus
}
#endif

#endif

#include <stdio.h>
#include <string.h>
#include "encrypt.h"

int main(void) {
    const unsigned char plain[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    const unsigned char key[8] = {0x13, 0x34, 0x57, 0x79, 0x9b, 0xbc, 0xdf, 0xf1};
    const unsigned char expected[8] = {0x85, 0xe8, 0x13, 0x54, 0x0f, 0x0a, 0xb4, 0x05};
    unsigned char cipher[8], recovered[8];
    des_encipher(plain, cipher, key);
    des_decipher(cipher, recovered, key);
    if (memcmp(cipher, expected, 8) || memcmp(plain, recovered, 8)) {
        fprintf(stderr, "DES verification failed\n");
        return 1;
    }
    printf("DES ciphertext:");
    for (int i = 0; i < 8; i++)
        printf(" %02x", cipher[i]);
    puts("\nDES round trip passed");

    RsaPubKey pub = {17, 3233};
    RsaPriKey pri = {2753, 3233};
    Huge message = 65, encrypted, decrypted;
    rsa_encipher(message, &encrypted, pub);
    rsa_decipher(encrypted, &decrypted, pri);
    if (encrypted != 2790 || decrypted != message) {
        fprintf(stderr, "RSA verification failed\n");
        return 1;
    }
    printf("RSA: %lu -> %lu -> %lu\n", message, encrypted, decrypted);
    return 0;
}

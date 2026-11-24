//
// Created by abondar on 07.03.16.
//

#include <stdio.h>
#include <string.h>

#include "bit_ops.h"


int main(int argc, char *argv[]) {
    unsigned char bits1[] = "abcde";
    unsigned char bits2[] = "aeghi";
    unsigned char bits3[5] = {0};
    if (argc != 2) {
        fprintf(stderr, "Usage: %s bg|bs|bx|br\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "bg") == 0) {
        printf("Bit val at position 4 of string 'abcde' %d\n", bit_get(bits1, 4));
    } else if (strcmp(argv[1], "bs") == 0) {
        bit_set(bits1, 4, 1);
        printf("New bit val at position 4 of string 'abcde' %d\n", bit_get(bits1, 4));
    } else if (strcmp(argv[1], "bx") == 0) {
        bit_xor(bits1, bits2, bits3, 40);
        printf("XOR bytes:");
        for (int i = 0; i < 5; i++)
            printf(" %02x", bits3[i]);
        printf("\n");
    } else if (strcmp(argv[1], "br") == 0) {
        bit_rot_left(bits2, 40, 8);
        printf("Rotated %s\n", bits2);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        return 1;
    }
    return 0;
}

int bit_get(const unsigned char *bits,int pos){

    unsigned char mask;

    int i;

    //set a mask for bit to get
    mask = 0x80;

    for (i=0;i<(pos % 8);i++){
        mask = mask>>1;
    }

    return (((mask & bits[(int)(pos/8)])==mask) ? 1: 0);
};

void bit_set(unsigned char *bits,int pos,int state){
    unsigned char mask;

    int i;

    //set a mask for bit to get
    mask = 0x80;

    for (i=0;i<(pos % 8);i++){
        mask = mask>>1;
    }
    //set a bit
    if (state)
        bits[pos/8]=bits[pos /8] | mask;
    else
        bits[pos/8]=bits[pos /8] & (~mask);
    return;
};

void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size){

    int i;

    for (i=0;i<size;i++){
        if (bit_get(bits1,i)!=bit_get(bits2,i))
            bit_set(bitsx,i,1);
        else
            bit_set(bitsx,i,0);
    }


    return;
};

void bit_rot_left(unsigned char *bits, int size, int count) {
    if (size <= 0 || count <= 0)
        return;
    count %= size;
    for (int j = 0; j < count; j++) {
        int first = bit_get(bits, 0);
        for (int i = 0; i < size - 1; i++)
            bit_set(bits, i, bit_get(bits, i + 1));
        bit_set(bits, size - 1, first);
    }
}

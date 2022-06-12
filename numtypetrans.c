#define uchar unsigned char
#define uint unsigned int
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define sc_bin 0
#define sc_oct 1
#define sc_dec 2
#define sc_hex 3

typedef struct {
    uint number;
    uchar bin[16];
    uchar oct[10];
    uchar dec[10];
    uchar hex[4];
} num_type;

void num_init(num_type *num) {
    int j;
    num->number = 0;
    for (j = 0; j < 16; j++)
        num->bin[j] = '0';
    for (j = 0; j < 10; j++)
        num->oct[j] = '0';
    for (j = 0; j < 10; j++)
        num->dec[j] = '0';
    for (j = 0; j < 4; j++)
        num->hex[j] = '0';
}



void num_input(num_type *num, uint mode, uchar *str) {
    uint i;
    uchar tmp_bin[16];
    uchar tmp_oct[10];
    uchar tmp_dec[10];
    uchar tmp_hex[4];
    switch (mode) {
    case sc_oct:
        scanf("%o", &num->number);
        break;
    case sc_dec:
        scanf("%d", &num->number);
        break;
    case sc_hex:
        scanf("%x", &num->number);
        break;
    case sc_bin:
        for (i = 0; i < 16; i++) {
            if (str[i] == '1')
                num->number |= (1 << i);
            else
                num->number &= ~(1 << i);
        }
        break;
    }
    itoa(num->number, tmp_bin, 2);
    itoa(num->number, tmp_oct, 8);
    itoa(num->number, tmp_dec, 10);
    itoa(num->number, tmp_hex, 16);
    for (i = 0; i < 16; i++)
        num->bin[i] = tmp_bin[i];
    for (i = 0; i < 10; i++)
        num->oct[i] = tmp_oct[i];
    for (i = 0; i < 10; i++)
        num->dec[i] = tmp_dec[i];
    for (i = 0; i < 4; i++)
        num->hex[i] = tmp_hex[i];
}
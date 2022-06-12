#define uchar unsigned char
#define uint unsigned int
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define sc_bin 0
#define sc_oct 1
#define sc_dec 2
#define sc_hex 3
#include <iostream>
using namespace std;

typedef struct {
    uint number;
    uchar bin[16];
    uchar oct[10];
    uchar dec[10];
    uchar hex[4];
} num_type;

num_type *num_init() {
    num_type* num = (num_type *)malloc(sizeof(num_type)); 
    if (num == NULL)                                      
        return 0;
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
    return num;
}



void num_input(num_type* num, uint mode, char* str) {
    uint i;
    char tmp_bin[16];
    char tmp_oct[10];
    char tmp_dec[10];
    char tmp_hex[5];
    // char buffer[16];
    switch (mode) {
    case sc_oct:
        sscanf_s(str, "%o", &num->number);
        break;
    case sc_dec:
        sscanf_s(str, "%d", &num->number);
        break;
    case sc_hex:
        sscanf_s(str, "%x", &num->number);
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
    _itoa_s(num->number, tmp_bin, 2);
    _itoa_s(num->number, tmp_oct, 8);
    _itoa_s(num->number, tmp_dec, 10);
    _itoa_s(num->number, tmp_hex, 16);
    tmp_hex[4] = ' ';
    for (i = 0; i < 16; i++)
        num->bin[i] = tmp_bin[i];
    for (i = 0; i < 10; i++)
        num->oct[i] = tmp_oct[i];
    for (i = 0; i < 10; i++)
        num->dec[i] = tmp_dec[i];
    for (i = 0; i < 4; i++)
        num->hex[i] = tmp_hex[i];
}

int main() {
    num_type* num_struct;
    num_struct = num_init();
    char str[] = "1011101";
    num_input(num_struct, sc_bin, str);
    cout << "num->bin:" << num_struct->bin << endl;
    cout << "num->oct:" << num_struct->oct << endl;
    cout << "num->dec:" << num_struct->dec << endl;
    cout << "num->hex:" << num_struct->hex << endl;
}
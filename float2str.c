#include <stdio.h>
#include <string.h>

void float2str(float f, char* str, int n) {
    //将一个float转换为精度位数为n的字符串
    //n = 8;
    int i = 0;
    int e = 0;
    char integar_f[10];
    int pointer_int = 0;
    int f_int = (int)f;
    float f_dec = f - (int)f;
    if (f < 0) {
        str[i++] = '-';
        f = -f;
    }
    f_int = (int)f;
    f_dec = f - (int)f;
    if (f < 1e-8) {
        str[i++] = '0';
        str[i++] = '.';
        while (n--) {
            str[i++] = '0';
        }
        str[i] = '\0';
        return;
    }
    if (!f_int) {
        str[i++] = '0';
    }   
    else {
        while (f_int) {
        integar_f[pointer_int++] = f_int % 10 + '0';
        f_int /= 10;
        }
    }
    while (pointer_int) {
        str[i++] = integar_f[--pointer_int];
    }
    str[i++] = '.';
    while (n--) {
        f_dec *= 10;
        str[i++] = (int)f_dec + '0';
        f_dec -= (int)f_dec;
    }
    str[i] = '\0';     
}

void main() {
    float f = -0.1456789;
    char str[100];
    float2str(f, str, 9);
    printf("%s\n", str);
}
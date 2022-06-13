/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "C8051F020.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init() {
    WDTCN = 0xDE;
    WDTCN = 0xAD;
}

void Timer_Init() { TMOD = 0x01; }

void Port_IO_Init() {
    // P0.0  -  Unassigned,  Open-Drain, Digital
    // P0.1  -  Unassigned,  Open-Drain, Digital
    // P0.2  -  Unassigned,  Open-Drain, Digital
    // P0.3  -  Unassigned,  Open-Drain, Digital
    // P0.4  -  Unassigned,  Open-Drain, Digital
    // P0.5  -  Unassigned,  Open-Drain, Digital
    // P0.6  -  Unassigned,  Open-Drain, Digital
    // P0.7  -  Unassigned,  Open-Drain, Digital

    // P1.0  -  Unassigned,  Open-Drain, Digital
    // P1.1  -  Unassigned,  Open-Drain, Digital
    // P1.2  -  Unassigned,  Open-Drain, Digital
    // P1.3  -  Unassigned,  Open-Drain, Digital
    // P1.4  -  Unassigned,  Open-Drain, Digital
    // P1.5  -  Unassigned,  Open-Drain, Digital
    // P1.6  -  Unassigned,  Open-Drain, Digital
    // P1.7  -  Unassigned,  Open-Drain, Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Push-Pull,  Digital
    // P2.6  -  Unassigned,  Push-Pull,  Digital
    // P2.7  -  Unassigned,  Push-Pull,  Digital

    // P3.0  -  Unassigned,  Push-Pull,  Digital
    // P3.1  -  Unassigned,  Push-Pull,  Digital
    // P3.2  -  Unassigned,  Push-Pull,  Digital
    // P3.3  -  Unassigned,  Push-Pull,  Digital
    // P3.4  -  Unassigned,  Push-Pull,  Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Push-Pull,  Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital

    P2MDOUT = 0xFF;
    P3MDOUT = 0xFF;
    P74OUT = 0x02;
    XBR2 = 0xC0;
}

void Oscillator_Init() { OSCICN = 0x07; }

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void) {
    Reset_Sources_Init();
    Timer_Init();
    Port_IO_Init();
    Oscillator_Init();
}

////////////////////�궨��&ͷ�ļ�����/////////////////////////
// #define uchar unsigned char
// #define uint unsigned int
#define N_O_num 0
#define N_O_operator 1
// #define MAX 200+10
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char xdata malloc_mempool[0x1000];

#include <string.h>
#define ldouble long double
#define lint long int
#define MAX 30 + 10
#define uint unsigned int
#define uchar unsigned char
#define comm 0
#define dat 1

#define sqrt_sign 0xE8
#define back_sign 0x7F
#define divide_sign 0xFD

#define s_0 0
#define s_1 1
#define s_2 2
#define s_3 3
#define s_4 4
#define s_5 5
#define s_6 6
#define s_7 7
#define s_8 8
#define s_9 9

#define sc_bin 0
#define sc_oct 1
#define sc_dec 2
#define sc_hex 3

sbit e = P3 ^ 2;  // input enable;
sbit rw = P3 ^ 1; // H=read; L=write;
sbit rs = P3 ^ 0; // H=data; L=command;
sbit beep = P3 ^ 5;
sbit b_164 = P3 ^ 6;
sbit clk_164 = P3 ^ 7;
// sbit ki_0 = P4 ^ 0;		  // P4����λѰַ
// sbit ki_1 = P4 ^ 1;
// sbit ki_2 = P4 ^ 2;
// sbit ki_3 = P4 ^ 3;
// sbit led_1 = P4 ^ 4;
// sbit led_2 = P4 ^ 5;

#define ki_h0 P4 |= 0x01 // P4.0����P4�޷�����λѰַ����
#define ki_h1 P4 |= 0x02
#define ki_h2 P4 |= 0x04
#define ki_h3 P4 |= 0x08
#define led_h1 P4 |= 0x10
#define led_h2 P4 |= 0x20

#define ki_l0 P4 &= 0xFE
#define ki_l1 P4 &= 0xFD
#define ki_l2 P4 &= 0xFB
#define ki_l3 P4 &= 0xF7
#define led_l1 P4 &= 0xEF
#define led_l2 P4 &= 0xDF

#define ram_temp 0x20

uchar code init_tab[] = {"12BitsCalculator"
                         "                "};
uchar code clear_tab[] = {"                "
                          "                "};


uchar ram_tmp, ram_p4;

void delay(int ms) // delay time
{
    int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 123; j++)
            ;
}

void beep_short() {
    beep = 1;
    delay(200);
    beep = 0;
    //    delay(100);
}
void beep_long() {
    beep = 1;
    P4 |= 0x30;
    delay(1500);
    beep = 0;
    delay(100);
}
int j;
void alarm_syntax() {
    beep = 1;
    P4 |= 0x10;
    delay(1000);
    beep = 0;
    P4 &= 0xEF;
    delay(500);
    beep = 1;
    P4 |= 0x10;
    delay(1000);
    beep = 0;
    P4 &= 0xEF;
    delay(500);
    beep = 1;
    P4 |= 0x10;
    delay(1000);
    beep = 0;
    delay(500);
    //    delay(500);
}

void alarm_math() {
    beep = 1;
    P4 |= 0x20;
    delay(1000);
    beep = 0;
    P4 &= 0xDF;
    delay(500);
    beep = 1;
    P4 |= 0x20;
    delay(1000);
    beep = 0;
    P4 &= 0xDF;
    delay(500);
    beep = 1;
    P4 |= 0x20;
    delay(1000);
    beep = 0;
    delay(500);
    //    delay(500);
}

int state_cal = 0; //ȫ�ֱ����������ж��Ƿ���ִ���
//---------------------����ת���ṹ��--------------------------
char *itoa(int num, char *buffer, int base) {//itoa����Ϊc++�ĺ������µ�����-�ַ���ת������
                                             //�˴����ڲ����ڶ�Ӧ�⺯������Ҫ��������
    int current = 0;
    int num_digits = 0;
    if (num == 0) {
        buffer[current++] = '0';
        buffer[current] = '\0';
        return buffer;
    }
    if (num < 0) {
        if (base == 10) {
            num_digits++;
            buffer[current] = '-';
            current++;
            num *= -1;
        } else
            return NULL;
    }
    num_digits += (int)floor(log(num) / log(base)) + 1;
    while (current < num_digits) {
        int base_val = (int)pow(base, num_digits - 1 - current);
        int num_val = num / base_val;
        char value = num_val + '0';
        buffer[current] = value;
        current++;
        num -= base_val * num_val;
    }
    buffer[current] = '\0';
    return buffer;
}

int mode_trans_in = sc_dec;
int mode_trans_out = sc_bin;

typedef struct {
    uint number;
    uchar bin[16];
    uchar oct[10];
    uchar dec[10];
    uchar hex[4];
} num_type;

num_type *num_init() {
    int j;
    num_type *num = (num_type *)malloc(sizeof(num_type));
    if (num == NULL)
        return 0;
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

void num_input(num_type *num, uint mode_in, uint mode_out, uchar *str) {
    uint i;
    uchar tmp_bin[16];
    uchar tmp_oct[10];
    uchar tmp_dec[10];
    uchar tmp_hex[4];
    switch (mode_in) {
    case sc_oct:
        sscanf(str, "%o", &num->number);
        break;
    case sc_dec:
        sscanf(str, "%d", &num->number);
        break;
    case sc_hex:
        sscanf(str, "%x", &num->number);
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
    if (num->number > 32767) {
        state_cal = 3; // overflow error;
        return;
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
    for (i = 0; i < 4; i++) {
        num->hex[i] = tmp_hex[i];
        if (num->hex[i] > '9')
            num->hex[i] += 7;
    }
}

//---------------------��������ֽṹ��--------------------------
typedef struct {
    float f_high;
    float f_mid;
    float f_low;
} dfloat;

dfloat final_answer;
void save_dfloat(dfloat *d, float f_high, float f_mid, float f_low) {
    d->f_high = f_high;
    d->f_mid = f_mid;
    d->f_low = f_low;
}

int get_integer(float f) {
    int f_int = (int)f;
    float f_dec = f - f_int;
    if (f_dec < 0.5)
        return f_int;
    else
        return f_int + 1;
}
//---------------------��������ض���--------------------------
dfloat d_add_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    d_result.f_high = d1.f_high + d2.f_high;
    d_result.f_mid = d1.f_mid + d2.f_mid;
    d_result.f_low = d1.f_low + d2.f_low;
    //����if�ж����Դ�����������������ͬ
    if (d_result.f_high <= -65534) {
        d_result.f_high = 0;
    }
    if (d_result.f_mid >= 65535)
        d_result.f_mid = 0;
    if (d_result.f_mid <= -65534) {
        d_result.f_mid = 0;
        d_result.f_high = d_result.f_high + 1;
    }
    if (d_result.f_low >= 65535)
        d_result.f_low = 0;
    if (d_result.f_low <= -65534) {
        d_result.f_low = 0;
        d_result.f_mid = d_result.f_mid + 1;
    }
    if (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    if (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    return d_result;
}

dfloat d_add_df(dfloat d1, float f2) {
    dfloat d_result;
    d_result.f_high = d1.f_high + f2;
    f2 = f2 * 1e4;
    f2 = f2 - (int)f2;
    d_result.f_mid = d1.f_mid + f2;
    d_result.f_low = d1.f_low;
    if (d_result.f_high <= -65534) {
        d_result.f_high = 0;
    }
    if (d_result.f_mid >= 65535)
        d_result.f_mid = 0;
    if (d_result.f_mid <= -65534) {
        d_result.f_mid = 0;
        d_result.f_high = d_result.f_high + 1;
    }
    if (d_result.f_low >= 65535)
        d_result.f_low = 0;
    if (d_result.f_low <= -65534) {
        d_result.f_low = 0;
        d_result.f_mid = d_result.f_mid + 1;
    }
    if (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    if (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    return d_result;
}

dfloat d_sub_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    d_result.f_high = d1.f_high - d2.f_high;
    d_result.f_mid = d1.f_mid - d2.f_mid;
    d_result.f_low = d1.f_low - d2.f_low;
    if (d_result.f_high <= -65534) {
        d_result.f_high = 0;
    }
    if (d_result.f_mid >= 65535)
        d_result.f_mid = 0;
    if (d_result.f_mid <= -65534) {
        d_result.f_mid = 0;
        d_result.f_high = d_result.f_high + 1;
    }
    if (d_result.f_low >= 65535)
        d_result.f_low = 0;
    if (d_result.f_low <= -65534) {
        d_result.f_low = 0;
        d_result.f_mid = d_result.f_mid + 1;
    }
    if (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    if (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    if (d_result.f_low < 0) {
        d_result.f_mid -= 1;
        d_result.f_low += 1;
    }
    if (d_result.f_mid < 0) {
        d_result.f_high -= 1;
        d_result.f_mid += 1;
    }
    return d_result;
}

dfloat d_sub_df(dfloat d1, float f2) {
    dfloat d_result;
    d_result.f_high = d1.f_high - f2;
    f2 = f2 * 1e4;
    f2 = f2 - (int)f2;
    d_result.f_mid = d1.f_mid - f2;
    d_result.f_low = d1.f_low;
    if (d_result.f_high <= -65534) {
        d_result.f_high = 0;
    }
    if (d_result.f_mid >= 65535)
        d_result.f_mid = 0;
    if (d_result.f_mid <= -65534) {
        d_result.f_mid = 0;
        d_result.f_high = d_result.f_high + 1;
    }
    if (d_result.f_low >= 65535)
        d_result.f_low = 0;
    if (d_result.f_low <= -65534) {
        d_result.f_low = 0;
        d_result.f_mid = d_result.f_mid + 1;
    }
    if (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    if (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    return d_result;
}

dfloat d_mul_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    d_result.f_high = d1.f_high * d2.f_high;
    d_result.f_mid = d1.f_mid * d2.f_high;
    d_result.f_low = d1.f_low * d2.f_high;
    if (d_result.f_high <= -65534) {
        d_result.f_high = 0;
    }
    if (d_result.f_mid >= 65535)
        d_result.f_mid = 0;
    if (d_result.f_mid <= -65534) {
        d_result.f_mid = 0;
        d_result.f_high = d_result.f_high + 1;
    }
    if (d_result.f_low >= 65535)
        d_result.f_low = 0;
    if (d_result.f_low <= -65534) {
        d_result.f_low = 0;
        d_result.f_mid = d_result.f_mid + 1;
    }
    if (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    if (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    while (d_result.f_low < 0) {
        d_result.f_mid -= 1;
        d_result.f_low += 1;
    }
    while (d_result.f_mid < 0) {
        d_result.f_high -= 1;
        d_result.f_mid += 1;
    }
    while (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    while (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    return d_result;
}

dfloat d_mul_df(dfloat d1, float f2) {
    dfloat d_result;
    d_result.f_high = d1.f_high * f2;
    d_result.f_mid = d1.f_mid * f2;
    d_result.f_low = d1.f_low * f2;
    if (d_result.f_high <= -65534) {
        d_result.f_high = 0;
    }
    if (d_result.f_mid >= 65535)
        d_result.f_mid = 0;
    if (d_result.f_mid <= -65534) {
        d_result.f_mid = 0;
        d_result.f_high = d_result.f_high + 1;
    }
    if (d_result.f_low >= 65535)
        d_result.f_low = 0;
    if (d_result.f_low <= -65534) {
        d_result.f_low = 0;
        d_result.f_mid = d_result.f_mid + 1;
    }
    if (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    if (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    while (d_result.f_low >= 1) {
        d_result.f_mid += 1;
        d_result.f_low -= 1;
    }
    while (d_result.f_mid >= 1) {
        d_result.f_high += 1;
        d_result.f_mid -= 1;
    }
    return d_result;
}

dfloat d_div_dd(dfloat d1, dfloat d2) {
    dfloat d_result;

    float f_high, f_mid, f_low, f_tmp, f_tmp1, f_tmp2;
    int f_high_tmp, f_mid_tmp, f_low_tmp, bits_10;
    if (d2.f_mid >= 65535)
        d2.f_mid = 0;
    if (d2.f_mid <= -65534) {
        d2.f_mid = 0;
        d2.f_high = d2.f_high + 1;
    }
    f_high = d1.f_high / (d2.f_high + d2.f_mid + d2.f_low);

    f_high = 10000 * f_high;
    f_high = (long int)f_high;
    f_high = f_high / 10000;

    f_tmp1 = f_high * (d2.f_high + d2.f_mid + d2.f_low);
    f_tmp1 = d1.f_high - f_tmp1; // ȡ��λ��������ԭ������������һ��������λ��λ����������
    f_tmp1 = 10000 * f_tmp1;
    f_tmp1 = get_integer(f_tmp1);
    f_mid = f_tmp1 / (d2.f_high + d2.f_mid + d2.f_low);
    f_mid = 10000 * f_mid;
    f_mid = (long int)f_mid;
    f_mid = f_mid / 10000;

    f_tmp2 = f_mid * (d2.f_high + d2.f_mid + d2.f_low);
    f_tmp2 = f_tmp1 - f_tmp2;
    f_tmp2 = 10000 * f_tmp2;
    f_tmp2 = get_integer(f_tmp2);
    f_low = f_tmp2 / (d2.f_high + d2.f_mid + d2.f_low);
    f_low = 10000 * f_low;
    f_low = (long int)f_low;
    f_low = f_low / 10000;

    save_dfloat(&d_result, f_high, f_mid, f_low);
    return d_result;
}

dfloat d_div_df(dfloat d1, float f) {
    dfloat d_result;

    float f_high, f_mid, f_low, f_tmp;
    f_high = d1.f_high / f;
    f_high = 1e4 * f_high;
    f_high = (long int)f_high;
    f_high = f_high / 1e4;
    f_mid = d1.f_mid / f;
    f_mid = 1e4 * f_mid;
    f_mid = (int)f_mid;
    f_mid = f_mid / 1e4;
    f_low = d1.f_low / f;
    f_low = 1e4 * f_low;
    f_low = (int)f_low;
    f_low = f_low / 1e4;

    save_dfloat(&d_result, f_high, f_mid, f_low);
    return d_result;
}

dfloat d_pow_df(dfloat d1, float f1) {
    dfloat d_result;
    float f_high, f_mid, f_low;
    f_high = pow(d1.f_high, f1);
    f_mid = pow(d1.f_mid, f1);
    f_low = pow(d1.f_low, f1);
    if (f_low >= 1) {
        f_high += 1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_mid, f_low);
    return d_result;
}

//---------------------�����������㷨--------------------------

int state_math = 0;
//������ջ���壬���ڲ������洢
typedef struct {
    char data_s[MAX];
    int top;
    int bottom;
} OpeStack, ope1;

OpeStack *OpeStackCreate() {
    OpeStack *p = (OpeStack *)malloc(sizeof(OpeStack)); //�����¿ռ�
    if (p == NULL)                                      //����ʧ��
        return 0;
    p->bottom = p->top = 0; //����ɹ�����ʼ��ջ
    return p;
}

void OpeStackCopy(OpeStack *p1, OpeStack *p2) { // p1<-p2
    int i;
    p1->top = p2->top;
    p1->bottom = p2->bottom;
    for (i = p1->bottom; i <= p1->top; i++) {
        p1->data_s[i] = p2->data_s[i];
    }
}

void OpeStackInput(OpeStack *p, char str) {
    p->data_s[p->top] = str; //��ջ
    p->top++;                //ջ����1
}

char OpeStackOutput(OpeStack *p) {
    char str;
    if (p->top != p->bottom) //ջ����
    {
        str = p->data_s[p->top - 1]; //��ջ
        p->top--;                    //ջ����1
        return str;
    }
}

uint priority_operator(uchar operator_char) {
    //���ȼ��жϣ�^����*/����+-
    switch (operator_char) {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case divide_sign:
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

void OpeStackConvert(OpeStack *p) {
    //˳���ջ��������ջ
    int pointer = 0;
    int length = p->top - p->bottom;
    uchar ope_tmp[MAX];
    int i;
    for (i = 0; i < length; i++) {
        ope_tmp[pointer++] = OpeStackOutput(p);
    }
    pointer = 0;
    for (i = 0; i < length; i++) {
        OpeStackInput(p, ope_tmp[pointer]);
        pointer++;
    }
}

//����ջ���壬�������ִ洢
typedef struct {
    dfloat data_s[MAX];
    int top;
    int bottom;
} NumStack, num1;

NumStack *NumStackCreate() {
    NumStack *p = (NumStack *)malloc(sizeof(NumStack)); //�����¿ռ�
    if (p == NULL)                                      //����ʧ��
        return 0;
    p->bottom = p->top = 0; //����ɹ�
    return p;
}

void NumStackCopy(NumStack *p1, NumStack *p2) { // p1<-p2
    int i;
    p1->top = p2->top;
    p1->bottom = p2->bottom;
    for (i = p1->bottom; i <= p1->top; i++) {
        p1->data_s[i] = p2->data_s[i];
    }
}

void NumStackInput(NumStack *p, float f) {
    save_dfloat(&p->data_s[p->top], f, 0, 0); //����ջ��
    p->top++;                                 //ջ��ָ���1
}

void NumStackInput_dfloat(NumStack *p, dfloat f) {
    p->data_s[p->top] = f; //����ջ��
    p->top++;              //ջ��ָ���1
}

dfloat NumStackOutput(NumStack *p) {
    dfloat f;
    if (p->top != p->bottom) {     //ջ�ǿ�
        f = p->data_s[p->top - 1]; //ջ���������
        p->top--;                  //ջ����1
        return f;
    }
}

int stack_calculation(NumStack *n, OpeStack *o) {
    //����ջ���������֡�����ջ��һ�����Ž������㣬���������ջ
    dfloat n1, n2;
    dfloat n_ans;
    char o1;
    n1 = NumStackOutput(n);
    o1 = OpeStackOutput(o);
    n2 = NumStackOutput(n);
    switch (o1) {
    case '+':
        n_ans = d_add_dd(n1, n2);
        break;
    case '-':
        n_ans = d_sub_dd(n1, n2);
        break;
    case '*':
        n_ans = d_mul_dd(n1, n2);
        break;
    case divide_sign:
        if (fabs(n2.f_high) < 1e-8) {
            state_cal =
                2; //�ھ���Ϊ1e-8�������жϳ����Ƿ�Ϊ0��Ϊ0���������ѧ����
            return -1;
        }
        n_ans = d_div_dd(n1, n2);
        break;
    case '^':
        if (fabs(n2.f_high) < 1e-8 && fabs(n1.f_high) < 1e-8) {
            state_cal =
                2; //�ھ���Ϊ1e-8�������ж��ݵ�����ָ���Ƿ�Ϊ0������Ϊ0���������ѧ����
            return -1;
        }
        n_ans = d_pow_df(n1, n2.f_high);
        break;
    default:
        break;
    }
    NumStackInput_dfloat(n, n_ans);
}

void StackConvert(NumStack *n, OpeStack *o) {
    //�﷨��������
    dfloat num_tmp;
    char ope_tmp;
    //�������š�������ʱ��ջ
    NumStack *ns_tmp;
    OpeStack *os_tmp;
    ns_tmp = NumStackCreate();
    os_tmp = OpeStackCreate();
    while (n->top != n->bottom) //����ջ�ǿ�
    {
        num_tmp = NumStackOutput(n);
        NumStackInput_dfloat(ns_tmp, num_tmp);
        if (o->top == o->bottom) {
            break;
        }
        ope_tmp = OpeStackOutput(o);
        while (os_tmp->top != os_tmp->bottom && //����ջ�ǿ�
                priority_operator(ope_tmp) < priority_operator(os_tmp->data_s[os_tmp->top - 1])) { //��ǰ�������ȼ�С�ڵ��ڷ���ջ��
            stack_calculation(ns_tmp, os_tmp); //�������ȼ�����
        }
        OpeStackInput(os_tmp, ope_tmp);
    }
    NumStackCopy(n, ns_tmp); // n = ns_tmp;
    OpeStackCopy(o, os_tmp); // o = os_tmp;
}

int numinstack(uint num, NumStack *p, uint dot_occupied) {
    //������ջ�ʷ���������
    int i;
    dfloat num_ans, num_pre;
    num = num - 48; //��ASCII��ת��Ϊ����
    num_pre = NumStackOutput(p);
    if (dot_occupied == 0) {
        num_ans = d_add_df(d_mul_df(num_pre, 10), (float)num); //�������������λ��ԭ���ֳ���10
    } else {
        num_ans = num_pre;
        for (i = 0; i < dot_occupied; i++) {
            num_ans = d_mul_df(num_ans, 10); //ԭ����ѭ����10����λ��
        }
        num_ans = d_add_df(num_ans, (float)num); //�������������λ
        for (i = 0; i < dot_occupied; i++) {
            num_ans = d_div_df(num_ans, 10); //����С���㸴λ
        }
    }
    NumStackInput_dfloat(p, num_ans);
    return 0;
}

int operatorinstack(NumStack *n, OpeStack *o, char ope) {
    //���ȼ���() > /sqrt() > ^ > * / > + -
    char o1;
    int state;
    o1 = o->data_s[o->top - 1];
    OpeStackInput(o, ope);
    return 0;
}

int sqrt_cal(NumStack *n, int *sqrt_flag) { 
    //��sqrt��־λָ�����ֿ������� 
    int i = 0, f_high_tmp_int;
    float f_high_tmp;
    for (i = 0; i < n->top; i++) {
        if (sqrt_flag[i] == 1) {
            n->data_s[i].f_high = sqrt(n->data_s[i].f_high);
            f_high_tmp = 10000 * n->data_s[i].f_high; //��������λ
            f_high_tmp_int = (int)f_high_tmp;
            n->data_s[i].f_mid = f_high_tmp - f_high_tmp_int; //��������λ
        }
    }
    return 0;
}
int cal_algorithm(uchar *p, uint length_p) {
    uint i = 0;
    uint dot_occupied = 0;
    uint dot_cnt = 0;
    uint N_O = N_O_operator;
    uint num_stack_depth = 0;
    uint operator_stack_depth = 0;
    int state_math;

    int sqrt_flag[MAX] = {0};
    int sqrt_flag_cnt = 0;
    NumStack *num_stack;
    OpeStack *operator_stack;
    num_stack = NumStackCreate();
    operator_stack = OpeStackCreate();

    while (i < length_p) { //���ʽδ��ȡ���
        if (p[i] == '.') {
            if (dot_occupied != 0) { //�Ѵ���С����
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar error
            }
            N_O = N_O_num;
            dot_occupied = 1; //С�����־����ʱ������һλ�������֣����Զ����0
        } else if (p[i] == sqrt_sign) {
            if (sqrt_flag_cnt == num_stack->top + 1) { //sqrt��־λ��
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar error
            }
            if (N_O == N_O_operator) {
                sqrt_flag_cnt = num_stack->top;
            } else {
                operatorinstack(num_stack, operator_stack, '*'); //�Զ����˺�
                sqrt_flag_cnt = num_stack->top;
            }
            sqrt_flag[sqrt_flag_cnt] = 1;
            N_O = N_O_operator;
        } else if (p[i] <= '9' && p[i] >= '0') { //����
            if (N_O == N_O_operator) { //ǰһ���ַ��������������ջ������λ
                dot_occupied = 0; //С�����־����
                dot_cnt = 0;
                NumStackInput(num_stack, 0); //����ջ�Զ���0��λ
            }
            if (i == 0 || p[i - 1] == '+' || p[i - 1] == '-' ||
                p[i - 1] == '*' || p[i - 1] == divide_sign ||
                p[i - 1] == '^' ) { //����Ϊ��λ��ǰһλΪ�����
                num_stack_depth++;
            }
            if (dot_occupied != 0) {
                dot_cnt++;
            }
            numinstack(p[i], num_stack, dot_cnt);
            N_O = N_O_num; //N_O��־�л�Ϊ����
        } else { //˫Ŀ�����
            if (num_stack_depth == 0 || p[i - 1] == '+' || p[i - 1] == '-' ||
                p[i - 1] == '*' || p[i - 1] == divide_sign ||
                p[i - 1] == '^' /*p[i-1] is operator*/) { //δ�������ֻ�ǰһλΪ�����
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar_error
            }
            operator_stack_depth++;
            state_math = operatorinstack(num_stack, operator_stack, p[i]);
            if (state_math) {
                // math_error_alarm();
                state_cal = 2;
                return 2; // math_error
            }
            N_O = N_O_operator;
        }
        i++;
    }
    if (N_O == N_O_operator) { //���һλΪ�����
        // grammar_error_alarm();
        state_cal = 1;
        return 1; // grammar error
    } else {
        sqrt_cal(num_stack, sqrt_flag); //��sqrt��־λָ�����ֿ�������
        StackConvert(num_stack, operator_stack); //תΪ��׺���ʽ���㴦��
        while (operator_stack->top != 0) { //����ջδ��
            stack_calculation(num_stack, operator_stack); //ջ����
        }
        final_answer = NumStackOutput(num_stack); //����ջ���һλ������
        return 0;
    }
}


//---------------------���̼�ⲿ��--------------------------
sbit DAT = P3 ^ 6;
sbit CLK = P3 ^ 7;
int key;
uchar input_char[MAX] = {"                "
                         "                "};

void Init_Key() {
    int i;
    for (i = 0; i < 8; i++) {
        DAT = 0;
        CLK = 0;
        CLK = 1;
    }
}

void send_data(char keyscan) {
    int i = 0;
    for (i = 0; i < 8; i++) {
        if (keyscan & 0x80) {
            DAT = 1;
            CLK = 0;
            CLK = 1;
        } else {
            DAT = 0;
            CLK = 0;
            CLK = 1;
        }
        keyscan = keyscan << 1;
    }
}

int Key_Scan() {
    int button, temp = 0; //��P4
    //��ʼ�ް�������
    send_data(0x00);
    button = P4 & 0x0f;
    if (button != 0x0f) {//�м�����
        delay(10); //����
        button = P4 & 0x0f;
        if (button != 0x0f) //��������д��һλ�͵�ƽ�������п�ʼ���м�⣬P4��0��˵�������ڶ�Ӧ��
        {
            send_data(0xFE);
            temp = P4 & 0x0f;
            if (temp != 0x0f) {//��P4�ٴα�1�����ȷ�����µļ��ڶ�Ӧ��
                while (P4 != 0xFF) ;
                switch (button) {
                    case 0x0e:
                        return 0;
                    case 0x0d:
                        return 1;
                    case 0x0b:
                        return 2;
                    case 0x07:
                        return 3;
                    default:
                        break;
                }
            } else {
                //�ڶ���
                send_data(0xFD);
                temp = P4 & 0x0f;
                if (temp != 0x0f) {
                    while (P4 != 0xFF) ;
                    switch (button) {
                        case 0x0e:
                            return 4;
                        case 0x0d:
                            return 5;
                        case 0x0b:
                            return 6;
                        case 0x07:
                            return 7;
                        default:
                            break;
                    }
                } else {
                    //������
                    send_data(0xFB);
                    temp = P4 & 0x0f;
                    if (temp != 0x0f) {
                        while (P4 != 0xFF) ;
                        switch (button) {
                            case 0x0e:
                                return 8;
                            case 0x0d:
                                return 9;
                            case 0x0b:
                                return 10;
                            case 0x07:
                                return 11;
                            default:
                                break;
                        }
                    } else {
                        //������
                        send_data(0xF7);
                        temp = P4 & 0x0f;
                        if (temp != 0x0f) {
                            while (P4 != 0xFF) ;
                            switch (button) {
                                case 0x0e:
                                    return 12;
                                case 0x0d:
                                    return 13;
                                case 0x0b:
                                    return 14;
                                case 0x07:
                                    return 15;
                                default:
                                    break;
                            }
                        } else {
                            //������
                            send_data(0xEF);
                            temp = P4 & 0x0f;
                            if (temp != 0x0f) {
                                while (P4 != 0xFF) ;
                                switch (button) {
                                    case 0x0e:
                                        return 16;
                                    case 0x0d:
                                        return 17;
                                    case 0x0b:
                                        return 18;
                                    case 0x07:
                                        return 19;
                                    default:
                                        break;
                                }
                            } else
                                return 20; //�޼�⵽����
                        }
                    }
                }
            }
        } else
            return 20;
    } else
        return 20;
    return 20;
}

char key_decode() {
    switch (key_scan()) {
    case 0:
        return '0';
        break; // 0

    case 1:
        return '1';
        break; // 1

    case 2:
        return '2';
        break; // 2

    case 3:
        return '3';
        break; // 3

    case 4:
        return '4';
        break; // 4

    case 5:
        return '5';
        break; // 5

    case 6:
        return '6';
        break; // 6

    case 7:
        return '7';
        break; // 7

    case 8:
        return '8';
        break; // 8

    case 9:
        return '9';
        break; // 9

    case 10:
        return '.';
        break; //.

    case 11:
        return '=';
        break; //=

    case 12:
        return divide_sign;
        break; // F1-/

    case 13:
        return '*';
        break; // F2-*

    case 14:
        return '-';
        break; // F3--

    case 15:
        return '+';
        break; // F4-+

    case 16:
        return back_sign;
        break; // F5-sqrt

    case 17:
        return 't';
        break; // F6-Trans

    case 18:
        return '^';
        break; // F7-power

    case 19:
        return sqrt_sign;
        break; // F8-sqrt

    default:
        return 20;
        break;
    }
}

void wr_lcd(uchar dat_comm, uchar content) {
    if (dat_comm) {
        rs = 1; // data
        rw = 0; // write
    } else {
        rs = 0; // command
        rw = 0; // write
    }
    P2 = content; // output data or comm
    e = 1;
    delay(1);
    e = 0;
}
/*----------------��ʾ�ַ�-----------------*/
void chrt_disp_first(uchar *chrt, uint length_chrt) {
    uchar i, j;
    wr_lcd(comm, 0x80);
    if (length_chrt < 16) {
        for (i = 0; i < 16; i++)
            wr_lcd(dat, chrt[i]);
        wr_lcd(comm, 0xc0);
    } else {
        for (i = 0; i < 16; i++)
            wr_lcd(dat, chrt[i + length_chrt - 16]);
        wr_lcd(comm, 0xc0);
    }
}
void chrt_disp(uchar *chrt) {
    uchar i, j;
    wr_lcd(comm, 0x80);
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 16; i++)
            wr_lcd(dat, chrt[j * 16 + i]);
        wr_lcd(comm, 0xc0);
    }
}

/*------------------��ʼ��------------------*/
void init_lcd(void) {
    e = 0;
    delay(200);
    wr_lcd(comm, 0x01); /*��������ַָ��ָ�� 00H*/
    delay(60);
    wr_lcd(comm, 0x06); /*�����ƶ�����*/
    delay(60);
    wr_lcd(comm, 0x0c); /*����ʾ���ع�꣬����˸*/
    delay(60);
    wr_lcd(comm, 0x38); /*8 λ�ӿ�������ʾģʽ*/
    delay(60);
    chrt_disp(init_tab);
    delay(30000);
}

/*-----------------����ģ-----------------*/
void cgram_wr(uchar zm_data1, uchar zm_data2) {
    uchar i, j;
    wr_lcd(comm, 0x40);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 4; i++) {
            wr_lcd(dat, zm_data1);
            wr_lcd(dat, zm_data2);
        }
    }
}
void cgram_disp(void) {
    uchar i, j;
    wr_lcd(comm, 0x80);
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            wr_lcd(dat, i);
        for (i = 0; i < 8; i++)
            wr_lcd(dat, i);
        wr_lcd(comm, 0xc0);
    }
}

/*--------------ldoubleת�ַ���--------------*/
void ldouble2str(ldouble f, uchar *s) {
    long int n_int = 0;
    int bits_10;
    n_int = (long int)f;
    if (n_int == 0) {
        bits_10 = 1;
    } else {
        bits_10 = log10(abs(n_int)) + 1; //��������λ��
    }
    if (f < 0) {//��ȡ����
        *s = '-';
        s += 1;
        f = -f;
    } else {
        *s = ' ';
        s += 1;
    }
    switch (bits_10) { //��������λ������С������
    case 1:
        sprintf(s, "%.4f", f);
        break;
    case 2:
        sprintf(s, "%.3f", f);
        break;
    case 3:
        sprintf(s, "%.2f", f);
        break;
    case 4:
        sprintf(s, "%.1f", f);
        break;
    case 5:
        sprintf(s, "%.0f", f);
        break;
    default:
        state_cal = 3;
        break;
    }
}

/*-----------------������-----------------*/
uint key_num;
uint cnt_tab;
uint length_input = 0;
ldouble ans = 0;

uint state_now = s_0;
uint state_next = s_0;
int _is_tr_ini = 0;
num_type *num_struct;
// previous define: uchar input_char[50];
void clear_data() {
    int i;
    for (i = 0; i < MAX; i++) {
        input_char[i] = ' ';
    };
    cnt_tab = 0;
    length_input = 0;
    ans = 0;
    _is_tr_ini = 0;
    state_cal = 0;

    chrt_disp(clear_tab);
}

void Transform_Initial() {

    num_struct = num_init();
    // clear_data();
    switch (mode_trans_in) {
    case sc_bin:
        input_char[0] = 'B';
        break;
    case sc_oct:
        input_char[0] = 'O';
        break;
    case sc_dec:
        input_char[0] = 'D';
        break;
    case sc_hex:
        input_char[0] = 'H';
        break;
    default:
        break;
    }
    input_char[1] = 0x7E;
    switch (mode_trans_out) {
    case sc_bin:
        input_char[2] = 'B';
        break;
    case sc_oct:
        input_char[2] = 'O';
        break;
    case sc_dec:
        input_char[2] = 'D';
        break;
    case sc_hex:
        input_char[2] = 'H';
        break;
    default:
        break;
    }
    input_char[3] = ' ';
    cnt_tab = 4;
}

void main() {
    int i = 0;
    int bits_bin = 1;
    int bits_dec = 1;
    int bits_hex = 1;
    int bits_oct = 1;
    int I_A = 0; // Input-0, Ans-1
    uchar ans_dis[16] = "                ";
    uchar ans_dis_high[16] = "                ";
    uchar ans_dis_mid[16] = "                ";
    uchar ans_dis_low[16] = "                ";
    uchar ans_display[] = {"                "
                           "                "};
    init_mempool(&malloc_mempool, sizeof(malloc_mempool));
    Init_Device();
    beep = 0;
    delay(1000);
    init_lcd();
    delay(1000);
    Init_Key();
    cnt_tab = 0;

    chrt_disp_first(input_char, cnt_tab);
    cgram_wr(0x00, 0x00);
    cgram_disp();
    while (1) {
        switch (state_now) {
        case s_0: //��ͨ��������ģʽ
            if (I_A == 0) {
                chrt_disp_first(input_char, cnt_tab);
                // ��ʼ��
                ans_dis[16] = "                ";
                ans_dis_high[16] = "                ";
                ans_dis_mid[16] = "                ";
                ans_dis_low[16] = "                ";
                ans_display[32] = "                                ";
                final_answer.f_high = 0;
                final_answer.f_mid = 0;
                final_answer.f_low = 0;
            } else {
                chrt_disp(ans_display);
            }
            key_num = key_decode();
            if (key_num != 20 && key_num != '=' && key_num != 't' && key_num != back_sign) {
                if (cnt_tab >= 30) { //�����������λ����
                    beep_long();
                } else { //�����δ���������ַ�
                    input_char[cnt_tab] = key_num;
                    cnt_tab++;
                    length_input++;
                }
            } else if (key_num == back_sign) {
                if (cnt_tab > 0) { //�����δ�գ����ĩλ�ַ�
                    cnt_tab--;
                    length_input--;
                    input_char[cnt_tab] = ' ';
                } else { //�����Ϊ�գ���λ����
                    beep_long();
                }
            } else if (key_num == 't') {//ģʽת��Ϊ����ת��ģʽ
                state_next = s_6;
                clear_data();
            } else if (key_num == '=') {//ģʽת��Ϊ���ģʽ
                I_A = 1;
                state_next = s_1;
            }
            break;
        case s_1: //��ͨ��������ʾģʽ
            ans = cal_algorithm(input_char, length_input);
            if (state_cal == 0) {
                for (i = 0; i < 16; i++) {
                    ans_display[i] = input_char[i];
                }
                ldouble2str(final_answer.f_high, ans_dis_high);
                ldouble2str(final_answer.f_mid, ans_dis_mid);
                ldouble2str(final_answer.f_low, ans_dis_low);
                for (i = 18; i < 25; i++) {
                    ans_display[i] = ans_dis_high[i - 18];
                }
                for (i = 25; i < 29; i++) {
                    ans_display[i] = ans_dis_mid[i - 25 + 3];
                }
                for (i = 29; i < 32; i++) {
                    ans_display[i] = ans_dis_low[i - 29 + 3];
                }
                state_next = s_1;
                beep_short();
                chrt_disp(ans_display);
                while (1) {
                    key_num = key_decode();
                    if (key_num != 20) {
                        clear_data();
                        state_next = s_0; //�ع�����ģʽ
                        I_A = 0;
                        break;
                    }
                }
                break;
            } else {
                state_next = s_2;
            }

            // state_next = s_2;
            break;
        case s_2: //�������ģʽ
            if (state_cal == 1) {
                // ans_display[0:15] = "Syntax Error!";
                ans_display[0] = 'S';
                ans_display[1] = 'y';
                ans_display[2] = 'n';
                ans_display[3] = 't';
                ans_display[4] = 'a';
                ans_display[5] = 'x';
                ans_display[6] = ' ';
                ans_display[7] = 'E';
                ans_display[8] = 'r';
                ans_display[9] = 'r';
                ans_display[10] = 'o';
                ans_display[11] = 'r';
                ans_display[12] = '!';
                ans_display[13] = '\0';
                alarm_syntax();
            } else if (state_cal == 2) {
                // ans_display[0:15] = "Math Error!";
                ans_display[0] = 'M';
                ans_display[1] = 'a';
                ans_display[2] = 't';
                ans_display[3] = 'h';
                ans_display[4] = ' ';
                ans_display[5] = 'E';
                ans_display[6] = 'r';
                ans_display[7] = 'r';
                ans_display[8] = 'o';
                ans_display[9] = 'r';
                ans_display[10] = '!';
                ans_display[11] = '\0';
                alarm_math();
            }
            // beep_short();
            chrt_disp(ans_display);
            while (1) {
                key_num = key_decode();
                if (key_num != 20) {
                    clear_data();
                    state_next = s_0; //�ع�����ģʽ
                    I_A = 0;
                    break;
                }
            }
            // state_next = s_2;
            break;
        case s_3: // shift����ģʽ��δ��д
            break;

        case s_4: //ģʽѡ��ģʽ��δ��д
            break;
        case s_5: // shift����ת������ģʽ
            state_next = s_5;
            key_num = key_decode();
            if (key_num != 20) {
                beep_short();
                switch (key_num) {
                case '0': // b->b
                    mode_trans_in = sc_bin;
                    mode_trans_out = sc_bin;
                    state_next = s_6;
                    break;
                case '1': // b->o
                    mode_trans_in = sc_bin;
                    mode_trans_out = sc_oct;
                    state_next = s_6;
                    break;
                case '4': // b->d
                    mode_trans_in = sc_bin;
                    mode_trans_out = sc_dec;
                    state_next = s_6;
                    break;
                case '7': // b->h
                    mode_trans_in = sc_bin;
                    mode_trans_out = sc_hex;
                    state_next = s_6;
                    break;
                case '.': // o->b
                    mode_trans_in = sc_oct;
                    mode_trans_out = sc_bin;
                    state_next = s_6;
                    break;
                case '2': // o->o
                    mode_trans_in = sc_oct;
                    mode_trans_out = sc_oct;
                    state_next = s_6;
                    break;
                case '5': // o->d
                    mode_trans_in = sc_oct;
                    mode_trans_out = sc_dec;
                    state_next = s_6;
                    break;
                case '8': // o->h
                    mode_trans_in = sc_oct;
                    mode_trans_out = sc_hex;
                    state_next = s_6;
                    break;
                case '=': // d->b
                    mode_trans_in = sc_dec;
                    mode_trans_out = sc_bin;
                    state_next = s_6;
                    break;
                case '3': // d->o
                    mode_trans_in = sc_dec;
                    mode_trans_out = sc_oct;
                    state_next = s_6;
                    break;
                case '6': // d->d
                    mode_trans_in = sc_dec;
                    mode_trans_out = sc_dec;
                    state_next = s_6;
                    break;
                case '9': // d->h
                    mode_trans_in = sc_dec;
                    mode_trans_out = sc_hex;
                    state_next = s_6;
                    break;
                case divide_sign: // h->b
                    mode_trans_in = sc_hex;
                    mode_trans_out = sc_bin;
                    state_next = s_6;
                    break;
                case '*': // h->o
                    mode_trans_in = sc_hex;
                    mode_trans_out = sc_oct;
                    state_next = s_6;
                    break;
                case '-': // h->d
                    mode_trans_in = sc_hex;
                    mode_trans_out = sc_dec;
                    state_next = s_6;
                    break;
                case '+': // h->h
                    mode_trans_in = sc_hex;
                    mode_trans_out = sc_hex;
                    state_next = s_6;
                    break;
                case 't':
                    state_next = s_6;
                    break;
                default:
                    break;
                }
                Transform_Initial();
                chrt_disp_first(input_char, cnt_tab);
                cgram_wr(0x00, 0x00);
            }
            break;
        case s_6: //����ת������ģʽ
            if (!_is_tr_ini) {
                Transform_Initial();
                _is_tr_ini = 1;
            }
            if (I_A == 0) {
                chrt_disp_first(input_char, cnt_tab);
                cgram_wr(0x00, 0x00);
                // cgram_disp();
            } else {
                chrt_disp(ans_display);
                cgram_wr(0x00, 0x00);
                // cgram_disp();
            }
            key_num = key_decode();
            if (key_num != 20) {
                if (key_num == 't') {
                    state_next = s_5;
                    // clear_data();
                } else if (key_num <= '9' && key_num >= '0') {
                    if (cnt_tab >= 30) {
                        beep_long();
                        continue;
                    } else {
                        input_char[cnt_tab] = key_num;
                        cnt_tab++;
                        length_input++;
                        // beep_short();
                    }
                } else if (key_num == '=') {
                    // ans = oct_trans();

                    for (i = 0; i < 16; i++) {
                        ans_display[i] = input_char[i];
                    }
                    for (i = 4; i < cnt_tab; i++) {
                        ans_dis[i - 4] = input_char[i];
                    }
                    num_input(num_struct, mode_trans_in, mode_trans_out,
                              ans_dis);
                    if (state_cal == 0) {
                        if (num_struct->number == 0) {
                            bits_bin = 1;
                            bits_oct = 1;
                            bits_dec = 1;
                            bits_hex = 1;
                        } else {
                            bits_bin = (int)(log10(abs(num_struct->number)) /
                                             log10(2)) +
                                       1;
                            bits_oct = (int)(log10(abs(num_struct->number)) /
                                             log10(8)) +
                                       1;
                            bits_dec = log10(abs(num_struct->number)) + 1;
                            bits_hex = (int)(log10(abs(num_struct->number)) /
                                             log10(16)) +
                                       1;
                        }

                        switch (mode_trans_out) {
                        case sc_bin:
                            for (i = 32 - bits_bin; i < 32; i++) {
                                ans_display[i] =
                                    num_struct->bin[i - 32 + bits_bin];
                            }
                            break;
                        case sc_oct:
                            for (i = 32 - bits_oct; i < 32; i++) {
                                ans_display[i] =
                                    num_struct->oct[i - 32 + bits_oct];
                            }
                            break;
                        case sc_dec:
                            for (i = 32 - bits_dec; i < 32; i++) {
                                ans_display[i] =
                                    num_struct->dec[i - 32 + bits_dec];
                            }
                            break;
                        case sc_hex:
                            for (i = 32 - bits_hex; i < 32; i++) {
                                ans_display[i] =
                                    num_struct->hex[i - 32 + bits_hex];
                            }
                            break;
                        default:
                            break;
                        }
                        I_A = 1;
                        beep_short();
                    } else if (state_cal == 3) {
                        // ans_display[0:15] = "Overflow Error!";
                        ans_display[0] = 'O';
                        ans_display[1] = 'v';
                        ans_display[2] = 'e';
                        ans_display[3] = 'r';
                        ans_display[4] = 'f';
                        ans_display[5] = 'l';
                        ans_display[6] = 'o';
                        ans_display[7] = 'w';
                        ans_display[8] = ' ';
                        ans_display[9] = 'E';
                        ans_display[10] = 'r';
                        ans_display[11] = 'r';
                        ans_display[12] = 'o';
                        ans_display[13] = 'r';
                        ans_display[14] = '!';
                        ans_display[15] = '\0';
                        alarm_syntax();
                    }
                    chrt_disp(ans_display);
                    cgram_wr(0x00, 0x00);
                }
            }
            break;
        }
        state_now = state_next;
    }
}

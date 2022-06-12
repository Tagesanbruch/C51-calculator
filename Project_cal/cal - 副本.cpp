#define uchar unsigned char
#define uint unsigned int
#define N_O_num 0
#define N_O_operator 1
#define MAX 200+10
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//双精度数字结构体
typedef struct {
    float f_high;
    float f_low;
} dfloat;

void save_dfloat(dfloat* d, float f_high, float f_low) {
    d->f_high = f_high;
    d->f_low = f_low;
}

//计算结果结构体
typedef struct {
    dfloat d_result;
    int i_result;
} result;

dfloat d_add_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high + d2.f_high;
    f_low = d1.f_low + d2.f_low;
    if (f_low >= 1) {
        f_high += 1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_add_df(dfloat d1, float f1) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high + f1;
    f_low = d1.f_low;
    if (f_low >= 1) {
        f_high += 1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_sub_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high - d2.f_high;
    f_low = d1.f_low - d2.f_low;
    if (f_low < 0) {
        f_high -= 1;
        f_low += 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_sub_df(dfloat d1, float f1) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high - f1;
    f_low = d1.f_low;
    if (f_low < 0) {
        f_high -= 1;
        f_low += 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_mul_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high * d2.f_high;
    f_low = d1.f_low * d2.f_low;
    if (f_low >= 1) {
        f_high += d2.f_high;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_mul_df(dfloat d1, float f1) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high * f1;
    f_low = d1.f_low * f1;
    if (f_low >= 1) {
        f_high += f1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_div_dd(dfloat d1, dfloat d2) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high / d2.f_high;
    f_low = d1.f_low / d2.f_low;
    if (f_low >= 1) {
        f_high += 1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}
dfloat d_div_df(dfloat d1, float f1) {
    dfloat d_result;
    float f_high, f_low;
    f_high = d1.f_high / f1;
    f_low = d1.f_low / f1;
    if (f_low >= 1) {
        f_high += 1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

dfloat d_pow_df(dfloat d1, float f1) {
    dfloat d_result;
    float f_high, f_low;
    f_high = pow(d1.f_high, f1);
    f_low = pow(d1.f_low, f1);
    if (f_low >= 1) {
        f_high += 1;
        f_low -= 1;
    }
    save_dfloat(&d_result, f_high, f_low);
    return d_result;
}

//操作符栈定义，用于操作符存储
typedef struct {
    char data_s[MAX];
    int top;
    int bottom;
}OpeStack;

OpeStack* OpeStackCreate() {
    OpeStack* p = (OpeStack*)malloc(sizeof(OpeStack));//分配新空间 
    if (p == NULL)//分配失败 
        return 0;
    p->bottom = p->top = 0;//分配成功 
    return p;
}

void OpeStackInput(OpeStack* p, char str) {
    p->data_s[p->top] = str;//存入栈中 
    p->top++;//栈顶指针加1 
}

char OpeStackOutput(OpeStack* p) {
    char str;
    if (p->top != p->bottom) {//栈非空 
        str = p->data_s[p->top - 1];//栈顶内容输出 
        p->top--;//栈顶减1 
        return str;
    }
}

uint priority_operator(uchar operator_char) {
    switch (operator_char)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    default:
        return 0;
        break;
    }

}

void OpeStackConvert(OpeStack* p) {
    int pointer = 0;
    int length = p->top - p->bottom;
    uchar ope_tmp[MAX];
    for (int i = 0; i < length; i++) {
        ope_tmp[pointer++] = OpeStackOutput(p);
    }
    pointer = 0;
    for (int i = 0; i < length; i++) {
        OpeStackInput(p, ope_tmp[pointer]);
        pointer++;
    }
}


//数字栈定义，用于数字存储
typedef struct {
    dfloat data_s[MAX];
    int top;
    int bottom;
}NumStack;

NumStack* NumStackCreate() {
    NumStack* p = (NumStack*)malloc(sizeof(NumStack));//分配新空间 
    if (p == NULL)//分配失败 
        return 0;
    p->bottom = p->top = 0;//分配成功 
    return p;
}

void NumStackInput(NumStack* p, float f) {
    save_dfloat(p->data_s, f, 0);//存入栈中 
    p->top++;//栈顶指针加1 
}

void NumStackInput_dfloat(NumStack* p, dfloat f) {
    p->data_s[p->top] = f;//存入栈中 
    p->top++;//栈顶指针加1 
}

dfloat NumStackOutput(NumStack* p) {
    dfloat f;
    if (p->top != p->bottom) {//栈非空 
        f = p->data_s[p->top - 1];//栈顶内容输出 
        p->top--;//栈顶减1 
        return f;
    }
}
void NumStackConvert(NumStack* p) {
    int pointer = 0;
    int length = p->top - p->bottom;
    dfloat num_tmp[MAX];
    for (int i = 0; i < length; i++) {
        num_tmp[pointer++] = NumStackOutput(p);
    }
    pointer = 0;
    for (int i = 0; i < length; i++) {
        NumStackInput_dfloat(p, num_tmp[pointer]);
        pointer++;
    }
}

int numinstack(uint num, NumStack* p, uint dot_occupied) {
    int i;
    dfloat num_ans, num_pre;
    num = num - 48;
    num_pre = NumStackOutput(p);
    if (dot_occupied == 0) {
        num_ans = d_add_df(d_mul_df(num_pre, 10), (float)num);
    }
    else {
        num_ans = num_pre;
        for (i = 0; i < dot_occupied; i++)
        {
            num_ans = d_mul_df(num_pre, 10);
        }
        num_ans = d_add_df(num_ans, (float)num);
        for (i = 0; i < dot_occupied; i++)
        {
            num_ans = d_div_df(num_pre, 10);
        }
    }
    NumStackInput_dfloat(p, num_ans);
    return 0;
}

int stack_calculation(NumStack* n, OpeStack* o) {
    dfloat n1, n2;
    dfloat n_ans;
    char o1;
    n1 = NumStackOutput(n);
    o1 = OpeStackOutput(o);
    n2 = NumStackOutput(n);
    switch (o1)
    {
    case '+':
        n_ans = d_add_dd(n1, n2);
        break;
    case '-':
        n_ans = d_sub_dd(n1, n2);
        break;
    case '*':
        n_ans = d_mul_dd(n1, n2);
        break;
    case '/':
        if (fabs(n2.f_high) < 1e-6) return -1; //在精度为1e-6条件下判断除数是否为0，为0输出计算错误
        n_ans = d_div_dd(n1, n2);
        break;
    default:
        break;
    }
    NumStackInput_dfloat(n, n_ans);
}



int operatorinstack(NumStack* n, OpeStack* o, char ope) {
    //优先级：() > /sqrt() > ^ > * / > + -
    char o1;
    int state;
    o1 = o->data_s[o->top - 1];
    if (o->top == 0 || priority_operator(o1) >= priority_operator(ope)) { //栈顶运算符优先级不小于入栈元素
        OpeStackInput(o, ope);
        return 0;
    }
    OpeStackInput(o, ope);
    state = stack_calculation(n, o);
    if (state == -1) {
        return -1;
    }
    return 0;
}
//输入错误：1. 运算符号相连（或与小数点）；2. 一个数中出现两个小数点；3. 除以0； 4. 开方下为负数？； 5. 0^0


int state_cal = 0;
dfloat final_answer;
#define sqrt_sign 0xE8
#define back_sign 0x7F
#define divide_sign 0xFD
int cal_algorithm(uchar* p, uint length_p)
{
    // uint length_p = strlen(p);
    uint i = 0;
    uint dot_occupied = 0;
    uint dot_cnt = 0;
    uint N_O = N_O_operator;
    uint num_stack_depth = 0;
    uint operator_stack_depth = 0;
    int state_math;

    int sqrt_flag[MAX] = 0;
    int sqrt_flag_cnt = 0;
    NumStack* num_stack;
    OpeStack* operator_stack;
    num_stack = NumStackCreate();
    operator_stack = OpeStackCreate();

    while (i < length_p)
    {
        if (p[i] == '.')
        {
            if (dot_occupied != 0)
            {
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar error
            }
            N_O = N_O_num;
            dot_occupied = 1; // dot occupation, if last char isnt num, then fill with 0 automatically
        }
        else if (p[i] == sqrt_sign)
        {
            if (sqrt_flag_cnt == num_stack->top + 1)
            {
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar error
            }
            if (N_O == N_O_operator)
            {
                sqrt_flag_cnt = num_stack->top;
            }
            else
            {
                operatorinstack(num_stack, operator_stack, '*');
                sqrt_flag_cnt = num_stack->top;
            }
            sqrt_flag[sqrt_flag_cnt] = 1;
            N_O = N_O_operator;
        }
        else if (p[i] <= '9' && p[i] >= '0')
        {
            if (N_O == N_O_operator)
            {
                dot_occupied = 0;
                dot_cnt = 0;
                NumStackInput(num_stack, 0);
            }
            if (i == 0 || p[i - 1] == '+' || p[i - 1] == '-' || p[i - 1] == '*' || p[i - 1] == divide_sign || p[i - 1] == '^' /*p[i-1] is operator*/)
            {
                num_stack_depth++;
            }
            if (dot_occupied != 0)
            {
                dot_cnt++;
            }
            numinstack(p[i], num_stack, dot_cnt);
            N_O = N_O_num;
        }
        else
        {
            if (num_stack_depth == 0 || p[i - 1] == '+' || p[i - 1] == '-' || p[i - 1] == '*' || p[i - 1] == divide_sign || p[i - 1] == '^' /*p[i-1] is operator*/)
            {
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar_error
            }
            operator_stack_depth++;
            state_math = operatorinstack(num_stack, operator_stack, p[i]);
            if (state_math)
            {
                // math_error_alarm();
                state_cal = 2;
                return 2; // math_error
            }
            N_O = N_O_operator;
        }
        i++;
    }
    if (N_O == N_O_operator)
    {
        // grammar_error_alarm();
        state_cal = 1;
        return 1; // grammar error
    }
    else
    {
        // ldouble num_tmp[num_stack->top];
        sqrt_cal(num_stack, sqrt_flag);
        StackConvert(num_stack, operator_stack);
        // OpeStackConvert(operator_stack);
        // for (i = num_stack->top - 1; i >= 1; i--) {

        // }
        while (operator_stack->top != 0)
        {
            stack_calculation(num_stack, operator_stack);
        }
        final_answer = NumStackOutput(num_stack);
        return 0;
    }
}


int main() {
    float ans;
    uchar input_char[] = "1+11*21";
    uint length_char;
    length_char = 7;
    ans = cal_algorithm(input_char, length_char);
    printf("%.6f", ans);
}
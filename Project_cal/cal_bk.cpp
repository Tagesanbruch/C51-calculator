#define uchar unsigned char
#define uint unsigned int
#define ldouble long double
#define N_O_num 0
#define N_O_operator 1
#define MAX 200+10

#define sqrt_sign 0xE8
#define back_sign 0x7F

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int state_cal = 0;//全局变量
int state_math = 0;
int sqrt_flag[10] = {0};
int sqrt_flag_pointer = 0;

ldouble sqrt_cal(ldouble num) {
    if (num < 0) {
        // math_error_alarm();
        state_cal = 2;
        return 2; //math_error
    }
    return sqrt(num);
}
//操作符栈定义，用于操作符存储
typedef struct {
    char data[MAX];
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

void OpeStackCopy(OpeStack* p1, OpeStack* p2) { //p1<-p2
    int i;
    p1->top = p2->top;
    p1->bottom = p2->bottom;
    for (i = p1->bottom; i <= p1->top; i++) {
        p1->data[i] = p2->data[i];
    }
}

void OpeStackInput(OpeStack* p, char str) {
    p->data[p->top] = str;//存入栈中 
    p->top++;//栈顶指针加1 
}

char OpeStackOutput(OpeStack* p) {
    char str;
    if (p->top != p->bottom) {//栈非空 
        str = p->data[p->top - 1];//栈顶内容输出 
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
    case '^':
        return 3;
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
    ldouble data[MAX];
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

void NumStackCopy(NumStack* p1, NumStack* p2) { //p1<-p2
    int i;
    p1->top = p2->top;
    p1->bottom = p2->bottom;
    for (i = p1->bottom; i <= p1->top; i++) {
        p1->data[i] = p2->data[i];
    }
}

void NumStackInput(NumStack* p, ldouble str) {
    p->data[p->top] = str;//存入栈中 
    p->top++;//栈顶指针加1 
}

ldouble NumStackOutput(NumStack* p) {
    ldouble str;
    if (p->top != p->bottom) {//栈非空 
        str = p->data[p->top - 1];//栈顶内容输出 
        p->top--;//栈顶减1 
        return str;
    }
}

int stack_calculation(NumStack* n, OpeStack* o) {
    ldouble n1, n2;
    ldouble n_ans = 0;
    char o1;
    n1 = NumStackOutput(n);
    o1 = OpeStackOutput(o);
    n2 = NumStackOutput(n);
    switch (o1)
    {
    case '+':
        n_ans = n1 + n2;
        break;
    case '-':
        n_ans = n1 - n2;
        break;
    case '*':
        n_ans = n1 * n2;
        break;
    case '/':
        if (fabs(n2) < 1e-6) return -1; //在精度为1e-6条件下判断除数是否为0，为0输出计算错误
        n_ans = n1 / n2;
        break;
    case '^':
        if (fabs(n1) < 1e-6 && n2 < 1e-6) {
            state_cal = 2;
            return -1;
        }
        n_ans = pow(n1, n2);
        break;
    default:
        break;
    }
    NumStackInput(n, n_ans);
}


void StackConvert(NumStack* n, OpeStack* o) {
    //change
#define ldouble long double
    NumStack* ns_tmp;
    OpeStack* os_tmp;
    ldouble num_tmp;
    char ope_tmp;
    ns_tmp = NumStackCreate();
    os_tmp = OpeStackCreate();
    while (n->top != n->bottom)
    {
        num_tmp = NumStackOutput(n);
        NumStackInput(ns_tmp, num_tmp);
        if (o->top == o->bottom) {
            break;
        }
        ope_tmp = OpeStackOutput(o);
        if (os_tmp->top == os_tmp->bottom || priority_operator(ope_tmp) >= priority_operator(os_tmp->data[os_tmp->top - 1])) {
            OpeStackInput(os_tmp, ope_tmp);
            continue;
        }
        // OpeStackInput(o, ope_tmp);
        // NumStackInput(n, num_tmp);
        stack_calculation(ns_tmp, os_tmp);
        OpeStackInput(os_tmp, ope_tmp);
    }
    NumStackCopy(n, ns_tmp); //n = ns_tmp;
    OpeStackCopy(o, os_tmp); //o = os_tmp;
    /*
    int pointer = 0;
    int length = n->top - n->bottom;
    ldouble num_tmp[MAX];
    for (int i = 0; i < length; i++) {
        num_tmp[pointer++] = NumStackOutput(n);
    }
    pointer = 0;
    for (int i = 0; i < length; i++) {
        NumStackInput(n, num_tmp[pointer]);
        pointer++;
    }
    */

}

int numinstack(uint num, NumStack* p, uint dot_occupied) {
    ldouble num_ans, num_pre;
    int i = 0;
    num = num - 48;
    num_pre = NumStackOutput(p);
    if (dot_occupied == 0) {
        num_ans = 10 * num_pre + (ldouble)num;
    }
    else {
        num_ans = num_pre;
        for (i = 0; i < dot_occupied; i++)
        {
            num_ans *= 10;
        }
        num_ans += (ldouble)num;
        for (i = 0; i < dot_occupied; i++)
        {
            num_ans /= 10;
        }
    }
    NumStackInput(p, num_ans);
    return 0;
}



int operatorinstack(NumStack* n, OpeStack* o, char ope) {
    //优先级：() > /sqrt() > ^ > * / > + -
    char o1;
    int state;
    o1 = o->data[o->top - 1];
    if (o->top == 0 || priority_operator(o1) >= priority_operator(ope)) { //栈顶运算符优先级不小于入栈元素
        OpeStackInput(o, ope);
        return 0;
    }
    OpeStackInput(o, ope);
    // state = stack_calculation(n, o);
    // if (state == -1) {
    //     return -1;
    // }
    return 0;
}
//输入错误：1. 运算符号相连（或与小数点）；2. 一个数中出现两个小数点；3. 除以0； 4. 开方下为负数？； 5. 0^0



ldouble cal_algorithm(uchar* p, uint length_p) {
    //uint length_p = strlen(p);
    uint i = 0;
    uint dot_occupied = 0;
    uint dot_cnt = 0;
    uint N_O = N_O_operator;
    uint num_stack_depth = 0;
    uint operator_stack_depth = 0;
    int cal_state;
    NumStack* num_stack;
    num_stack = NumStackCreate();
    // ldouble num_stack[MAX];
    // NumStackInput(num_stack, 0);

    OpeStack* operator_stack;
    operator_stack = OpeStackCreate();

    while (i < length_p) {
        if (p[i] == '.') {
            if (dot_occupied != 0) {
                // grammar_error_alarm();
                return 1; //grammar error
            }
            N_O = N_O_num;
            dot_occupied = fmax(1, dot_cnt); //dot occupation, if last char isnt num, then fill with 0 automatically
        }
        else if (p[i] == sqrt_sign) {
            if (N_O == N_O_operator) {
                sqrt_flag_pointer = num_stack->top + 1;
                sqrt_flag[sqrt_flag_pointer] = 1;
            }
            else {
                operator_stack_depth++;
                state_math = operatorinstack(num_stack, operator_stack, '*');
                if (state_math) {
                    // math_error_alarm();
                    state_cal = 2;
                    return 2; //math_error
                }
                N_O = N_O_operator;
                sqrt_flag_pointer = num_stack->top + 1;
                sqrt_flag[sqrt_flag_pointer] = 1;
            }
        }
        else if (p[i] <= '9' && p[i] >= '0') {
            if (N_O == N_O_operator) {
                dot_occupied = 0;
                dot_cnt = 0;
                NumStackInput(num_stack, 0);
            }
            if (i == 0 || p[i - 1] == '+' || p[i - 1] == '-' || p[i - 1] == '*' || p[i - 1] == '/' || p[i - 1] == '^'/*p[i-1] is operator*/) {
                num_stack_depth++;
            }
            if (dot_occupied != 0) {
                dot_cnt++;
            }
            numinstack(p[i], num_stack, dot_cnt);
            N_O = N_O_num;
        }
        else {
            if (num_stack_depth == 0 || p[i - 1] == '+' || p[i - 1] == '-' || p[i - 1] == '*' || p[i - 1] == '/' || p[i - 1] == '^'/*p[i-1] is operator*/) {
                // grammar_error_alarm();
                return 1;
            }
            operator_stack_depth++;
            cal_state = operatorinstack(num_stack, operator_stack, p[i]);
            if (cal_state) {
                // math_error_alarm();
                return 2;
            }
            N_O = N_O_operator;
        }
        i++;
    }
    if (N_O == N_O_operator) {
        // grammar_error_alarm();
        return 1;
    }
    else {
        ldouble final_answer;
        //ldouble num_tmp[num_stack->top];
        for (i = 0; i <= num_stack->top - 1; i++) {
            if (sqrt_flag[i] == 1) {
                num_stack->data[i - 1] = sqrt_cal(num_stack->data[i - 1]);
            }
        }
        StackConvert(num_stack, operator_stack);
        // OpeStackConvert(operator_stack);
        // for (int i = num_stack->top - 1; i >= 1; i--) {

        // }
        while (operator_stack->top != 0) {
            stack_calculation(num_stack, operator_stack);
        }
        final_answer = NumStackOutput(num_stack);
        return final_answer;
    }
}

//uint length_uchar(uchar* p) {
//    int n = 0;
//    while (p++) {
//        n++;
//    }
//    return n;
//}
int main() {
    ldouble ans;
    long int n_int;
    int bits_10;
    // uchar input_char[] = "2+32++3^3-1000";
    uchar input_char[] = "1/3";
    char s[16];
    // input_char[2] = sqrt_sign;
    // input_char[1] = sqrt_sign;
    // input_char[5] = sqrt_sign;
    uint length_char;
    length_char = 3;
    ans = cal_algorithm(input_char, length_char);
    n_int = (long int)ans;
    if (n_int == 0) {
        bits_10 = 1;
    }
    else {
        bits_10 = log10(abs(n_int)) + 1;
    }
    switch (bits_10)
    {
    case 1:
        sprintf_s(s, sizeof(s), "%.11f", ans);
        break;
    case 2:
        sprintf_s(s, sizeof(s), "%.10f", ans);
        break;
    case 3:
        sprintf_s(s, sizeof(s), "%.9f", ans);
        break;
    case 4:
        sprintf_s(s, sizeof(s), "%.8f", ans);
        break;
    case 5:
        sprintf_s(s, sizeof(s), "%.7f", ans);
        break;
    case 6:
        sprintf_s(s, sizeof(s), "%.6f", ans);
        break;
    case 7:
        sprintf_s(s, sizeof(s), "%.5f", ans);
        break;
    case 8:
        sprintf_s(s, sizeof(s), "%.4f", ans);
        break;
    case 9:
        sprintf_s(s, sizeof(s), "%.3f", ans);
        break;
    case 10:
        sprintf_s(s, sizeof(s), "%.2f", ans);
        break;
    case 11:
        sprintf_s(s, sizeof(s), "%.1f", ans);
        break;
    case 12:
        sprintf_s(s, sizeof(s), "%.0f", ans);
        break;
    default:
        break;
    }    
    printf("%s", s);
}
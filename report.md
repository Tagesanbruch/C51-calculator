[toc]
# 任务要求

## 实验目的

## 实验要求

【基本要求】

1.	可以进行＋－×÷四则运算和平方、开方运算。

2.	显示界面可参考CASIO fx-350TL或类似功能的计算器，上面显示计算式，下面一行显示计算结果。

3.	有运算错误提示功能和输入限位功能（声光提示）

4.	其它指标参考现有的计算器。

【选作功能】
1.  可以进行数据制式转换（双字节）

2.  其它功能不变，精度改为12位

功能说明书：

本计算器为多功能12位精度计算器，可以进行加、减、乘、除、开方、乘幂、进制转换等运算功能，同时具有退格功能、输入限位、错误提示（包括语法错误、数学错误、进制转换时的溢出错误）等功能。
计算器具有两个模式：科学计算模式与程序员模式，其中不同模式的操作说明如下：
1. 12位精度计算模式：
   该模式下用户可进行四则运算与乘幂、开方等计算，按键说明如下：

   图1

   【常规输入】

   用户可在屏幕上方输入待求表达式，输入完毕时按下等于键，即可在第二行输出结果：

   图2

   此时按下任意键可重新输入计算式进行计算。

   【错误处理】

   用户在输入错误的表达式时，计算器蜂鸣器及LED灯会发出警报，在普通计算模式下错误有以下两种：

   (1) 语法错误（Syntax Error）：此错误是由用户输入了错误的表达式所导致，如以下的表达式：

   同一个数中出现了多个小数点：

   1..2+3

   表达式首位为运算符：

   +2/5×3

   连续出现两位运算符：

   1.5×+2
   计算式最末位为运算符：

   14-25+

   这几种情况系统将判定输入计算式出现了语法错误，声光提示并在显示器显示"Syntax Error!"，此时按任意键可返回；

   注：参考Casio fx-991计算器输入标准，以下左边几个输入式将不被判定为语法错误，并自动补全为右式计算返回结果：

   2.+3 -> 2.0+3=5

   2√5 -> 2×√5=4.472135955

   .93/3 -> 0.93/3=0.31
   
   48×.5 -> 48×0.5=24

   (2) 数学错误（Math Error）：此错误是用户输入了数学上无法求出的表达式导致的，具体错误有如下几种：

   除数为0（注意，此时若除数过小，小于精度1e-8时依然视为0，输出数学错误）：

   2/0

   幂底与幂指数同时为0：

   0^0

   这几种情况系统将判定输入计算式出现了数学错误，声光提示并在显示器显示"Math Error!"，此时按任意键可返回；

   【输入限位】
   计算器具有退格键，若用户误输入数据可通过退格键清除最末尾一位。但当输入表达式为空时，此时继续按退格键会触发限位警告，声光提示，输入无效。

   计算器表达式输入位有限制，系统初始化时设定为30位，当表达式输入位数超过此位时，系统将触发限位警告，声光提示，输入无效。

2. 程序员模式：

   该模式下用户可进行整数的二进制、八进制、十进制与十六进制间的转换，按键说明如下：

   图3

   【常规输入】

   用户可在屏幕上方输入待求数字，输入完毕时按下等于键，即可在第二行输出结果：

   图4

   此时按下任意键可重新输入计算式进行计算。

   【模式切换】

   用户可以在二进制、八进制、十进制、十六进制之间进行转换，此时需要先按下图3所示的SHIFT键，即可在不同模式间进行切换。切换完毕后，用户需要重新输入数字进行进制转换。

   【错误提示】
   该模式下限位提示与计算模式相同，此时输入位被设定为12位，超过12位时触发限位警告，声光提示，输入无效。

   该模式下输入数字有大小限制，由于显示屏第二行仅有16位，当输入的数字（十进制）超过65535时，系统将判定输入数字触发了溢出错误，声光提示并在显示器显示"Overflow Error!"，此时按任意键可返回。

# 设计思路
模块化分析：

整个计算器系统可进行分模块划分分析：

图5

计算器的输入部分包含键盘模块，键盘模块负责接收各位按键开关开闭情况，并将数据转换保存至系统内存中；
 
计算器的输出部分包含LCD显示屏模块、蜂鸣器及LED灯输出，显示模块将实时地输出已输入的内容、计算结果及其他必要的提示内容；蜂鸣器与LED灯则作为错误提示、限位功能的声光输出。
 
系统内部则包含系统初始化模块、输入转换模块、运算算法模块、输出转换模块、及系统状态机控制模块。系统初始化负责将单片机的各个必要模块进行初始化，使得系统能够得以正常工作；输入转换模块负责将外部的信号转换保存在系统中，输出转换模块则将系统内的变量以各种方式输出；运算算法模块建立了对于输入字符串的统一处理算法，以建立堆栈的形式，将运算字符串处理计算得到最终结果；系统状态机控制模块则控制系统的状态，使得系统可在计算模式、制式转换模式、错误处理模式、shift拓展按键模式等之间进行变换。
 
下面将具体地按层次对系统的各个模块进行分析：
 
## 设备初始化
 
首先简要介绍单片机的初始化流程。单片机的初始化主要分为三部分：看门狗的关闭、输入/输出端口配置、时钟配置。
 
上述配置函数基本可使用软件Configuration Wizard 2进行配置，在主函数中调用函数Init_Device()即可。

## 显示模块
本次实验使用的字符型 LCD 模块选用广东金鹏公司的 OCMC2X16A，电位器 W1 用来调节 LCD 的对比度，单片机的 P2 口为数据口，P3 口为 LCD 模块的控制口。连接电路图如下所示：

图（电路）

### 引脚描述

LCD屏幕对应引脚描述如下表所述：

//表格

### 工作时序

在执行不同的操作时，LCD显示屏需要一定的时序才能得以实现。不同操作时序图如下所示：


### 本实验使用命令描述

#### 清显示

指令码如下所示：

清显示指令将空位字符码 20H 送入全部 DDRAM 地址中，使 DDRAM 中的内容全部清除，显示消失；地址计数器 AC=0，自动增 1 模式；显示归位，光标或者闪烁回到原点（显示屏左上角）；但并不改变移位设置模式。

#### 输入模式设置
指令码如下所示：

I/D：字符码写入或者读出 DDRAM 后 DDRAM 地址指针 AC 变化方向标志：

I/D=1，完成一个字符码传送后，光标右移，AC 自动加 1；

I/D=0，完成一个字符码传送后，光标左移，AC 自动减 1；

S：显示移位标志：

S=1，将全部显示向右（I/D=0）或者向左（I/D=1）移位；

S=0，显示不发生移位；

S=1 时，显示移位时，光标似乎并不移位；此外，读 DDRAM 操作以及对 CGRAM 的访问，不发生显示移位。

#### 显示开关控制
指令码如下所示：

D：显示开/关控制标志：D=1，开显示；D=0，关显示；

关显示后，显示数据仍保持在 DDRAM 中，立即开显示可以再现；

C：光标显示控制标志：C=1，光标显示；C=0，光标不显示；
 
不显示光标并不影响模块其它显示功能；显示5X8点阵字符时，光标在第八行显示，显示5X10点阵字符时，光标在第十一行显示；
 
B：闪烁显示控制标志：B=1，光标所指位置上，交替显示全黑点阵和显示字符，产生闪烁效果，Fosc=250kHz时，闪烁频率为 0.4ms 左右；通过设置，光标可以与其所指位置的字符一起闪烁。
 
#### 功能设置
 
指令码如下所示
 
功能设置指令设置模块数据接口宽度和 LCD 显示屏显示方式，即 MPU 与模块接口数据总线为 4 位或者是 8位、LCD 显示行数和显示字符点阵规格；所以建议用户最好在执行其它指令设置（读忙标志指令除外）之前，在程序的开始，进行功能设置指令的执行；
 
DL：数据接口宽度标志：DL=1，8 位数据总线 DB7～DB0；DL=0，4 位数据总线 DB7～DB4，DB3～DB0 不用，使用此方式传送数据，需分两次进行；
 
N：显示行数标志：N=1，两行显示模式；N=0，单行显示模式；
 
F：显示字符点阵字体标志：F=1：5X10 点阵＋光标显示模式；F=0：5X7 点阵＋光标显示模式。   
  
### 程序实现
  
## 按键模块
 
系统的输入模块为4*5的矩阵键盘，其中使用了74HC164进行外部按键扫描，故单片机仅使用了P3.6~P3.7与P4.0~P4.3共6位引脚，来实现进行键盘读取功能。
 
图（电路）
  
### 按键去抖
 
单片机使用的机械按键易出现抖动，此时可使用软件去抖方法对按键进行去抖处理：
 
图
  
### 移位寄存器74HC164
 
74HC164的引脚图如下图所示：
 
图
 
其是8位边沿触发式移位寄存器：串行输入数据，然后并行输出(即串入并出)。数据通过两个输入端（A 或 B）之一串行输入；任一输入端可以用作高电平使能端，控制另一输入端的数据输入。两个输入端或者连接在一起，或者把不用的输入端接高电平，一定不要悬空。
  
时钟 (CLK) 每次由低变高时，数据右移一位，输入到 Q0， Q0 是两个数据输入端（A 和 B）的逻辑与，它将上升时钟沿之前保持一个建立时间的长度。
  
主复位 (CLR) 输入端上的一个低电平将使其它所有输入端都无效，同时非同步地清除寄存器，强制所有的输出为低电平。
 
### 行列扫描
 
由上所述，按键扫描可以使用公共端对74HC164进行扫描，此时有两种情况：
 
(1)公共端接地，74HC164定时扫描出高电平
 
扫描时若公共端出现高电平，则按下短路按键的行位，可确定为74HC164扫描对应位。
 
(2)公共端上拉，74HC164定时扫描出低电平
 
扫描时若公共端出现低电平，则按下短路按键的行位，可确定为74HC164扫描对应位。
 
根据这个思路可以写出键盘扫描函数如下：

```cpp
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
    int button, temp = 0; //读P4
    //初始无按键按下
    send_data(0x00);
    button = P4 & 0x0f;
    if (button != 0x0f) {//有键按下
        delay(10); //消抖
        button = P4 & 0x0f;
        if (button != 0x0f) //在上升沿写入一位低电平，从首行开始逐行检测，P4变0则说明按键在对应行
        {
            send_data(0xFE);
            temp = P4 & 0x0f;
            if (temp != 0x0f) {//若P4再次变1，则可确定按下的键在对应行
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
                //第二行
                //......
                }else //...省略
                    return 20; //无检测到按键
        } else
            return 20;
    } else
        return 20;
    return 20;
}
```

此时即可根据Key_Scan返回值进行译码处理，得到输入的键盘情况。

## 计算器核心算法

计算器的核心是对输入的一个数字、小数点、运算符混合字符串进行读取并处理，其涉及编译原理，核心算法可划分为四个部分：1.读字符串；2.词法分析；3.语法分析；4.后缀表达式求值。

### 0. 基本数据结构介绍：建立堆栈数据结构

字符串中包含的字符元素有几种类型：数字、双目运算符（加、减、乘、除及幂）、单目运算符（开方）及小数点。为方便字符串的处理，我们需要将元素分类以堆栈形式存储（主要是数字与双目运算符）。

#### 堆栈数据结构&基本操作

下面介绍建立的堆栈数据结构形式与基本操作。堆栈表示后进先出（LIFO）的对象，在程序中堆栈定义为结构体，包括一个存储元素的数组元素及栈顶、栈底指针。（图、代码）

以数字栈为例，下面介绍几个堆栈基本操作（运算符栈同理）：

1. 堆栈创建
   堆栈的创建需要使用malloc函数为堆栈赋予RAM空间进行存储，同时进行初始化：
```cpp
NumStack *NumStackCreate()
{
    NumStack *p = (NumStack *)malloc(sizeof(NumStack)); //为堆栈在RAM区分配新空间
    if (p == NULL)//分配失败 
        return 0;
    p->bottom = p->top = 0; //分配成功
    return p;
}
```
2. 堆栈复制
   算法执行过程中，有的时候可能需要将一个堆栈元素完全复制为另一个堆栈，只需要一一对元素进行对应赋值即可：
```cpp
void NumStackCopy(NumStack *p1, NumStack *p2)// p1<-p2
{ 
    int i;
    p1->top = p2->top;
    p1->bottom = p2->bottom;
    for (i = p1->bottom; i <= p1->top; i++)
    {
        p1->data_s[i] = p2->data_s[i];
    }
}
```
3. 元素入栈与出栈
栈的元素遵循后入先出的规则（LIFO, Last In First Out），程序实现只需要对堆栈的顶部元素及顶部指针进行操作即可：
```cpp
void NumStackInput(NumStack *p, dfloat num)
{
    p->data_s[p->top] = num; //存入栈中
    p->top++;                //栈顶指针加1
}

dfloat NumStackOutput(NumStack *p)
{
    dfloat num; //dfloat变量类型已定义为结构体
    if (p->top != p->bottom)//栈非空
    {                                
        num = p->data_s[p->top - 1]; //输出栈顶内容 
        p->top--;                    //栈顶指针减1
        return num;
    }
    return 0; //栈空
}
```
4. 堆栈倒置
堆栈有时需要将整体进行倒置，顶部元素放置底部，而底部放回顶部，实现倒置只需要逐个将堆栈元素出栈再反向入栈即可：
```cpp
void NumStackConvert(NumStack *p)
{
    int pointer = 0;
    int length = p->top - p->bottom;
    dfloat num_tmp[MAX];
    int i;
    for (i = 0; i < length; i++)
    {
        num_tmp[pointer++] = NumStackOutput(p);
    }
    pointer = 0;
    for (i = 0; i < length; i++)
    {
        NumStackInput(p, num_tmp[pointer]);
        pointer++;
    }
}
```

### 1.读字符串——按键输入转为字符串输入
在按键模块的处理中，我们读取了每次按键的值，并对按键情况进行判断：

若输入为退格，则清除数组最末位的字符，同时数组指针减1（若此时指针指向0，即之前没有任何字符输入，则改为发出声光警报）；

若输入为清屏，则清除数组存储所有值，指针指向初始值；

若输入为模式键，则进入模式选择状态机，可进行不同模式的选择；

若输入为等于号，则将当前字符串数组传入cal_algorithm函数中进行计算处理，同时进行状态机转换。

其余输入，如数字、运算符、小数点等，则按照顺序存储至字符串数组input_char中，等待输入等于号后进行字符串计算。

其全过程见cal_algorithm子函数，其中词法分析、语法分析、表达式求解在后续调用子函数中得以体现，详见2、3、4部分：

```cpp
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

    while (i < length_p) { //表达式未读取完成
        if (p[i] == '.') {
            if (dot_occupied != 0) { //已存在小数点
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar error
            }
            N_O = N_O_num;
            dot_occupied = 1; //小数点标志，此时如果最后一位不是数字，则自动填充0
        } else if (p[i] == sqrt_sign) {
            if (sqrt_flag_cnt == num_stack->top + 1) { //sqrt标志位满
                // grammar_error_alarm();
                state_cal = 1;
                return 1; // grammar error
            }
            if (N_O == N_O_operator) {
                sqrt_flag_cnt = num_stack->top;
            } else {
                operatorinstack(num_stack, operator_stack, '*'); //自动补乘号
                sqrt_flag_cnt = num_stack->top;
            }
            sqrt_flag[sqrt_flag_cnt] = 1;
            N_O = N_O_operator;
        } else if (p[i] <= '9' && p[i] >= '0') { //数字
            if (N_O == N_O_operator) { //前一个字符是运算符，数字栈开拓新位
                dot_occupied = 0; //小数点标志清零
                dot_cnt = 0;
                NumStackInput(num_stack, 0); //数字栈自动补0垫位
            }
            if (i == 0 || p[i - 1] == '+' || p[i - 1] == '-' ||
                p[i - 1] == '*' || p[i - 1] == divide_sign ||
                p[i - 1] == '^' ) { //数字为首位或前一位为运算符
                num_stack_depth++;
            }
            if (dot_occupied != 0) {
                dot_cnt++;
            }
            numinstack(p[i], num_stack, dot_cnt);
            N_O = N_O_num; //N_O标志切换为数字
        } else { //双目运算符
            if (num_stack_depth == 0 || p[i - 1] == '+' || p[i - 1] == '-' ||
                p[i - 1] == '*' || p[i - 1] == divide_sign ||
                p[i - 1] == '^' /*p[i-1] is operator*/) { //未输入数字或前一位为运算符
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
    if (N_O == N_O_operator) { //最后一位为运算符
        // grammar_error_alarm();
        state_cal = 1;
        return 1; // grammar error
    } else {
        sqrt_cal(num_stack, sqrt_flag); //对sqrt标志位指向数字开方处理
        StackConvert(num_stack, operator_stack); //转为后缀表达式计算处理
        while (operator_stack->top != 0) { //符号栈未空
            stack_calculation(num_stack, operator_stack); //栈运算
        }
        final_answer = NumStackOutput(num_stack); //数字栈最后一位结果输出
        return 0;
    }
}
```

### 2.词法分析——字符串元素读取及错误处理
1. 小数点：

在一个数字中，小数点能且仅能最多出现一次，且小数点影响后续数字入栈合并时大小的体现（在小数点出现前，后续数字以整数形式与前数字的十倍相加；在小数点出现后，后续数字只能以当前小数位最低位值加入，如545=500+40+5，5.45=5+0.4+0.05），实际操作中可以对小数点当前位进行标记，在入栈时先化为整数，数字顺利加入时再将小数点归位，如5.45的输入：

5->.->4（(5*10+4)/10=5.4）->5（(5.4*10*10+5)/10/10）->5.45

代码具体实现过程如下：
```cpp
    if (p[i] == '.') {
        if (dot_occupied != 0) { //已存在小数点
            // grammar_error_alarm();
            state_cal = 1;
            return 1; // grammar error
        }
        N_O = N_O_num;
        dot_occupied = 1; //小数点标志，此时如果最后一位不是数字，则自动填充0
    }
```

2. 退格

退格的读取：每当系统检测到输入字符为退格时，将自动抹除最末尾值，并根据前面的输入情况调整N/O标记（最后输入为数字或操作符，用以判断是否出现语法错误）。注意为防止退格时，指针指向的位置为负数导致操作越界系统崩溃，需要在输入指针指向0时进行限位提示，同时不执行操作；

    ```cpp
   if (key_num == back_sign) {
        if (cnt_tab > 0) {
            cnt_tab--;
            length_input--;
            input_char[cnt_tab] = ' ';
        } else {
           beep_long();
        }
   }
    ```
3. 数字

数字在输入时，需要检测前一位标志，如果前一位为运算符，则此时需要为数字栈开拓一个新位存放新数字；若前一位为数字，则需要传入numinstack函数，对应修改当前数字栈存放的数字。

```cpp
if (p[i] <= '9' && p[i] >= '0') { //数字
            if (N_O == N_O_operator) { //前一个字符是运算符，数字栈开拓新位
                dot_occupied = 0; //小数点标志清零
                dot_cnt = 0;
                NumStackInput(num_stack, 0); //数字栈自动补0垫位
            }
            if (i == 0 || p[i - 1] == '+' || p[i - 1] == '-' ||
                p[i - 1] == '*' || p[i - 1] == divide_sign ||
                p[i - 1] == '^' ) { //数字为首位或前一位为运算符
                num_stack_depth++;
            }
            if (dot_occupied != 0) {
                dot_cnt++;
            }
            numinstack(p[i], num_stack, dot_cnt);
            N_O = N_O_num; //N_O标志切换为数字
        }
```

其中numinstack函数定义如下：

```cpp
int numinstack(uint num, NumStack *p, uint dot_occupied) {
    //数字入栈词法分析函数
    int i;
    dfloat num_ans, num_pre;
    num = num - 48; //将ASCII码转换为数字
    num_pre = NumStackOutput(p);
    if (dot_occupied == 0) {
        num_ans = d_add_df(d_mul_df(num_pre, 10), (float)num); //输入数字填入个位，原数字乘以10
    } else {
        num_ans = num_pre;
        for (i = 0; i < dot_occupied; i++) {
            num_ans = d_mul_df(num_ans, 10); //原数字循环乘10至个位空
        }
        num_ans = d_add_df(num_ans, (float)num); //输入数字填入个位
        for (i = 0; i < dot_occupied; i++) {
            num_ans = d_div_df(num_ans, 10); //数字小数点复位
        }
    }
    NumStackInput_dfloat(p, num_ans);
    return 0;
}
```
4. 单目运算符

此处设定开方为单目运算符，仅对其后第一个数字进行开方处理，故在处理输入字符串时，先提取根号出现的位置，再在sqrt_cal函数中逐个对标志位进行求开方：

    ```cpp
    int sqrt_cal(NumStack *n, int *sqrt_flag) { 
    //对sqrt标志位指向数字开方处理 
        int i = 0, f_high_tmp_int;
        float f_high_tmp;
        for (i = 0; i < n->top; i++) {
            if (sqrt_flag[i] == 1) {
                n->data_s[i].f_high = sqrt(n->data_s[i].f_high);
                f_high_tmp = 10000 * n->data_s[i].f_high; //计算结果高位
                f_high_tmp_int = (int)f_high_tmp;
                n->data_s[i].f_mid = f_high_tmp - f_high_tmp_int; //计算结果中位
            }
        }
        return 0;
   }
   ```

事实上在系统中，可通过令乘幂指数为0.5实现开方操作。此处单独定义了开方操作为单目运算符，主要是为了体现系统的可拓展性，如此可基于系统拓展sin，cos，log等单目运算操作，体现系统的可拓展性。此处由于时间问题未能进一步拓展，仅实现了开方操作，系统可进一步开发完善科学计算功能。

5. 双目运算符（优先级）

在每次检测到双目运算符时，系统将会把运算符入栈处理，同时将N/O标记修改为O。

需要注意的是，在语法分析过程中，若检测到N/O标记为O的情况下仍然输入了一个运算符，或输入完毕时N/O标记为O，此时将判定为语法错误，退出程序并进入错误显示状态机。

双目运算符具有优先级，优先级判断如下：^（乘幂）>*, />+, -。

```cpp
uint priority_operator(uchar operator_char) {
    //优先级判断：^大于*/大于+-
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
```
### 3.语法分析——堆栈的运算规则

在经过前一步的处理后，我们得到了一个浮点数堆栈与双目运算符结构体，此时由系统错误处理，可以保证此时输入的数字堆栈长度为双目运算符长度加一。

下面将介绍运算式的表达方式，以展示算法对于运算式的语法分析。

#### 运算式的前序、中序、后序表达

对于算术表达式，其存在前序、中序及后序表达形式（也可称为前缀、中缀、后缀表达式），其概念如下：

前序表达式（波兰表示法）：

前序表达式的特点是操作符置于操作数前面。对于二元运算符，语法上不需要括号即能被无歧义地解释，不需要括号改变优先级。

中序表达式：

中序表达式即我们日常使用的表达式，作为计算器的标准输入模式，其可从左往右阅读且结构清晰，但是需要括号改变优先级，对计算机不友好。

后序表达式（逆波兰表示法）

后序表达式所有的操作符置于操作数后面，因此也被称为后缀表示法。逆波兰表示法不需要括号标识操作符的优先级。

将算术表达式按照运算顺序列写为树，可以注意到前序表达式、中序表达式、后序表达式分别对应树的前序遍历、中序遍历、后序遍历：

图

#### 中序运算式转换实现算法
由于数字栈为LIFO特性，读取数字栈实际上是从右至左的。StackConvert函数在实现数字出栈重排顺序为从左向右同时，可基于优先级排序，将表达式同时改写为后缀表达式。此处在判断符号优先级更高时，已将后缀表达式的较前值进行了求解处理，包含了后缀表达式求值的一部分。
```cpp
void StackConvert(NumStack *n, OpeStack *o) {
    //语法分析函数
    dfloat num_tmp;
    char ope_tmp;
    //建立符号、数字临时堆栈
    NumStack *ns_tmp;
    OpeStack *os_tmp;
    ns_tmp = NumStackCreate();
    os_tmp = OpeStackCreate();
    while (n->top != n->bottom) //数字栈非空
    {
        num_tmp = NumStackOutput(n);
        NumStackInput_dfloat(ns_tmp, num_tmp);
        if (o->top == o->bottom) {
            break;
        }
        ope_tmp = OpeStackOutput(o);
        while (os_tmp->top != os_tmp->bottom && //符号栈非空
                priority_operator(ope_tmp) < priority_operator(os_tmp->data_s[os_tmp->top - 1])) { //当前符号优先级小于等于符号栈顶
            stack_calculation(ns_tmp, os_tmp); //根据优先级计算
        }
        OpeStackInput(os_tmp, ope_tmp);
    }
    NumStackCopy(n, ns_tmp); // n = ns_tmp;
    OpeStackCopy(o, os_tmp); // o = os_tmp;
}
```

### 4.后缀表达式求解

在步骤3中的后缀表达式中，排在最后方的必然优先级最高，因此处理中已对出现的更高优先级二元操作符进行了调用函数stack_calculation进行处理：
```cpp
int stack_calculation(NumStack *n, OpeStack *o) {
    //数字栈顶两个数字、符号栈顶一个符号进行运算，并将结果入栈
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
                2; //在精度为1e-8条件下判断除数是否为0，为0输出计算数学错误
            return -1;
        }
        n_ans = d_div_dd(n1, n2);
        break;
    case '^':
        if (fabs(n2.f_high) < 1e-8 && fabs(n1.f_high) < 1e-8) {
            state_cal =
                2; //在精度为1e-8条件下判断幂底与幂指数是否为0或负数，为0输出计算数学错误
            return -1;
        }
        n_ans = d_pow_df(n1, n2.f_high);
        break;
    default:
        break;
    }
    NumStackInput_dfloat(n, n_ans);
}
```
此时后缀表达式的求解，仅剩下同等优先级从左向右的顺序计算部分，此时因数字栈与符号栈均已倒置，可逐个出栈运算：
```cpp
while (operator_stack->top != 0) { //符号栈未空
    stack_calculation(num_stack, operator_stack); //栈运算
}
final_answer = NumStackOutput(num_stack); //数字栈最后一位结果输出
return 0;
```

### 5.数字精度拓展

对于8位单片机C语言C51而言，其支持数据类型仅为char, int, long, float，最大长度为float与long的四字节。浮点数只能以最高8位（10进制）的形式存储，实际运算精度一般只有7位：

为了实现单片机的拓展功能，以空间换取12位精度，系统需要手动创建数据类型，用以存储更高精度的数字。此处将使用数据结构链表进行处理：

#### 精度拓展：链表结构
流程图：

#### 运算重载

### 6.数字转换为字符串输出

在得到了float型浮点数后，程序需要将浮点数转换为字符串进行输出。系统最开始通过逐位乘10读取各位整数，但在后来的开发中发现精度较低，因此改用了sprintf进行数字转字符串的操作。
```cpp
void ldouble2str(ldouble f, uchar *s) {
    long int n_int = 0;
    int bits_10;
    n_int = (long int)f;
    if (n_int == 0) {
        bits_10 = 1;
    } else {
        bits_10 = log10(abs(n_int)) + 1; //计算整数位数
    }
    if (f < 0) { //读取负号
        *s = '-';
        s += 1;
        f = -f;
    } else {
        *s = ' ';
        s += 1;
    }
    switch (bits_10) { //根据整数位数设置小数精度
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
    default: //读取错误
        state_cal = 3;
        break;
    }
}
```
## 进制转换模式

### 进制数转换结构体

程序员模式下，系统需要对输入的数字进行多进制转换。为实现通用的进制转换功能，系统定义了结构体存储输入的数字，以及该数字对应的二进制、八进制、十进制及十六进制的字符串形式。

图
```cpp
typedef struct {
    uint number;
    uchar bin[16];
    uchar oct[10];
    uchar dec[10];
    uchar hex[4];
} num_type;
```
结构体可进行的操作如下所述：
结构体初始化：
```cpp
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
```
数字输入：
```cpp
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
    if (num->number > 65535) {
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
```
其中itoa函数为c++的函数库下的数字-字符串转换函数，此处由于不存在对应库函数，需要单独定义：
```cpp
char *itoa(int num, char *buffer, int base) {
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
```
定义了该数制转换结构体后，我们可以很方便地读取输入字符串对应整数值，通过num_input函数输入结构体，即可直接读取结构体的字符串输出：
```cpp

if (key_num == '=') {
        for (i = 0; i < 16; i++) {
            ans_display[i] = input_char[i];
        }
        for (i = 4; i < cnt_tab; i++) {
            ans_dis[i - 4] = input_char[i];
        }
        num_input(num_struct, mode_trans_in, mode_trans_out,
                  ans_dis);
        if (state_cal == 0) {
            if (num_struct->number == 0) { //输入数字为0，则对应数位数均为1
                bits_bin = 1;
                bits_oct = 1;
                bits_dec = 1;
                bits_hex = 1;
            } else { //计算整数位数：
                     //使用log10函数可以计算10进制位数，换底即可得到其他进制对应位数
                bits_bin = (int)(log10(abs(num_struct->number)) /
                                 log10(2)) + 1;
                bits_oct = (int)(log10(abs(num_struct->number)) /
                                 log10(8)) + 1;
                bits_dec = log10(abs(num_struct->number)) + 1;
                bits_hex = (int)(log10(abs(num_struct->number)) /
                                 log10(16)) + 1;
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
```

## 计算器状态机
计算器的实现了多模式功能，为此系统将设置状态机对计算器的当前状态进行判断转换：

图

变量state_now与state_next存储了当前状态与即将转换的状态，每次状态机段的代码执行完后，状态机会检测是否满足状态转换条件，并将状态state_next设定为下一步状态，在当前状态执行完后将state_next赋给state_now进入下一轮循环，函数体结构大致如下：
```cpp
while (1) {
        switch (state_now) {
        case s_0: //普通计算输入模式
            //......
            break;
        case s_1: //普通计算结果显示模式
            //......
            break;
        case s_2: //错误输出模式
            //......
            break;
        case s_3: // shift输入模式
            break;
        //case ......
        }
        state_now = state_next;
    }
```
1. 计算模式状态

2. 答案输出状态

3. 错误状态

4. shift按键




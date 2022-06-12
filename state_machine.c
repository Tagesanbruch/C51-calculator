
switch (state_now)
        {
        case s_0: //普通计算输入模式
            if (I_A == 0)
            {
                chrt_disp_first(input_char);
                // cgram_wr(0x00, 0x00);
                // cgram_disp();
                // clear_ans();
                ans_dis[16] = "                ";
                ans_dis_high[16] = "                ";
                ans_dis_mid[16] = "                ";
                ans_dis_low[16] = "                ";
                ans_display[32] = "                                ";      
                final_answer.f_high = 0;
                final_answer.f_mid = 0;
                final_answer.f_low = 0;
            }
            else
            {
                chrt_disp(ans_display);
                // cgram_wr(0x00, 0x00);
                // cgram_disp();
                // beep_short();
            }
            key_num = key_decode();
            if (key_num != 20 && key_num != '=' && key_num != 't' && key_num != back_sign)
            {
                if (cnt_tab >= 16)
                {
                    beep_long();
                    // continue;
                }
                else
                {
                    input_char[cnt_tab] = key_num;
                    cnt_tab++;
                    length_input++;
                    // beep_short();
                }
            }
            else if (key_num == back_sign){
                if(cnt_tab > 0){
                    cnt_tab--;
                    length_input--;
                    input_char[cnt_tab] = ' ';
                }
                else{
                    beep_long();
                }                
            }
            else if (key_num == 't'){
                state_last = s_1;
                clear_data();
            }
            else if (key_num == '=')
            {
                ans = cal_algorithm(input_char, length_input);
                if (state_cal == 0)
                {
                    for (i = 0; i < 16; i++)
                    {
                        ans_display[i] = input_char[i];
                    }
                    ldouble2str(final_answer.f_high, ans_dis_high);
                    ldouble2str(final_answer.f_mid, ans_dis_mid);
                    ldouble2str(final_answer.f_low, ans_dis_low);
                    for (i = 18; i < 25; i++)
                    {
                        ans_display[i] = ans_dis_high[i - 18];
                    }
                    for (i = 25; i < 29; i++)
                    {
                        ans_display[i] = ans_dis_mid[i - 25 + 3];
                    }
                    for (i = 29; i < 32; i++)
                    {
                        ans_display[i] = ans_dis_low[i - 29 + 3];
                    }
//                    beep_short();
                }
                else if (state_cal == 1)
                {
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
                }
                else if (state_cal == 2)
                {
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
                I_A = 1;
            }
            break;
        case s_1: //进制转换输入模式
            if (!_is_tr_ini) {
                Transform_Initial();
                _is_tr_ini = 1;
                }
            if (I_A == 0)
            {
                chrt_disp_first(input_char, cnt_tab);
                cgram_wr(0x00, 0x00);
                // cgram_disp();
            }
            else
            {
                chrt_disp(ans_display);
                cgram_wr(0x00, 0x00);
                // cgram_disp();
            }
            key_num = key_decode();
            if (key_num == 't'){
                state_last = s_0;
                clear_data();
            }
            else if (key_num <= '9' && key_num >= '0')
            {
                if (cnt_tab >= 16)
                {
                    beep_long();
                    continue;
                }
                else
                {
                    input_char[cnt_tab] = key_num;
                    cnt_tab++;
                    length_input++;
                    // beep_short();
                }
            }
            else if (key_num == '=')
            {
                //ans = oct_trans();
                
                for (i = 0; i < 16; i++)
                {
                    ans_display[i] = input_char[i];
                }
                for(i = 4; i < cnt_tab; i++)
                {
                    ans_dis[i - 4] = input_char[i];
                }
                num_input(num_struct, mode_trans_in, mode_trans_out, ans_dis);
				if (state_cal == 0)
                {
                    if (num_struct->number == 0){
                        bits_bin = 1;
                        bits_oct = 1;
                        bits_dec = 1;
                        bits_hex = 1;
                    }
                    else {
                        bits_bin = (int) (log10(abs(num_struct->number)) / log10(2))+1;
                        bits_oct = (int) (log10(abs(num_struct->number)) / log10(8))+1;
                        bits_dec = log10(abs(num_struct->number))+1;
                        bits_hex = (int) (log10(abs(num_struct->number)) / log10(16))+1;
                    }
                    
                    switch (mode_trans_out)
                    {
                    case sc_bin:
                        for (i = 32 - bits_bin; i < 32; i++)
                        {
                            ans_display[i] = num_struct->bin[i - 32 + bits_bin];
                        }
                        break;
                    case sc_oct:
                        for (i = 32 - bits_oct; i < 32; i++)
                        {
                            ans_display[i] = num_struct->oct[i - 32 + bits_oct];
                        }
                        break;
                    case sc_dec:
                        for (i = 32 - bits_dec; i < 32; i++)
                        {
                            ans_display[i] = num_struct->dec[i - 32 + bits_dec];
                        }
                        break;
                    case sc_hex:
                        for (i = 32 - bits_hex; i < 32; i++)
                        {
                            ans_display[i] = num_struct->hex[i - 32 + bits_hex];
                        }
                        break;
                    default:
                        break;
                    }
                    I_A = 1;
                    beep_short();
                }
                else if (state_cal == 3){
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
        state_now = state_last;
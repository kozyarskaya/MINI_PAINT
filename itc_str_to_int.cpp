#include"mini_paint.h"

long long itc_str_to_int(string str){

    long long number = 0, i = 0;
    int ch = 0;
    bool zn = false;
    if(str[0] == '-'){
        zn = true;
        str = itc_slice_str(str, 1, itc_len(str) - 1);
    }
    while(str[i] != '\0'){
        ch = str[i] - 48;
        number = number * 10 + ch;
        i ++;
    }
    if(zn)
        number *= -1;
    return number;
}

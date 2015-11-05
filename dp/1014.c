/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 1014.c
 * @author liuzhaocheng(com@baidu.com)
 * @date 2015/11/05 10:12:30
 * @brief 
 *  
 **/

#include <stdio.h>

#define MAXIMUM_NUM 20000

int N[7];
int pack[120001];

int sum_values() {
    int sum = 0;
    int i = 1;
    for(; i <= 6; i++)
        sum += N[i]*i;
    return sum;
}

int pack01(int lens, int new_value) {
    //printf("%d\n", new_value);
    int i = lens;
    for (; i >= 0; i--) {
        if ((i >= new_value) && (pack[i - new_value] != -1) && (pack[i - new_value] + new_value > pack[i])) {
            pack[i] = pack[i - new_value] + new_value;
            //printf("%d %d %d %d\n", i, new_value, pack[i - new_value], pack[i]);
        }
    }
    if (pack[lens] != -1)
        return 1;
    else
        return 0;
}

int main() {
    int index = 0;
    while(1) {
        scanf("%d %d %d %d %d %d", N+1, N+2, N+3, N+4, N+5, N+6);
        if (!(N[1] | N[2] | N[3] | N[4] | N[5] | N[6]))
            break;
        index++;
        int sum = sum_values();
        if (sum%2) {
            printf("Collection #%d:\nCan't be divided.\n", index);
            printf("\n");
            continue;
        }
        int lens = sum/2;
        int i = 1;
        int flag = 0;
        pack[0] = 0;
        for (; i <= lens; i++) {
            pack[i] = -1;
        }
        i = 1;
        for (; i <= 6; i++) {
            int cur_num = N[i];
            int binary_num = 1;
            while(binary_num < cur_num) {
                int new_value = binary_num * i;
                cur_num -= binary_num;
                flag = pack01(lens, new_value);
                binary_num *= 2;
            } 
            if (flag)
                break;
            flag = pack01(lens, cur_num * i);
        } 
        if (flag)
            printf("Collection #%d:\nCan be divided.\n", index);
        else
            printf("Collection #%d:\nCan't be divided.\n", index);
        printf("\n");
    }
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

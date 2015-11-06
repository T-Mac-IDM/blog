/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 3260.c
 * @author liuzhaocheng(com@baidu.com)
 * @date 2015/11/05 15:11:47
 * @brief 
 *  
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int v[101];
int c[101];
int pack[24521];
int cpack[24521];
int N = 0;
int target = 0;

//get the gross of his money
int sum_all_coins() {
    int i = 0;
    int max = 0;
    for (; i < N; i++)
        if (v[i] > max)
            max = v[i];
    return max * (max + 1) + target; 
}

void init_pack(int *pack, int lens) {
    int i = 1;
    pack[0] = 0;
    for (; i <= lens; i++)
        pack[i] = MAX;
}

void pack01(int lens, int new_value, int binary_num) {
    int i = lens;
    for (; i >= 0; i--)
        if (i >= new_value && pack[i - new_value] + binary_num < pack[i])
            pack[i] = pack[i - new_value] + binary_num;
}

int complete_pack(int new_lens) {
    int i = 0;
    int j = 0;
    init_pack(cpack, new_lens);
    for (; i < N; i++) {
        for (j = 0; j <= new_lens; j++) {
            if (j >= v[i] && cpack[j - v[i]] + 1 < cpack[j]) {
                cpack[j] = cpack[j - v[i]] + 1;
            }
        }
    }
    int res = cpack[new_lens];
    return res;
}

int update_cmin(cmin, cur_min) {
    if (cur_min < cmin)
        cmin = cur_min;
    return cmin;
}

int main() {
    while(scanf("%d %d", &N, &target) != EOF) {
        int i = 0;
        for (; i < N; i++)
            scanf("%d", v+i);
        i = 0;
        for (; i < N; i++)
            scanf("%d", c+i);
        int lens = sum_all_coins();
        init_pack(pack, lens + 1);
        i = 0;
        for (; i < N; i++) {
            int cur_num = c[i];
            int binary_num = 1;
            int new_value = 0;
            while (binary_num < cur_num) {
                cur_num -= binary_num;
                new_value = binary_num * v[i];
                pack01(lens, new_value, binary_num);
                binary_num *= 2;
            } 
            pack01(lens, cur_num * v[i], cur_num);
        }
        i = target;
        int cmin = MAX;
        for (; i <= lens; i++)
            if (pack[i] != MAX && pack[i] < cmin) {
                int new_lens = i - target;
                if (!new_lens) {
                    cmin = update_cmin(cmin, pack[i]); 
                    continue;
                }
                int tmp = complete_pack(new_lens);
                cmin = update_cmin(cmin, tmp + pack[i]); 
            }
        if (cmin > (MAX - 1))
            printf("-1\n");
        else
            printf("%d\n", cmin);
    }

}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

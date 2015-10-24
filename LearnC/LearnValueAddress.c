/*
NTU ComputeThink course
151023 Value and Address
*/

#include <stdio.h>

int main(){
    char c_0[10] = {"ARTHUR"};
    char c_1[5], c_2[20];
    int i, j, k;
    float abc;

    printf("c_0 -> %s address of c_0 -> %d\n", c_0, &c_0);
    printf("c_1 -> %s address of c_1 -> %d\n", c_1, &c_1);
    printf("c_2 -> %s address of c_2 -> %d\n", c_2, &c_2);
    printf("i   -> %d address of i   -> %d\n", i, &i);
    printf("j   -> %d address of j   -> %d\n", j, &j);
    printf("k   -> %d address of k   -> %d\n", k, &k);
    printf("abc -> %f address of abc -> %d\n", abc, &abc);    

    // The code below produce error during compiling
    //printf("c_0 %d\n", &c_0 - &abc);
    //printf("c_1 %d\n", &c_1 - &abc);
    //printf("c_2 %d\n", &c_2 - &abc);
    //printf("i   %d\n", &i - &abc);
    //printf("j   %d\n", &j - &abc);
    //printf("k   %d\n", &k - &abc);
    //printf("abc %d\n", abc, &abc - &abc);    

    return 0;
}

/* Structure Tutorial

Tutorial Link
https://www.youtube.com/watch?v=rI88W3yu8Qw
*/

#include <stdio.h>

typedef struct complexNumber {
    int real;
    int complex;
}complex;

struct complexNumber addComplexNumber1(complex c1, complex c2){
    struct complexNumber temp;
    temp.real = c1.real + c2.real;
    temp.complex = c1.complex + c2.complex;
    return temp;
}

complex addComplexNumber2(complex *c1, complex *c2){
    complex temp;
    temp.real = (*c1).real + (*c2).real;
    temp.complex = c1->complex + c2->complex;
    return temp;
}

complex* addComplexNumber3(complex *c1, complex *c2){
    complex temp;
    temp.real = c1->real + c2->real;
    temp.complex = c1->complex + c2->complex;
    return &temp;
} // This function creates a warning

int main(){
    complex c1 = {1, 5}, c2 = {2, 6};
    printf("sum of complex number is %d + i%d\n",
	   addComplexNumber1(c1, c2).real,
	   addComplexNumber1(c1, c2).complex);
    printf("sum of complex number is %d + i%d\n",
	   addComplexNumber2(&c1, &c2).real,
	   addComplexNumber2(&c1, &c2).complex);
    printf("sum of complex number is %d + i%d\n",
	   addComplexNumber3(&c1, &c2)->real,
	   addComplexNumber3(&c1, &c2)->complex);

    return 0;
}

/*
The first one spends a lot of memory.

The second one is good.

The third one is not recommended, since the function return
the pointer of a local variable.
*/

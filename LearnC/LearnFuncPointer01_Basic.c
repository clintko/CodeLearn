/* C Programming: Function Pointer Tutorial

Tutorial Link:
https://www.youtube.com/watch?v=KVv-TWzl_Io
*/

#include <stdio.h>
#include <stdlib.h>

static void goodbye(){
    printf("\nPress ENTER to exit: ");
    fflush(stdin);
    getchar();
}

static int add(int a, int b){
    return a + b;
}

static int subtract(int x, int y){
    return x - y;
}

int main(){
    //char *term = getenv("TERM");
    //if (term != NULL && !strcmp(term,"emacs")==0) {
    //    setvbuf(stdout, NULL, _IONBF, 0);
    //}
    
    int x, y;
    int result;
    int do_add; /* boolean - add or subtract */

    // function pointer
    int (*func_ptr)(int, int);
    
    atexit(goodbye);

    printf("Please enter the first number: ");
    scanf("%d", &x);
    printf("Please enter the second number: ");
    scanf("%d", &y);

    printf("Would you like to add or subtract (a/s)? ");
    fflush(stdin);

    if (getchar() == 'a'){
	func_ptr = add;
    } else {
	func_ptr = subtract;
    }

    result = func_ptr(x, y);

    printf("The result is %d\n", result);

    return 0;
    
}

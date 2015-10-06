/**/
#include <stdio.h>
#include <stdlib.h>
#include "LearnStructFuncPtr02_fig.h"

int main(){

    fig_gun01 = pic_2dto1d(4, 20, pic_gun01);
    pic_print(fig_gun01, 4, 20);

    free(fig_gun01);
    

    
    return 0;
}

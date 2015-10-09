/**/
#include <stdio.h>
#include <stdlib.h>
//#include "LearnStructFuncPtr01_point.h"
#include "LearnStructFuncPtr02_fig.h"

int main(){

    Fig* gun01 = Fig_init(10, 20, 4, 20, 2);
    gun01->pic[0] = fig_2dto1d(4, 20, pic_gun01);
    gun01->pic[1] = fig_2dto1d(4, 20, pic_gun02);
    
    printf("\nAfter Initialization\n");
    gun01->print(gun01);
    gun01->frame_cur += 1;
    gun01->print(gun01);
    
    
    printf("\nCheck getter function and set function of struct Fig\n");
    printf("The current size of figure\nHeight: %d\nWidth: %d\n",
	   gun01->getHeight(gun01), gun01->getWidth(gun01));

    printf("The current position of figure\nx: %d\ny: %d\n",
	   gun01->getX(gun01), gun01->getY(gun01));

    printf("\nCurrent Location\n");
    gun01->pos->print(gun01->pos);

    printf("After Move Down\n");
    gun01->moveDown(gun01);
    gun01->pos->print(gun01->pos);

    printf("Test Check\n");
    printf("Initialize a point\n");
    
    Point* pixel = Point_init(10, 20);
    pixel->print(pixel);

    if (gun01->check(gun01, pixel)){
	printf("Point in Figure\n");
    } else {
	printf("Point not in Figure\n");
    } // end if-else
    printf("\n");
    
    printf("Move Down the point\n");
    pixel->moveDown(pixel);
    pixel->print(pixel);

    if (gun01->check(gun01, pixel)){
	printf("Point in Figure\n");
    } else {
	printf("Point not in Figure\n");
    } // end if-else
    printf("\n");

    printf("Move Down the point\n");
    pixel->moveDown(pixel);
    pixel->print(pixel);

    if (gun01->check(gun01, pixel)){
	printf("Point in Figure\n");
    } else {
	printf("Point not in Figure\n");
    } // end if-else
    printf("\n");

    
    free(gun01->pos);
    free(gun01->pic);
    free(gun01);
    free(pixel);
    

    
    return 0;
}

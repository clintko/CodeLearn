#include <stdio.h>
#include <stdlib.h>
#include "LearnStructFuncPtr01_point.h"


int main(){
    // initialize Pixel
    // Pixel point;
    //point.x = 10;
    //point.y = 20;
    //point.print = Pixel_print;
    
    // initialize using a function
    //Pixel point = Pixel_init(10, 20);
    //Pixel_print(&point);
    //point.print(&point);

    //Pixel point = Pixel_init(10, 20);
    //Pixel* point_ptr = &point;
    //point_ptr->print(point_ptr);

    Pixel* point = Pixel_init(10, 20);
    point->print(point);

    free(point);
    return 0;
}

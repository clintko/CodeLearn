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

    Point* pixel = Point_init(10, 20);
    printf("Initialization\n");
    pixel->print(pixel);

    printf("Set the point to (5, 10)\n");
    pixel->set(pixel, 5, 10);
    pixel->print(pixel);

    printf("Reset the point\n");
    pixel->reset(pixel);
    pixel->print(pixel);

    printf("Move Left by one\n");
    pixel->moveLeft(pixel);
    pixel->print(pixel);

    printf("Move Rigth by one\n");
    pixel->moveRight(pixel);
    pixel->print(pixel);

    printf("Move Up by one\n");
    pixel->moveUp(pixel);
    pixel->print(pixel);

    printf("Move Down by one\n");
    pixel->moveDown(pixel);
    pixel->print(pixel);
    
    pixel->set(pixel, 123, 456);
    printf("The current point\nx: %d\ny: %d\n",
	   pixel->getX(pixel), pixel->getY(pixel));

    // free the memory
    free(pixel);
    return 0;
}

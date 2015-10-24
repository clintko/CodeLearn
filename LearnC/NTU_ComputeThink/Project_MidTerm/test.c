/* NTU_ComputeThink MidTerm Porject 
Testing functions

Desc:
    Test each module to check if any module produce error
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Point.h"
#include "Fig.h"


void testStructPoint(){
    printf("Test the structure Point\n");
    printf("==========================================\n");
    // ------------------------------------------
    printf("Initialize a Point\n");
    Point* pixel = Point_init(20, 25);

    // -------------------------------------------
    printf("Check Getter Method\n");
    if (pixel->getX(pixel) == 20){
	printf("    test11: getX; Passed\n");	
    } else {
	printf("    test11: getX; Failed\n");
    } // end if-else

    if (pixel->getY(pixel) == 25){
	printf("    test12: getY; Passed\n");
    }else{
	printf("    test12: getY; Failed\n");
    } // end if-else

    // --------------------------------------------
    printf("Check Setter Method\n");
    pixel->setX(pixel, 50);
    if (pixel->getX(pixel) == 50){
	printf("    test21: getX; Passed\n");	
    } else {
	printf("    test21: getX; Failed\n");
    } // end if-else

    pixel->setY(pixel, 100);
    if (pixel->getY(pixel) == 100){
	printf("    test22: getY; Passed\n");
    }else{
	printf("    test22: getY; Failed\n");
    } // end if-else

    // -----------------------------------------
    printf("Check Method reset\n");
    pixel->reset(pixel);
    if (pixel->getX(pixel) == 0 && pixel->getY(pixel) == 0){
	printf("    test31: reset; Passed\n");	
    } else {
	printf("    test31: reset; Failed\n");
    } // end if-else
    
    // -----------------------------------------
    printf("Check Method move\n");
    pixel->moveDown(pixel);
    if (pixel->getY(pixel) == 1){
	printf("    test41: moveDown; Passed\n");	
    } else {
	printf("    test41: moveDown; Failed\n");
    } // end if-else

    pixel->moveUp(pixel);
    pixel->moveUp(pixel);
    if (pixel->getY(pixel) == -1){
	printf("    test42: moveUp; Passed\n");
    }else{
	printf("    test42: moveUp; Failed\n");
    } // end if-else

    pixel->moveLeft(pixel);
    if (pixel->getX(pixel) == -1){
	printf("    test43: moveLeft; Passed\n");	
    } else {
	printf("    test43: moveLeft; Failed\n");
    } // end if-else

    pixel->moveRight(pixel);
    pixel->moveRight(pixel);
    if (pixel->getX(pixel) == 1){
	printf("    test44: moveRight; Passed\n");
    }else{
	printf("    test44: moveRight; Failed\n");
    } // end if-else
    
    // ------------------------------------------
    printf("Free the memory of Point\n");
    pixel->freePoint(pixel);
    printf("Finish testing structure Point\n");
    printf("==========================================\n\n");
}


char test_pic11[1][1] = {"A"};
char test_pic12[1][1] = {"B"};
char test_pic21[2][2] = {"AB", "CD"};
char test_pic22[2][2] = {"XY", "ZW"};

void testStructFig(){
    printf("Test the structure Fig\n");
    printf("==========================================\n");
    printf("Initialize a Fig\n");
    printf("Check Getter Method\n");
    printf("Check Setter Method\n");
    printf("Check Method move\n");
    printf("Check Method addPic\n");
    printf("Check Method Print\n");
    printf("Check Method nextPic\n");
    printf("Check Method isPointInFig\n");
    printf("Check Method check\n");
    printf("Free the memory of Fig\n");
    printf("Finish testing structure Fig\n");
    printf("==========================================\n");
}

int main(){
    testStructPoint();
    testStructFig();
    return 0;
}


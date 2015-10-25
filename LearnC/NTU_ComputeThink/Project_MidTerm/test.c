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
char test_pic21[2][3] = {"AB", "CD"};
char test_pic22[2][3] = {"XY", "ZW"};

void testStructFig(){
    printf("Test the structure Fig\n");
    printf("==========================================\n");
    printf("Initialize a Fig\n");
    Fig* fig01 = Fig_init(10, 20, 1, 1);
    Fig* fig02 = Fig_init( 5, 10, 2, 2);
    
    printf("Check Getter Method\n");
    
    if(fig01->getX(fig01) == 10){
	printf("    test11: getX; Passed\n");
    }else{
	printf("    test11: getX; Failed\n");
    } // end if-else

    if(fig01->getY(fig01) == 20){
	printf("    test12: getY; Passed\n");
    }else{
	printf("    test12: getY; Failed\n");
    } // end if-else

    // check getHeight and getWidth
    if (fig01->getHeight(fig01) == 1){
	printf("    test13: getHeight; Passed\n");
    } else {
	printf("    test13: getHeight; Failed\n");
    }

    if (fig02->getHeight(fig02) == 2){
	printf("    test14: getHeight; Passed\n");
    } else {
	printf("    test14: getHeight; Failed\n");
    }

    if (fig01->getWidth(fig01) == 1){
	printf("    test15: getWidth; Passed\n");
    } else {
	printf("    test15: getWidth; Failed\n");
    }

    if (fig02->getWidth(fig02) == 2){
	printf("    test16: getWidth; Passed\n");
    } else {
	printf("    test16: getWidth; Failed\n");
    }

    // check getFrameTot and getFrameCur
    if (fig01->getFrameTot(fig01) == 0){
	printf("    test17: getFrameTot; Passed\n");
    } else {
	printf("    test17: getFrameTot; Failed\n");
    }

    if (fig01->getFrameCur(fig01) == 0){
	printf("    test18: getFrameCur; Passed\n");
    } else {
	printf("    test18: getFrameCur; Failed\n");
    }
    
    // ------------------------------------------    
    printf("Check Setter Method\n");
    
    fig01->setX(fig01, 35);
    if(fig01->getX(fig01) == 35){
	printf("    test21: setX; Passed\n");
    }else{
	printf("    test21: setX; Failed\n");
    } // end if-else
    
    fig01->setY(fig01, 55);
    if(fig01->getY(fig01) == 55){
	printf("    test22: getY; Passed\n");
    }else{
	printf("    test22: getY; Failed\n");
    } // end if-else

    // -----------------------------------------
    printf("Check Method reset\n");
    fig01->reset(fig01);
    
    if((fig01->getX(fig01) == 0) && (fig01->getY(fig01) == 0)){
	printf("    test31: reset; Passed\n");
    }else{
	printf("    test31: reset; Failed\n");
    } // end if-else
    
    // ------------------------------------------
    printf("Check Method move\n");
    
    fig01->moveUp(fig01);
    if(fig01->getY(fig01) == -1){
	printf("    test41: moveUp; Passed\n");
    }else{
	printf("    test41: moveUp; Failed\n");
    } // end if-else
    
    fig01->moveDown(fig01);
    fig01->moveDown(fig01);
    if(fig01->getY(fig01) == 1){
	printf("    test42: moveDown; Passed\n");
    }else{
	printf("    test42: moveDown; Failed\n");
    } // end if-else
    
    fig01->moveLeft(fig01);
    if(fig01->getX(fig01) == -1){
	printf("    test43: moveLeft; Passed\n");
    }else{
	printf("    test43: moveLeft; Failed\n");
    } // end if-else
    
    fig01->moveRight(fig01);
    fig01->moveRight(fig01);
    if(fig01->getX(fig01) == 1){
	printf("    test44: moveRight; Passed\n");
    }else{
	printf("    test44: moveRight; Failed\n");
    } // end if-else

    // -----------------------------------------
    printf("Check Helper Function fig_2dto1d\n");
    
    // printf("%s\n", fig_2dto1d(1, 1, test_pic11));
    if((strcmpi(fig_2dto1d(1, 1, test_pic11), "A") == 0)){
	printf("    test51: fig_2dto1d; Passed\n");
    } else {
	printf("    test51: fig_2dto1d; Failed\n");
    } // end if-else

    //printf("%s\n", fig_2dto1d(1, 1, test_pic12));
    if((strcmpi(fig_2dto1d(1, 1, test_pic12), "B") == 0)){
	printf("    test52: fig_2dto1d; Passed\n");
    } else {
	printf("    test52: fig_2dto1d; Failed\n");
    } // end if-else

    //printf("%s\n", fig_2dto1d(2, 2, test_pic21));
    if((strcmpi(fig_2dto1d(2, 2, test_pic21), "ABCD") == 0)){
	printf("    test53: fig_2dto1d; Passed\n");
    } else {
	printf("    test53: fig_2dto1d; Failed\n");
    } // end if-else

    //printf("%s\n", fig_2dto1d(2, 2, test_pic22));
    if((strcmpi(fig_2dto1d(2, 2, test_pic22), "XYZW") == 0)){
	printf("    test54: fig_2dto1d; Passed\n");
    } else {
	printf("    test54: fig_2dto1d; Failed\n");
    } // end if-else
    // ------------------------------------------
    printf("Check Method addPic\n");

    // fig01 add test picture 11
    //original version: fig01->addPic(fig01, fig_2dto1d(1, 1, test_pic11));
    fig01->addPic(fig01,
		  fig01->getWidth(fig01),
		  fig01->getHeight(fig01),
		  test_pic11);
    if((fig01->getFrameTot(fig01) == 1) &&
       (strcmpi(fig01->pic[0], "A") == 0)){
	printf("    test61: addPic; Passed\n");
    } else {
	printf("    test61: addPic; Failed\n");
    } // end if-else

    // fig01 add test picture 12
    // original version: fig01->addPic(fig01, fig_2dto1d(1, 1, test_pic12));
    fig01->addPic(fig01,
		  fig01->getWidth(fig01),
		  fig01->getHeight(fig01),
		  test_pic12);
    if((fig01->getFrameTot(fig01) == 2) &&
       (strcmpi(fig01->pic[1], "B") == 0)){
	printf("    test62: addPic; Passed\n");
    } else {
	printf("    test62: addPic; Failed\n");
    } // end if-else
       
    // fig02 add test picture 21
    fig02->addPic(fig02,
		  fig02->getWidth(fig02),
		  fig02->getHeight(fig02),
		  test_pic21);
    if((fig02->getFrameTot(fig02) == 1) &&
       (strcmpi(fig02->pic[0], "ABCD") == 0)){
	printf("    test63: addPic; Passed\n");
    } else {
	printf("    test63: addPic; Failed\n");
    } // end if-else

    // fig02 add test picture 22
    fig02->addPic(fig02,
		  fig02->getWidth(fig02),
		  fig02->getHeight(fig02),
		  test_pic22);
    if((fig02->getFrameTot(fig02) == 2) &&
       (strcmpi(fig02->pic[1], "XYZW") == 0)){
	printf("    test64: addPic; Passed\n");
    } else {
	printf("    test64: addPic; Failed\n");
    } // end if-else
    
    // ------------------------------------------
    printf("Check Method get\n");
    
    // ------------------------------------------
    printf("Check Method Print\n");

    // ------------------------------------------
    printf("Check Method nextPic\n");

    // ------------------------------------------
    printf("Check Method isPointInFig\n");

    // ------------------------------------------
    printf("Check Method check\n");
    
    // ----------------------------------------------
    printf("Free the memory of Fig\n");
    fig01->freeFig(fig01);
    printf("Finish testing structure Fig\n");
    printf("==========================================\n");
}

int main(){
    testStructPoint();
    testStructFig();
    return 0;
}


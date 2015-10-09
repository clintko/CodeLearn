#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void copyStr(){}

int main(){
	/* 
	In the first section, I want to test whether pointer to be assigned to another pointer
    
    first, I found out that
    if I initialized without specified the size, the program failed as I print it out
        
		// not OK
   	    char* test;
   	    printf("test2: %s\n", test);
   	    
   	    // OK
   	    char test[SIZE];
   	    printf("test2: %s\n", test);
   	    
   	Second, I found out that if I have already specified the size of pointer, I could not assigned it by another pointer
   	    
   	    // not OK
   	    char test1[ncols];
	    char test2[ncols];
        
        test2 = test1;
        
        // OK
        char test1[ncols];
	    char* test2;
        
        test2 = test1;
	*/
	int nrows = 2;
	int ncols = 5;
	
	char test1[ncols];
	//char test2[ncols];
    char* test2;
	
	test1[0] = '1';
	test1[1] = '2';
	test1[2] = '3';
	test1[3] = '4';
	
	printf("test1: %s\n", test1);
	//printf("test2: %s\n", test2);
	
	test2 = test1;
	
	printf("test1: %s\n", test1);
	printf("test2: %s\n", test2);
	//======================================
	/* 
	In the second section, I want to test the pointer of poitners, which can be used to represent 2d array
	*/
	int idx;      // counter
	char **array; // pointer of array of arrays
	
	// allocate the pointer of array of arrarys
	array = malloc(nrows * sizeof(char *));
	
	// allocate the pointer of each array in the 2d array
	// Note that each array has the same size
	for(idx = 0; idx < nrows; idx++){	
		array[idx] = malloc(ncols * sizeof(char));		
	} // end for loop
	
	// print out the array
	printf("print the 2d array\n");
	printf("%s\n", array[0]);
	printf("%s\n", array[1]);
	
	// unable to assigned by pointer
	//array[0] = test1;
	
	// assigned by elements
	array[0][0] = 'a';
    array[0][1] = 'b';
    
    // assigned using loop
	for (idx = 0; idx < ncols; idx++){
	    array[1][idx] = test1[idx];	
	} // end for loop
	
	// print out the array
	printf("print the 2d array\n");
	printf("%s\n", array[0]);
	printf("%s\n", array[1]);
	
	// free the memory
	for(idx = 0; idx < nrows; idx++){
		free(array[idx]);
	} // end for loop
	
	/* 
	In the third section, I want to test the whether each array in the 2d array
	should contain the same size or not
	*/
	// construct several different size of array
	char str01[5] = "1234";
	char str02[5] = "6789";
	char str03[12] = "abcdefghijk";
	
	// declare the 2d int array
	char** array02;
	char** array03;
	
	// allocate the pointer of array of arrays
	array02 = malloc(nrows * sizeof(char *));
	array03 = malloc(nrows * sizeof(char *));
	
	// assigned by pointers (sith same size)
	array02[0] = str01;
	array02[1] = str02;	
	
	printf("\narray02\n");
	printf("%s, size: %d\n", array02[0], strlen(array02[0]));
	printf("%s, size: %d\n", array02[1], strlen(array02[1]));
	
	// assigned by pointers (with different size)
	array03[0] = str01;
	array03[1] = str03;	
	
	printf("\narray02\n");
	printf("%s, size: %d\n", array03[0], strlen(array03[0]));
	printf("%s, size: %d\n", array03[1], strlen(array03[1]));
	
	free(array02);
	free(array03);
	
	/* make sure that this could be applied to the int array */
	int** array04;
	int** array05;
	int int01[4] = {1, 2, 3, 4};
	int int02[4] = {5, 6, 7, 8};
    int int03[6] = {8, 9, 1, 2, 3, 4};
	
	// allocate 2d array
	array04 = malloc(nrows * sizeof(int *));
	array05 = malloc(nrows * sizeof(int *));
	
	// assigned by pointers()
	array04[0] = int01;
	array04[1] = int02;
	
	// assigned by pointers()
	array05[0] = int01;
	array05[1] = int03;
	
	free(array04);
	free(array05);
	
	return 0;
}
	
	
	
	
/*	
	int width;
	int height;
	int idx;
	
	width = 5;
	height = 2;
	
	char** arr1 = malloc(height * sizeof(char*));
	arr1[0] = malloc(width * sizeof(char));
	
	//arr1[0] = "1234";
	
	
	
	
	return 0;
}
*/

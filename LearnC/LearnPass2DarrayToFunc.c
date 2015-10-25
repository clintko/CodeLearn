#include <stdio.h>

//void test(int arr[height][width], int height, int width){
void test(int height, int width, int arr[height][width]){
	printf("%d %d %d %d\n", arr[0][0], arr[0][1], arr[0][2], arr[0][3]);
}

int main(){
	int arr[2][4] = { {1, 2, 3, 4}, 
	                  {2, 3, 4, 5} };
    
    //test(arr, 2, 4);
    test(2, 4, arr);
    
	return 0;	
}

/**/

char pic_gun01[4][21]=
    {"  __n-___      ____ "
    ,"_/n------\\____/---+ "
    ,"[[---=__!!------\\__|"
    ," |-\\\\\\]-            "
    };

char pic_gun02[4][21]=
    {"    ___________     "
    ," /.-{~~~~~}\\________"
    ,"|=======::====--<<<<"
    ," \\----YY-[_--/``````"
    };

char *fig_gun01;

char* pic_2dto1d(int height, int width, char pic_d2[height][width+1]){
    /* convert 2D array to 1D */
    char* pic_d1 = malloc(height * width * sizeof(char));
    int idx1, idx2;
    
    // specified each element to 1D array from input 2D array
    for (idx1 = 0; idx1 < height; idx1 += 1){
	for (idx2 = 0; idx2 < width; idx2 += 1){
	    
	    pic_d1[idx1 * width + idx2] = pic_d2[idx1][idx2];
	    
	} // end inner loop
    } // end outer loop

    return pic_d1;
}

void pic_print(char* fig, int height, int width){
    int idx1, idx2;

    for (idx1 = 0; idx1 < height; idx1 += 1){
	for (idx2 = 0; idx2 < width; idx2 += 1){
	    printf("%c", fig[idx1 * width + idx2]);
	} // end inner loop
	printf("\n");
    } // end outer loop
}

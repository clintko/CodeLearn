/**/
#include "LearnStructFuncPtr01_point.h"

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
// define structure
typedef struct Fig{
    // attributes
    Point* pos;
    int height;
    int width;
    int frame_tot; // total number of frame(pictures)
    int frame_cur; // the current frame(pictures)
    char** pic;

    // method
    void (*print)(struct Fig*);
    int (*getX)(struct Fig*);
    int (*getY)(struct Fig*);
    int (*getHeight)(struct Fig*);
    int (*getWidth)(struct Fig*);
    int (*moveUp)(struct Fig*);
    int (*moveDown)(struct Fig*);
    int (*moveLeft)(struct Fig*);
    int (*moveRight)(struct Fig*);
    int (*check)(struct Fig*, struct Point*);

}Fig;

// Function Prototype
Fig* Fig_init(int, int, int, int, int);
void Fig_print(Fig*);
int Fig_getX(Fig*);
int Fig_getY(Fig*);
int Fig_getHeight(Fig*);
int Fig_getWidth(Fig*);
int Fig_moveUp(Fig*);
int Fig_moveDown(Fig*);
int Fig_moveLeft(Fig*);
int Fig_moveRight(Fig*);
int Fig_check(Fig*, Point*);
int Fig_isPointInFig(Fig*, Point*);

char* fig_2dto1d(int height, int width, char pic_d2[height][width+1]);


// Implement Functions
Fig* Fig_init(int x, int y, int height, int width, int frame_tot){
    Fig* temp = malloc(sizeof(struct Fig));
    // initialized attributes
    temp->pos = Point_init(x, y);
    temp->height = height;
    temp->width = width;
    temp->frame_tot = frame_tot;
    temp->frame_cur = 0;

    // dynamic allocate pictures
    temp->pic = malloc(frame_tot * sizeof(char*));

    // assigned methods
    temp->print = Fig_print;
    temp->getX = Fig_getX;
    temp->getY = Fig_getY;
    temp->getHeight = Fig_getHeight;
    temp->getWidth = Fig_getWidth;
    temp->moveUp = Fig_moveUp;
    temp->moveDown = Fig_moveDown;
    temp->moveLeft = Fig_moveLeft;
    temp->check = Fig_check;
    
    return temp;
}

void Fig_print(Fig* temp){
    // 2 counter for iteration
    int idx1, idx2;

    // loop and print out 1d array as 2d picture
    for (idx1 = 0; idx1 < temp->height ; idx1 += 1){
	for (idx2 = 0; idx2 < temp->width; idx2 += 1){
	    printf("%c", temp->pic[temp->frame_cur][idx1 * temp->width + idx2]);
	} // end inner loop
	printf("\n");
    } // end outer loop
}

int Fig_getX(Fig* temp){
    return temp->pos->getX(temp->pos);
}

int Fig_getY(Fig* temp){
    return temp->pos->getY(temp->pos);
}

int Fig_getHeight(Fig *temp){
    return temp->height;
}

int Fig_getWidth(Fig *temp){
    return temp->width;
}

int Fig_moveUp(Fig *temp){
    temp->pos->moveUp(temp->pos);
}

int Fig_moveDown(Fig* temp){
    temp->pos->moveDown(temp->pos);
}

int Fig_moveLeft(Fig* temp){
    temp->pos->moveLeft(temp->pos);
}

int Fig_moveRight(Fig* temp){
    temp->pos->moveRight(temp->pos);
}

int Fig_check(Fig* fig, Point* point){
    return isPointInFig(fig, point);
}

int isPointInFig(Fig* fig, Point* point){
    int isPointXinFig;
    int isPointYinFig;
    
    if ((point->x >= fig->pos->x) &&
        (point->x < (fig->pos->x + fig->width))){
        isPointXinFig = 1;
    } else {
	isPointXinFig = 0;
    } // end if-else

    if ((point->y >= fig->pos->y) &&
        (point->y < (fig->pos->y + fig->height))){
        isPointYinFig = 1;
    } else {
	isPointYinFig = 0;
    } // end if-else


    return (isPointXinFig && isPointYinFig);
				    
}

// helper function
char* fig_2dto1d(int height, int width, char pic_d2[height][width+1]){
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


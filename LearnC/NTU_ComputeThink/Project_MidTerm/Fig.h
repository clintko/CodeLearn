/* NTU_ComputeThink Midterm Project */
//#include "LearnStructFuncPtr01_point.h"

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
    Point* pos;    // the position of the figure
    int height;    // height of the figure
    int width;     // width of the figure
    int frame_tot; // total number of frame(pictures)
    int frame_cur; // the current frame(pictures)
    char** pic;    // the 2d array of char;
                   // each row stores a frame(pictures)
                   // the number of rows is the total number of frame(pictures)

    // method
    void (*print)(struct Fig*);      // print out the current frame
    int (*getX)(struct Fig*);        // Getter Method; get x coordinate
    int (*getY)(struct Fig*);        // Getter Method; get y coordinate
    int (*getHeight)(struct Fig*);   // Getter Method; get figure height
    int (*getWidth)(struct Fig*);    // Getter Method; get figure width
    int (*getFrameTot)(struct Fig*); // Getter Method;
                                     // get the total number of frame
    int (*getFrameCur)(struct Fig*); // Getter Method;
                                     // get the current index of frame
    void (*setX)(struct Fig*, int);  // Setter Method; set x coordinate
    void (*setY)(struct Fig*, int);  // Setter Method; set y coordinate
    void (*reset)(struct Fig*);      // reset the figure to the origin
    int (*moveUp)(struct Fig*);      // shift the picture one step up
    int (*moveDown)(struct Fig*);    // shift the picture one step down
    int (*moveLeft)(struct Fig*);    // shift the picture one step left
    int (*moveRight)(struct Fig*);   // shift the picture one step right
    //void (*addPic)(struct Fig*, char*); // add picture to the figure
    void (*addPic)(struct Fig*self, int height, int width, char pic[height][width+1]);
    int (*check)(struct Fig*, struct Point*);
    void (*freeFig)(struct Fig*);    // free the memory of Fig
    
}Fig;

// Function Prototype
Fig* Fig_init(int, int, int, int);
void Fig_print(Fig*);
int Fig_getX(Fig*);
int Fig_getY(Fig*);
int Fig_getHeight(Fig*);
int Fig_getWidth(Fig*);
int Fig_getFrameTot(Fig*);
int Fig_getFrameCur(Fig*);
void Fig_setX(Fig*, int);
void Fig_setY(Fig*, int);
void Fig_reset(Fig*);
int Fig_moveUp(Fig*);
int Fig_moveDown(Fig*);
int Fig_moveLeft(Fig*);
int Fig_moveRight(Fig*);
//void Fig_addPic(Fig*, char*);
void Fig_addPic(Fig* self, int height, int width, char pic[height][width+1]);
int Fig_check(Fig*, Point*);
int Fig_isPointInFig(Fig*, Point*);
void Fig_free(Fig*);

char* fig_2dto1d(int height, int width, char pic_d2[height][width+1]);


// Implement Functions
Fig* Fig_init(int x, int y, int height, int width){
    Fig* self = malloc(sizeof(struct Fig));
    // initialized attributes
    self->pos = Point_init(x, y);
    self->height = height;
    self->width = width;
    self->frame_tot = 0;
    self->frame_cur = 0;

    // dynamic allocate pictures
    self->pic = malloc(self->frame_tot * sizeof(char*));
    
    // initialize the picture array
    int counter = 0;
    for (counter = 0; counter < (self->frame_tot); counter += 1){
	self->pic[counter] = 0;
    } // end for loop
    
    // assigned methods
    self->print = Fig_print;
    self->getX = Fig_getX;
    self->getY = Fig_getY;
    self->getHeight = Fig_getHeight;
    self->getWidth = Fig_getWidth;
    self->getFrameTot = Fig_getFrameTot;
    self->getFrameCur = Fig_getFrameCur;
    self->setX = Fig_setX;
    self->setY = Fig_setY;
    self->reset = Fig_reset;
    self->moveUp = Fig_moveUp;
    self->moveDown = Fig_moveDown;
    self->moveLeft = Fig_moveLeft;
    self->moveRight = Fig_moveRight;
    self->addPic = Fig_addPic;
    self->check = Fig_check;
    self->freeFig = Fig_free;
    
    return self;
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
    /* Getter method; get the x coordinate */
    return temp->pos->getX(temp->pos);
}

int Fig_getY(Fig* self){
    /* Getter method; get the y coordinate */
    return self->pos->getY(self->pos);
}

int Fig_getHeight(Fig *self){
    /* Getter method; get the height of figure */
    return self->height;
}

int Fig_getWidth(Fig *self){
    /* Getter method; get the width of figure*/
    return self->width;
}

int Fig_getFrameTot(Fig* self){
    /* Getter method; get the total number of 
       pictures in the figure */
    return self->frame_tot;
}

int Fig_getFrameCur(Fig* self){
    /* Getter method; get the current index of 
       pictures in the figure */
    return self->frame_cur;
}

void Fig_setX(Fig *self, int x){
    /* Setter method; set the x coordinate */
    self->pos->setX(self->pos, x);
}

void Fig_setY(Fig *self, int y){
    /* Setter method; set the y coordinate */
    self->pos->setY(self->pos, y);
}

void Fig_reset(Fig *self){
    /* reset the figure to the origin */
    self->setX(self, 0);
    self->setY(self, 0);
}

int Fig_moveUp(Fig *self){
    /* move the figure one step up by decrementing the y coordinate */
    self->pos->moveUp(self->pos);
}

int Fig_moveDown(Fig* self){
    /* move the figure one step dwon by incrementing the y coordinate */
    self->pos->moveDown(self->pos);
}

int Fig_moveLeft(Fig* self){
    /* move the figure one step left by decrementing the x coordinate */
    self->pos->moveLeft(self->pos);
}

int Fig_moveRight(Fig* self){
    /* move the figure one step right by incrementing the x coordinate */
    self->pos->moveRight(self->pos);
}

//void Fig_addPic(Fig* self, char pic[self->height][self->width+1]){
void Fig_addPic(Fig* self, int height, int width, char pic[height][width+1]){
    /* add a picture into the figure */

    // dynamic allocate picture array
    char **temp_pic = malloc((self->frame_tot + 1) * sizeof(char*));
    int counter;
    
    // initialize the picture array
    for (counter = 0; counter < (self->frame_tot + 1); counter += 1){
	temp_pic[counter] = 0;
    } // end for loop
    
    // copy the content from self->pic to temp_pic
    for (counter = 0; counter < (self->frame_tot); counter += 1){
        temp_pic[counter] = self->pic[counter];	
    } // end for loop

    // assign the new picture
    //temp_pic[self->frame_tot] = pic;
    temp_pic[self->frame_tot] = fig_2dto1d(self->height, self->width, pic);
	
    // free the original picture array of figures
    free(self->pic);

    // assigned the new pictures to figures
    self->pic = temp_pic;
    
    // increment the total frame
    self->frame_tot += 1;
}

int Fig_check(Fig* fig, Point* point){
    return isPointInFig(fig, point);
}

void Fig_free(Fig* temp){
    int counter;
    // free the picture in the Figure
    for(counter = 0; counter < temp->frame_tot; counter += 1){
	// free each picture
	free(temp->pic[counter]);
    } // end for loop
    free(temp->pic);

    // free the Figure
    free(temp);
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
    char* pic_d1 = malloc(height * width * sizeof(char) + 1);
    int idx1, idx2;

    // initialize the array
    for(idx1 = 0; idx1 < (height * width + 1); idx1 += 1){
    	pic_d1[idx1] = 0;
    } // end for loop
    
    // specified each element to 1D array from input 2D array
    for (idx1 = 0; idx1 < height; idx1 += 1){
	for (idx2 = 0; idx2 < width; idx2 += 1){
	    
	    pic_d1[idx1 * width + idx2] = pic_d2[idx1][idx2];
	    
	} // end inner loop
    } // end outer loop
    
    return pic_d1;
}


/* NTU_ComputeThink MidTerm Project
Header File: Point

Desc:
    Define the structure "Point". The structure Point
contains the attributes and methods needed to describe
a point on the 2d plane
*/

// define structure
typedef struct Point{
    int x;                                 // x coordinate
    int y;                                 // y coordinate
    void (*print)(struct Point*);          // method that print out the point
    int (*getX)(struct Point*);            // getter method; get x coordinate
    int (*getY)(struct Point*);            // getter method; get y coordinate
    void (*setX)(struct Point*, int);      // setter method; set x coordinate
    void (*setY)(struct Point*, int);      // setter method; set y coordinate
    void (*reset)(struct Point*);          // reset the point to origin
    void (*moveLeft)(struct Point*);       // move the point one step to the left
    void (*moveRight)(struct Point*);      // move the point one step to the right
    void (*moveUp)(struct Point*);         // move the point one step to the up
    void (*moveDown)(struct Point*);       // move the point one step to the down
    void (*freePoint)(struct Point*);      // free the memory of the point
}Point;

// Function Prototype (for instructor of the Point)
Point* Point_init(int, int);
void Point_print(Point*);
int Point_getX(Point*);
int Point_getY(Point*);
void Point_setX(Point*, int);
void Point_setY(Point*, int);
void Point_reset(Point*);
void Point_left(Point*);
void Point_right(Point*);
void Point_up(Point*);
void Point_down(Point*);
void Point_free(Point*);

// Implement Method Functions
Point* Point_init(int x, int y){
    /* constructor of Point */
    Point* temp = malloc(sizeof(struct Point));
    temp->x = x;
    temp->y = y;
    temp->print = Point_print;
    temp->getX = Point_getX;
    temp->getY = Point_getY;
    temp->setX = Point_setX;
    temp->setY = Point_setY;
    temp->reset = Point_reset;
    temp->moveLeft = Point_left;
    temp->moveRight = Point_right;
    temp->moveUp = Point_up;
    temp->moveDown = Point_down;
    temp->freePoint = Point_free;
    return temp;
}

void Point_print(struct Point* temp){
    /* print out the current position of the point */
    printf("Location of Point\n");
    printf("--------------------\n");
    printf("Coordinate x: %d\n", temp->x);
    printf("Coordinate y: %d\n", temp->y);
    printf("--------------------\n\n");
}

int Point_getX(struct Point* temp){
    /* getter function of point */
    return temp->x;
}

int Point_getY(struct Point* temp){
    /* getter function of point */
    return temp->y;
}

void Point_setX(struct Point *temp, int x){
    /* setter function for setting x coordinate */
    temp->x = x;
}

void Point_setY(struct Point *temp, int y){
    /* setter funcntion for setting y coordinate */
    temp->y = y;
}

void Point_reset(struct Point *temp){
    /* reset the point to origin (0, 0) */
    Point_setX(temp, 0);
    Point_setY(temp, 0);
}

void Point_left(struct Point *temp){
    /* left shift the point */
    temp->x -= 1;
}

void Point_right(struct Point *temp){
    /* right shift the point */
    temp->x += 1;
}

void Point_up(struct Point *temp){
    /* up shift the point; 
       Note that the origin is at the left upper corner */
    temp->y -= 1;
}

void Point_down(struct Point *temp){
    /* down shift the point;
       Note that the orgin is at the left upper corner */
    temp->y += 1;
}

void Point_free(struct Point *temp){
    /* free the memory */
    free(temp);
}

/**/

// define structure
typedef struct Point{
    int x;
    int y;
    void (*print)(struct Point*);
    int (*getX)(struct Point*);
    int (*getY)(struct Point*);
    void (*set)(struct Point*, int, int);
    void (*reset)(struct Point*);
    void (*moveLeft)(struct Point*);
    void (*moveRight)(struct Point*);
    void (*moveUp)(struct Point*);
    void (*moveDown)(struct Point*);
}Point;

// Function Prototype (for instructor of the Point)
Point* Point_init(int, int);
void Point_print(Point*);
int Point_getX(Point*);
int Point_getY(Point*);
void Point_set(Point *, int, int);
void Point_reset(Point*);
void Point_left(Point*);
void Point_right(Point*);
void Point_up(Point*);
void Point_down(Point *);

// Implement Method Functions
Point* Point_init(int x, int y){
    /* constructor of Point */
    Point* temp = malloc(sizeof(struct Point));
    temp->x = x;
    temp->y = y;
    temp->print = Point_print;
    temp->getX = Point_getX;
    temp->getY = Point_getY;
    temp->set = Point_set;
    temp->reset = Point_reset;
    temp->moveLeft = Point_left;
    temp->moveRight = Point_right;
    temp->moveUp = Point_up;
    temp->moveDown = Point_down;
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

void Point_set(struct Point *temp, int x, int y){
    /* setter function for the point */
    temp->x = x;
    temp->y = y;
}

void Point_reset(struct Point *temp){
    /* reset the point to origin (0, 0) */
    Point_set(temp, 0, 0);
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

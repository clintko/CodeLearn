/**/

// define structure
typedef struct Pixel{
    int x;
    int y;
    void (*print)(struct Pixel*);
}Pixel;

// Function Prototype (for instructor of the Pixel)
Pixel* Pixel_init(int, int);
void Pixel_print(Pixel*);

// Implement Method Functions
Pixel* Pixel_init(int x, int y){
    Pixel* temp = malloc(sizeof(Pixel));
    temp->x = x;
    temp->y = y;
    temp->print = Pixel_print;
    return temp;
}

void Pixel_print(struct Pixel* temp){
    /**/
    printf("Location of Point\n");
    printf("--------------------\n");
    printf("Coordinate x: %d\n", temp->x);
    printf("Coordinate y: %d\n", temp->y);
    printf("--------------------");
}

//void Pixel_set(struct Pixel temp){
//}

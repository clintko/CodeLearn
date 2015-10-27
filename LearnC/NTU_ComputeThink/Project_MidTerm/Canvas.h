/* NTU_ComputeThink

*/

typedef struct Canvas{
    Point* pos;
    int height;
    int width;
    char *pic;

    int (*getHeight)(struct Canvas*);
    int (*getWidth)(struct Canvas*);
    int (*setFig)(struct Canvas*, struct Fig*);
    void (*draw)(struct Canvas*, struct Point*, char);
    void (*show)(struct Canvas*);
    void (*cleanAll)(struct Canvas*);
    void (*freeCanvas)(struct Canvas*);
}Canvas;

Canvas* Canvas_init(int, int);
int Canvas_getHeight(Canvas*);
int Canvas_getWidth(Canvas*);
void Canvas_setFig(Canvas*, struct Fig*);
void Canvas_draw(Canvas* struct Point*, char);
void Canvas_show(Canvas*);
void Canvas_cleanAll(Canvas*);
void Canvas_freeCanvas(Canvas*);


Canvas* Canvas_init(int height, int width){
    Canvas* self = malloc(sizeof(struct Canvas));
    // initialized attributes
    self->pos = Point-init(0, 0);
    self->height = height;
    self->width = width;

    // canvas picture
    char pic[height][width];
    self->pic = pic;

    // assigned methods
    self->getHeight = Canvas_getHeight;
    self->getWidth = Canvas_getWidth;
    self->setFig = Canvas_setFig;
    self->draw = Canvas_draw;
    self->show = Canvas_show;
    self->cleanAll = Canvas_cleanAll;
    self->freeCanvas = Canvas_freeCanvas;
}

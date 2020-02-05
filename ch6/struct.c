#include <stdio.h>
#include <stdlib.h>

// examples take from page 128->130 of c book

struct point { 
    int x;
    int y;
};

struct nestedpoint {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y) {
    struct point p;
    p.x = x, p.y = y;
    return p;
}

struct point addpoints(struct point p1, struct point p2) {
    p1.x = p1.x + p2.x;
    p1.y = p1.y + p2.y;
    return p1;
}

struct point *addpointsp(struct point p1, struct point p2) {
    p1.x = p1.x + p2.x;
    p1.y = p1.y + p2.y;
    struct point *p = malloc(sizeof(p1));
    *p = p1;
    return p;
}

int main() {
    struct point maxpoint = { 200, 300 }; // with initialization
    struct point funcpt = makepoint(300, 400);
    struct nestedpoint npt = { maxpoint, funcpt };
    struct point combined = addpoints(npt.pt1, npt.pt2);
    struct point *combinedp = addpointsp(npt.pt1, npt.pt2);
    printf("yes initialization\tx: %d\ty: %d\n", maxpoint.x, maxpoint.y);
    printf("func init\tx: %d\ty: %d\n", funcpt.x, funcpt.y);
    printf("combined\tx: %d\ty: %d\n", combined.x, combined.y);
    printf("combined pointer address: %p\n", *combinedp);
    printf("%s", npt.pt1);
    return 0;
}
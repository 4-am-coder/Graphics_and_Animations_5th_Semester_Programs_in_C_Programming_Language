// Write a Program to translate a triangle about the origin.
#include <stdio.h>
#include <graphics.h>

// Function to translate a point
void translatePoint(int *x, int *y, int tx, int ty) {
    *x = *x + tx;
    *y = *y + ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original coordinates of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;

    // Translation factors
    int tx = 50, ty = 50;

    // Drawing the original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Translating the triangle
    translatePoint(&x1, &y1, tx, ty);
    translatePoint(&x2, &y2, tx, ty);
    translatePoint(&x3, &y3, tx, ty);

    // Drawing the translated triangle
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}

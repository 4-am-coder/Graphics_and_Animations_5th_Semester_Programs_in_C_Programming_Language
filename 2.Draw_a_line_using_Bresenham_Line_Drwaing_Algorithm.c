// Write a Program in C to draw a line using Bresenham’s line drawing algorithm.

#include <stdio.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        putpixel(x1, y1, WHITE); // Place a pixel at (x1, y1)

        if (x1 == x2 && y1 == y2) break; // End condition

        e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 200, y2 = 150;
    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

// Write a Program in C to fill a circle using Flood Fill algorithm.

#include <stdio.h>
#include <graphics.h>

void floodFill(int x, int y, int fill_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        putpixel(x, y, fill_color);
        floodFill(x + 1, y, fill_color, old_color);
        floodFill(x - 1, y, fill_color, old_color);
        floodFill(x, y + 1, fill_color, old_color);
        floodFill(x, y - 1, fill_color, old_color);
    }
}

void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 200, r = 100;
    drawCircleMidpoint(xc, yc, r);

    int fill_color = RED;
    int old_color = BLACK; // Assuming the background color is black

    floodFill(xc, yc, fill_color, old_color);

    getch();
    closegraph();
    return 0;
}

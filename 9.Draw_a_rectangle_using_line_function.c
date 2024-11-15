// Write a Program to draw a rectangle using line function.

#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the rectangle
    int left = 100, top = 100;
    int right = 300, bottom = 200;

    // Drawing the rectangle using the line function
    line(left, top, right, top);        // Top side
    line(right, top, right, bottom);    // Right side
    line(right, bottom, left, bottom);  // Bottom side
    line(left, bottom, left, top);      // Left side

    getch();
    closegraph();
    return 0;
}

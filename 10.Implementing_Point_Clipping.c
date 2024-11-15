// Write a Program to implement Point clipping.

#include <stdio.h>
#include <graphics.h>

// Function to check whether a point is inside the clipping window
int isInside(int x, int y, int x_min, int y_min, int x_max, int y_max) {
    return (x >= x_min && x <= x_max && y >= y_min && y <= y_max);
}

// Function to draw and clip points
void drawAndClipPoints(int points[][2], int n, int x_min, int y_min, int x_max, int y_max) {
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        if (isInside(x, y, x_min, y_min, x_max, y_max)) {
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Window boundaries
    int x_min = 100, y_min = 100;
    int x_max = 300, y_max = 300;

    // Drawing the clipping rectangle
    rectangle(x_min, y_min, x_max, y_max);

    // Points to be clipped
    int points[5][2] = {
        {50, 150},
        {150, 150},
        {350, 150},
        {150, 250},
        {250, 350}
    };
    int n = 5; // Number of points

    // Drawing and clipping points
    drawAndClipPoints(points, n, x_min, y_min, x_max, y_max);

    getch();
    closegraph();
    return 0;
}

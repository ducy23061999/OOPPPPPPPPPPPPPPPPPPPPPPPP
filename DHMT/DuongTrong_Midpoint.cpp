#include "graphics.h"
#include <iostream>
#include <math.h>
using namespace std;

void put8pixel(int xc, int yc, int x, int y, int color)
{
    // cout << x << "|" << y << "|" << xc + x << "|" << yc + y << endl;
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}
void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0; int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y, color);
    for (;x < round(r / sqrt(2)); x++) {
        if (f < 0) {
            f += 2*x + 3;
        } else {
            y--;
            f += 2*(x - y) + 5;
        };
        put8pixel(xc, yc,x,y,color);
    }
}
void drawCircleBresenham(int xc, int yc, int r, int color) {
    int x = 0, y = r;
    int p = 3 - 2*r;
    cout << p << "|";
    put8pixel(xc,yc,x,y,color);
    for (; x <= round(r / sqrt(2)); x++) {
        if (p < 0) {
            p+= 4*x + 6;
        } else {
            y--;
            p += 4*(x - y) + 10;
        }
        cout << p << "|";
        put8pixel(xc,yc,x,y,color);
    }
    
}

int main() {

    int gd = DETECT, gm;
    // int x0, y0, R;
    // cin >> x0 >> y0 >> R;
    // int x = x0, y = y0 + R;
    // int P = 1 - R;

    // draw
    initgraph(&gd, &gm, NULL);
    drawCircleBresenham(2, 10, 6, 3);
    // drawCircleMidpoint(200, 200, 100, 6);

    getch();
    closegraph();
}
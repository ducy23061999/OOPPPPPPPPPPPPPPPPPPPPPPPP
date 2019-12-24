#include "graphics.h"
#include <iostream>
#include <math.h>
using namespace std;
float f(float x, float y, float D){
    return round(abs(y - D*x));
}

int main() {

    int gd = DETECT, gm;
    
    float x, y, a, b;
    cin >> x >> y >> a >> b;
    float dx, dy;
    dx = a - x;
    dy = b - y;
    float D = dy / dx;
    

    // draw
    float Y;
    initgraph(&gd, &gm, NULL);
    for (int i = x; i <= a; i++) {
        Y = f(i,y,D);
        putpixel(i,Y,4);
    }
    getch();
    closegraph();
}
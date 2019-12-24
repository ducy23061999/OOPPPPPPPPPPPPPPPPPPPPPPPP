#include "graphics.h"
#include <iostream>
#include <math.h>
using namespace std;
float f(float x, float y, float D){
    return round(abs(y - D*x));
}

int main() {

    int gd = DETECT, gm;
    float x1, y1, a, b;
    cin >> x1 >> y1 >> a >> b;
    float dx, dy;
    dx = a - x1;
    dy = b - y1;
    float D = dy / dx;
    float x = x1, y = y1;
    
    initgraph(&gd, &gm, NULL);
    putpixel(x, round(y), 4); // Ve y0
    for (int i = x1; i <= a; i++) {
        y += D;
        putpixel(i,y,4);
    }
    
    getch();
    closegraph();
}
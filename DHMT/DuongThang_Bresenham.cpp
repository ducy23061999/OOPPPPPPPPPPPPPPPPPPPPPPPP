#include "graphics.h"
#include <iostream>
#include <math.h>
using namespace std;
float f(float x, float y, float D){
    return round(abs(y - D*x));
}
void aa(int x1, int y1, int x2, int y2, int color) {
    float dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    setcolor(color);
    int const1 = 2*dy,
        const2 = 2*dy + 2*dx;
    float x = x1, y = y1;
    int P = 2*dy - 2*dx;
    cout << x <<"|"<<y<< " | "<< P<<endl;

    putpixel(x,y,color);
    for (int i = x1; i <= x2; i++){
        if (P < 0) {
            P += const1;
        } else {
            P += const2;
            y++;
        }
        cout << i << "|"<<y << "|" << P<<endl;
        putpixel(i,y,color);

    }
}

int main() {

    int gd = DETECT, gm;

  
    initgraph(&gd, &gm, NULL);
    aa(11,20,22,27,1);
    
    getch();
    closegraph();
}
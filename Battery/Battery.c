/* Battery System */
/*
    Arrange a battery
    Heat dissipation
*/

#include <stdio.h>
#include <stdlib.h>

#define tSize 60
enum material{PLASTIC,ALUMINUM,MAGNESIUM,STEEL};

typedef struct {
    int battArr[tSize];
    float surface[tSize];
    int width, height;
    float charge;
    float draw;
    int material;
    float transferAmount;
} battery;

typedef struct {
    int sX, sY;
    int eX, eY;
} cell;

void Display(battery * b) {
    printf("\t~BATTERY ARRANGEMENT~\n");
    for(int i = 0; i < b->width; i++) {
        for(int j = 0; j < b->height; j++) {
            printf("%d,", b->battArr[i+j*b->width]);
        }
        putchar('\n');
    }
    printf("\n\t\t~SURFACE~\n");
    for(int i = 0; i < b->width; i++) {
        for(int j = 0; j < b->height; j++) {
            printf("%.1f,", b->surface[i+j*b->width]);
        }
        putchar('\n');
    }
    printf("Charge: %f\n", b->charge);
}

const int boundsCheck(const int w, const int h, const int pos) {
    return pos >= 0 && pos < w && pos < h;
}

void Run(battery * b) {
    b->charge -= b->draw;
    int w = b->width, h = b->height;
    for(unsigned int i = 0; i < b->width; i++) {
        for(unsigned int j = 0; j < b->height; j++) {
            if(b->battArr[i+j*b->width]) {
                // Propogate heat
                b->surface[i+j*b->width] += b->transferAmount;
                if(boundsCheck(w,h,i-1+j*b->width) && b->battArr[i-1+j*b->width] != 1) { 
                    b->surface[i-1+j*b->width] += b->transferAmount;
                    if(b->surface[i-1+j*b->width])
                        printf("Temperature warning at point: %d : %d\n", i-1, j);
                }
                if(boundsCheck(w,h,i+1+j*b->width) && b->battArr[i+1+j*b->width] != 1) {
                    b->surface[i-1+j*b->width] += b->transferAmount;
                    if(b->surface[i+1+j*b->width])
                        printf("Temperature warning at point: %d : %d\n", i+1, j);
                }
                if(boundsCheck(w,h,i+j-1*b->width) && b->battArr[i+j-1*b->width] != 1) {
                    b->surface[i-1+j*b->width] += b->transferAmount;
                    if(b->surface[i+j-1*b->width])
                        printf("Temperature warning at point: %d : %d\n", i, j-1);
                }
                if(boundsCheck(w,h,i+j+1*b->width) && b->battArr[i+j+1*b->width] != 1) {
                    b->surface[i-1+j*b->width] += b->transferAmount;
                    if(b->surface[i+j+1*b->width])
                        printf("Temperature warning at point: %d : %d\n", i, j+1);
                }
            }

            // Heat Prop algo test 1 | Make radial!
            for(int k = 0; k < b->width; k++)
                b->surface[i+k*b->width] += b->transferAmount * k/10;
            for(int l = 0; l < b->width; l++)
                b->surface[l+j*b->width] += b->transferAmount * l/10;
        }
    }
}

battery ConstructBattery() {
    battery newBat;
    // Width + height calc | Probably much better way of doing this
    for(int i = 1; i < 12; i++) {
        for(int j = 1; j < 12; j++) {
            if(i * j == tSize) {
                newBat.height = i;
                newBat.width = j;
            }
        }
    }
    // Arrange batteries in blocks
        // Transformation matrices!
    int batSizeX = newBat.width/3, batSizeY = newBat.height;
    cell c;

    int batCount = 4;
    int storedXPoints[10];
    int storedYPoints[10];
    int xTop = 0, yTop = 0;
    while(batCount > 0) { // DO AABB!
        c.sX = rand() % newBat.width;
        while(c.sX == storedXPoints[xTop])
            c.sX = rand() % newBat.width;
        storedXPoints[xTop] = c.sX;
        c.sY = rand() % newBat.height;
        while(c.sY == storedYPoints[yTop])
            c.sY = rand() % newBat.height;
        storedYPoints[yTop] = c.sY;
        xTop++;
        yTop++;
        for(int i = c.sY; i < c.eY; i++) {
            for(int j = c.sX; j < c.eX; j++) {
                newBat.battArr[i+j*newBat.width] = 1;
            }
        }
    }

    /*
    int curPlaced = 0;
    for(int i = 0; i < newBat.width; i++) {
        for(int j = 0; j < newBat.height; j++) {
            newBat.surface[i+j*newBat.width] = 0.0f;
            int startY = i, startX = j;
            int endX = rand() % newBat.width;
            int endY = rand() % newBat.height;
            for(int k = i; k < endY; k++) {
                newBat.surface[k*newBat.width] = 1;
                for(int l = j; l < endX; l++)
                    newBat.surface[k+l*newBat.width] = 1;
            }
            if(j <= newBat.width/3) {
                newBat.battArr[i+j*newBat.width] = 1;
                // curPlaced++;
            } else {
                newBat.battArr[i+j*newBat.width] = 0;
            }
            if(curPlaced == batSizeX * batSizeY)
                break;
            j = endX;
            i = endY;
        }
        if(curPlaced == batSizeX * batSizeY)
            break;
    }
    */

    newBat.charge = 100.0f;
    newBat.draw = 1.0f;
    newBat.material = PLASTIC;
    switch(newBat.material) {
        case PLASTIC:   newBat.transferAmount = 0.5; break;
        case ALUMINUM:  newBat.transferAmount = 1.5; break;
        case MAGNESIUM: newBat.transferAmount = 2.5; break;
        case STEEL:     newBat.transferAmount = 1.0; break;
    }
    return newBat;
}

void Execute() {
    battery b = ConstructBattery();
    Display(&b);
    while(b.charge > 0.0f) {
        Run(&b);
        Display(&b);
    }
    printf("Drained!\n");
}

int main(int argc, char * argv[]) {
    printf("Battery System:\n");
    Execute();

    return 0;
}
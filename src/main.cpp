#include "mbed.h"
#include "SDFileSystem.h"

SDFileSystem sd(D4, D5, D3, D7, "sd"); // the pinout on the mbed Cool Components workshop board

Serial pc(USBTX, USBRX);

int main() {
    pc.printf("Hello World from atom !\n");

    //mkdir("/sd/mydir", 0777);

    FILE *fp = fopen("/sd/blackbox.csv", "w");
    if(fp == NULL) {
        pc.printf("Could not open file for write\n");
    }
    fprintf(fp, "X, Y, Z\n");
    fprintf(fp, "8, 8, 8\n");
    fprintf(fp, "4, 4, 4\n");

    fclose(fp);

    pc.printf("Goodbye World!\n");
}

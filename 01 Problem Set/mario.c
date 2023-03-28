#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int height = 0;
    
    // Get height input
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Return pyramid
    for (int i = 1; i <= height; i++) {
        // Left side print
        for (int j = height; j > 0; j--) {
            if (j > i) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("  ");
        // Right side print
        for (int j = 1; j <= height; j++) {
            if (j <= i) {
                printf("#");
            }
        }
        printf("\n");
    }
}
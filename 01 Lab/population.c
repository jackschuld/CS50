#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int numberOfYears = 0;

    // TODO: Prompt for start size
    do {
        printf("Start size: ");
        scanf("%d", &startSize);
    } while (startSize < 9);

    // TODO: Prompt for end size
    do {
        printf("End size: ");
        scanf("%d", &endSize);
    } while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    while (startSize < endSize) {
        startSize += ((startSize/3) - (startSize/4));
        numberOfYears++;
    }
    // TODO: Print number of years
    printf("Years: %d\n", numberOfYears);
}

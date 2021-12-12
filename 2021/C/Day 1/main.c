#include <stdio.h>
#define N 2000

int main()
{
    int array[N] = { 0 };

    FILE *inputFile;
    inputFile = fopen("day1_input.txt", "r");
    for (int i = 0; i < N; i++)
    {
        fscanf(inputFile, "%i", &array[i]);
    }

    // Part 1
    {
        int count = 0;
        for (int i = N-1; i >= 1; i--)
        {
            if (array[i] > array[i - 1])
                count++;
        }
        printf("Solution part 1: %i\n", count);
    }

    // Part 2
    {
        int count = 0;
        for (int i = N-1; i>=2; i--)
        {
            if (array[i] > array[i-3])
                count++;
        }
        printf("Solution part 2: %i\n", count);
    }

    fclose(inputFile);

    return 0;
}

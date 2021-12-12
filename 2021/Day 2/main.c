#include <stdio.h>
#include <string.h>

int main()
{
    FILE *inputFile;
    inputFile = fopen("day2_input.txt", "r");

    // Part 1
    {
        int posX = 0;
        int posY = 0;
        int posChange = 0;
        char wordInput[8] = { 0 };

        while (!feof(inputFile)) {
            fscanf(inputFile, "%s %i", wordInput, &posChange);
            if (strcmp(wordInput, "forward") == 0)
                posX += posChange;
            else if (strcmp(wordInput, "down") == 0)
                posY += posChange;
            else
                posY -= posChange;
        }
        printf("Solution part 1: %i\n", posX*posY);
    }

    // Part 2
    {
        int posX = 0;
        int posY = 0;
        int posChange = 0;
        int aim = 0;
        char wordInput[8] = { 0 };

        fseek(inputFile, 0, SEEK_SET);
        while (!feof(inputFile))
        {
            fscanf(inputFile, "%s %i", wordInput, &posChange);
            if (strcmp(wordInput, "forward") == 0)
            {
                posX += posChange;
                posY = posY + (posChange * aim);
            }
            else if (strcmp(wordInput, "down") == 0)
            {
                aim += posChange;
            }
            else
                aim -= posChange;
        }
        printf("Solution part 2: %i\n", posX*posY);
    }

    fclose(inputFile);

    return 0;
}

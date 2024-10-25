#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
     // Simplified usage check
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file with simplified error handling
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) return 1;

    FILE *outputImg = NULL;

    BYTE buff[512];
    char fname[8];
    int imgCount = 0;

    // Read file in chunks of 512 bytes
    while (fread(buff, sizeof(BYTE), 512, inputFile) == 512)
    {
        // Check for JPEG header
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            if (outputImg) fclose(outputImg); // Close the previous image if open

            sprintf(fname, "%03i.jpg", imgCount++);
            outputImg = fopen(fname, "w");
        }

        // If there is an open image file, continue writing
        if (outputImg) fwrite(buff, sizeof(BYTE), 512, outputImg);
    }

    // Close any remaining open files
    fclose(inputFile);
    if (outputImg) fclose(outputImg);

    return 0;
}

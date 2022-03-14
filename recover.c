#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *source = fopen(argv[1], "r");

    if (source == NULL)
    {
        printf("Error: File cannot be opened\n");
        return 1;
    }

    BYTE buffer[512];
    FILE *destination = NULL;
    char filename[8];
    int counter = 0;

    while (fread(&buffer, sizeof(buffer), 1, source) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))

        {
            if (counter > 0) //if not first file
            {
                fclose(destination);
                sprintf(filename, "%03i.jpg", counter);
                counter ++;
                destination = fopen(filename, "w");
                fwrite(&buffer, sizeof(buffer), 1, destination);
            }

            else if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                counter ++;
                destination = fopen(filename, "w");
                fwrite(&buffer, sizeof(buffer), 1, destination);
            }
        }
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(buffer), 1, destination);
        }
    }
    fclose(source);
    fclose(destination);
    return 0;
}

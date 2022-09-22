#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define GLOBAL_HEADER 24
#define UDP_HEADER 8

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // File not provided through command line
        printf("File not provided!\n");
        exit(0);
    }
    else
    {
        FILE *file = fopen(argv[1], "rb");
        char c;

        if (file == 0)
        {
            printf("Could not open file!\n");
            exit(EXIT_FAILURE);
        }
        else
        {

            fseek(file, GLOBAL_HEADER, SEEK_SET);
            while ((c = fgetc(file)) != EOF)
            {
                printf("\n\n---------------------------------\n");

                fseek(file, 50 - 1, SEEK_CUR);

                // Read UDP data
                unsigned char udp_data[UDP_HEADER];
                fread(udp_data, 1, UDP_HEADER, file);

               
                
            }
            printf("\n");

            fclose(file);
        }
    }
}
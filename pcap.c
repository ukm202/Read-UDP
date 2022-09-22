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

                // Source port
                unsigned short source_port = (ntohs(udp_data[0])) | udp_data[1];
                printf("Src port: %d \n", source_port);

                // Destination port
                unsigned short destination_port = (ntohs(udp_data[2])) | udp_data[3];
                printf("Des port: %d \n", destination_port);

                // UDP Packet Length
                unsigned short udp_length = (ntohs(udp_data[4])) | udp_data[5];
                printf("UDP Packet Length: %d \n", udp_length);

                // Get the checksum
                unsigned short checksum = (ntohs(udp_data[6])) | udp_data[7];

                // Printing checkusum as hex
                printf("Checksum: 0x%x \n", checksum);

                
                
            }
            printf("\n");

            fclose(file);
        }
    }
}
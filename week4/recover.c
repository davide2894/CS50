/*
    CS50

    This program recovers 50 JPEGs
    from an image of a memory card
    called card.raw
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open infile\n");
        return 2;
    }


    //memory block storage
    byte buffer[512];

    //track new names
    char name[8];

    //set name counter to 0
    int count = -1;


    FILE *outptr = fopen("#.jpg", "w");
    if(outptr == NULL)
    {
        fprintf(stderr, "err: could not open starting outfile\n");
        return 3;
    }


    while( fread(&buffer, 1, 512, inptr) == 512 )
    {
        //if jpeg signature is found
        if( buffer[0]==0xff &&
            buffer[1]==0xd8 &&
            buffer[2]==0xff &&
            (buffer[3] & 0xf0) == 0xe0 )
        {

            //close old file
            fclose(outptr);


            //update name counter
            count++;


            //create updated new jpg name
            sprintf(name, "%03i.jpg", count);
            printf("%s\n", name);

            //open new outfile file with new jpg name
            outptr = fopen(&name[0], "w" );
            if(outptr==NULL)
            {
                fprintf(stderr, "err: could not open inloop file\n");
                return 4;
            }
        }
        //write data on previously opened file
        fwrite(&buffer, 1, 512, outptr);

    }








    //close card.raw
    fclose(inptr);
    fclose(outptr);
    //success
    return 0;
}

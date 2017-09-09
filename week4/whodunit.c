#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: ./whodunit infile outfile\n");
        return 1;
    }

    //remember file name
    char *infile = argv[1]; //point infile to argv[1]'s value
    char *outfile = argv[2]; //point outfile to argv[2]' value

    //open input file
    FILE *inptr = fopen(infile, "r");
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open the file\n");
        return 2;
    }

    FILE *outptr = fopen(outfile, "w");
    if(outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not open the file\n");
        return 3;
    }

    //read infile BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    //read infile BITMAPFILEINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //make sure input file is 24-bit uncompressed BMP 4.0
    if( bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40
        || bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fclose(outptr);
            fclose(inptr);
            fprintf(stderr, "Format not supported\n");
            return 4;
        }

    //write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    //write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    int padding = ( 4 - ( bi.biWidth * sizeof( RGBTRIPLE ) ) %4 ) %4;

    //iterate over infile's scaniles
    for(int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //iterate over infile's pixels
        for(int j = 0; j < bi.biWidth; j++)
        {
            //temporary storage
            RGBTRIPLE triple;

            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            if(
                triple.rgbtRed == 0xff)
            {
                //remove red
                 triple.rgbtBlue = 0x00;
                 triple.rgbtGreen = 0x00;
                 triple.rgbtRed = 0x00;
            }

            //write rgb red-lacking triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        //skip padding if any so we enter the following scanline
        fseek(inptr, padding, SEEK_CUR);

        //put back the padding
        for(int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }

    }


    //close infile
    fclose(inptr);

    //close outfile
    fclose(outptr);

    //success
    return 0;
}
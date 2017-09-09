#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not open %s\n", outfile);
        return 3;
    }

    //make sure 1 >= n =< 100
    if(n < 1 || n > 100)
    {
        fclose(inptr);
        fclose(outptr);
        fprintf(stderr, "n allowed range: 1 to 100\n");
        return 4;
    }


    //temporary storage
    BITMAPFILEHEADER bf;
    //read infile's BITMAPFILEHEADER
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);


    //temporary storage
    BITMAPINFOHEADER bi;
    //read infile's BITMAPINFOHEADER
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);



    //make sure infile is 24-bit uncompressed BMP 4.0
    if( bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(inptr);
        fclose(outptr);
        fprintf(stderr, "Unsupported format\n");
        return 5;
    }

    //infile measures
    int old_biWidth = bi.biWidth;
    int old_padding = (4 - (old_biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int old_biHeight = bi.biHeight;

    //outfile enlarged measures
    bi.biWidth *= n;
    int new_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biHeight *= n;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + new_padding) * abs(bi.biHeight);
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;


    //write them in outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    //write them in outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    int offset = (old_biWidth * sizeof(RGBTRIPLE));




    //VERTICAL RESIZE
    //for each row
    for(int i = 0, biHeight = abs(old_biHeight); i < biHeight; i++)
    {
        //for n-1 times
        for(int v = 0; v < n-1; v++)
        {
            //write pixels
            for(int j = 0; j < old_biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //write each infile pixel to outfile n times
                for(int k = 0; k < n; k++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            //pad to outfile
            for (int l = 0; l < new_padding; l++)
            {
                fputc(0x00, outptr);
            }

            //send cursor back to the beginning of the row
            fseek(inptr, -offset, SEEK_CUR);

        }



        //write pixels for last time before entering new row
        for(int h = 0; h < old_biWidth; h++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //write each infile pixel to outfile n times
            for(int k = 0; k < n; k++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        //pad to outfile
        for (int l = 0; l < new_padding; l++)
        {
            fputc(0x00, outptr);
        }

        //skip infile padding, if any
        fseek(inptr, old_padding, SEEK_CUR);
    }




    fclose(inptr);
    fclose(outptr);

    //success
    return 0;
}


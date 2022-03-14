// code for creating instagram filters

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //initialize grayscale array

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;

        }

    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            if (sepiaRed >= 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen >= 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue >= 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width / 2; j++)
        {

            int tmpred = image[i][j].rgbtRed;
            int tmpgreen = image[i][j].rgbtGreen;
            int tmpblue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - 1- j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 - j].rgbtRed = tmpred;
            image[i][width - 1 - j].rgbtGreen = tmpgreen;
            image[i][width - 1 - j].rgbtBlue = tmpblue;

        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    int red = 0;
    int green = 0;
    int blue = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    float counter = 0.0;

    for (i = 0; i < height; i++)
    {
        
        for (j = 0; j < width; j++)
        {
            
            //if top left corner

            if (i == 0 && j == 0)
            {
                
                for (x = 0; x <= 1; x++)
                {
                    
                    for (y = 0; y <= 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = 0;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //if top right corner

            else if (i == 0 && j == width - 1)
            {

                for (x = 0; x <= 1; x++)
                {

                    for (y = width - 2; y <= width - 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = width - 2;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //bottom left

            else if (i == height - 1 && j == 0)
            {

                for (x = height - 2; x <= height - 1; x++)
                {

                    for (y = 0; y <= 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = 0;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //bottom right

            else if (i == height - 1 && j == width - 1)
            {

                for (x = height - 2; x <= height - 1; x++)
                {

                    for (y = width - 2; y <= width - 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = width - 2;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //top row

            else if ((i == 0 && j > 0 && j < width - 1))
            {

                for (x = 0; x <= 1; x++)
                {

                    for (y = j - 1; y <= j + 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = j - 1;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //left row

            else if ((i > 0 && i < height - 1 && j == 0))
            {

                for (x = i - 1; x <= i + 1; x++)
                {

                    for (y = 0; y <= 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = 0;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //right row

            else if ((i > 0 && i < height - 1 && j == width - 1))
            {

                for (x = i - 1; x <= i + 1; x++)
                {

                    for (y = width - 2; y <= width - 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = width - 2;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            //bottom row

            else if ((i == height - 1 && j > 0 && j < width - 1))
            {

                for (x = height - 2; x <= height - 1; x++)
                {

                    for (y = j - 1; y <= j + 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = j - 1;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }
          
            else
            {
              
                for (x = i - 1; x <= i + 1; x++)
                {
                  
                    for (y = j - 1; y <= j + 1; y++)
                    {

                        red += image[x][y].rgbtRed;
                        green += image[x][y].rgbtGreen;
                        blue += image[x][y].rgbtBlue;
                        counter++;

                    }

                    y = j - 1;

                }

                tmp[i][j].rgbtRed = round(red / counter);
                tmp[i][j].rgbtGreen = round(green / counter);
                tmp[i][j].rgbtBlue = round(blue / counter);
                red = green = blue = 0;
                counter = 0.0;

            }

        }

    }
   
    for (i = 0; i < height; i++)
    {
      
        for (j = 0; j < width; j++)
        {
          
            image[i][j] = tmp[i][j];

        }

    }

    return;

}

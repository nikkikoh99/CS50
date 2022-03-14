#include <cs50.h>
#include <stdio.h>
#include <math.h>

//code allows you to create a simple mario pyramid

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter height here:\n");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = height-1; j >= i; j--)
        {
            printf(" ");
        }
        
        for (int k = 1; k <=i; k++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}

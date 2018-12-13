
// Creates half Mario pyramid
// Nadia Abby
// Problem Set 1

#include <cs50.h>
#include <stdio.h>

int main(void)
{

// Pyramid variables
    int height, spaces, bricks, i;

// Prompt user for Pyramid height
    do
    {
        height = get_int("Please give a positive number no greater than 23: ");
    }
    while (height < 0 || height > 23);

// Build the height of pyramid
    for (i = height; i > 0; i--)
    {
        // Create spaces
        for (spaces = i - 1; spaces > 0; spaces--)
        {
            printf(" ");
        }
        // Height bricks
        printf("#");

// Build the columns of pyramid
        for (bricks = height; bricks >= i; bricks--)
        {
            printf("#");
        }

        printf("\n");

    }

}

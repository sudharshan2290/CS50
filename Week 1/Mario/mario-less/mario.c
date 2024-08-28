#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hash;
    do
    {
        hash = get_int("Homany rows :");
    }
    while (hash < 1 || hash > 8);

    for (int lenght = 0; lenght < hash; lenght++)
    {
        for (int spaces = 0; spaces < hash - lenght - 1; spaces++)
        {
            printf(" ");
        }
        for (int height = 0; height <= lenght; height++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}

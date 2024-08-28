#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hash;
    do
    {
        hash = get_int("HOw many Rows :");
    }
    while (hash < 1 || hash > 8);

    for (int height = 0; height < hash; height++)

    {
        for (int spaces = 0; spaces < hash - height - 1; spaces++)
        {
            printf(" ");
        }
        for (int lenght1 = 0; lenght1 <= height; lenght1++)
        {
            printf("#");
        }
        {
            printf("  ");
        }

        for (int lenght = 0; lenght <= height; lenght++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}

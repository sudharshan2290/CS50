#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string caesar(string text, int key);

int main(int argc, string argv[])
{ // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext:\n");
    string ciphertext = caesar(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
string caesar(string text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            char offset = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + key) % 26 + offset;
        }
    }
    return text;
}

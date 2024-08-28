#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_index(int letters, int words, int sentences);

int main(void)
{

    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float index = calculate_index(letters, words, sentences);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

    // printf("Letters: %i\n", letters);
    // printf("Words: %i\n", words);
    // printf("Sentences: %i\n", sentences);
    // printf("Coleman-Liau Index: %.0f\n", index);
}

int count_letters(string text)
{
    // Return the number of letters in text
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // Return the number of words in text
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
float calculate_index(int letters, int words, int sentences)
{
    {
        float L = ((float) letters / words) * 100;
        float S = ((float) sentences / words) * 100;
        float index = 0.0588 * L - 0.296 * S - 15.8;
        return index;
    }
}

#include <cs50.h>
#include <stdio.h>

long credit_card(long card_number);
string card_type(long card_number);

int main(void)
{
    long card_number = get_long("enter the card number :");
    if (credit_card(card_number))
    {
        printf("%s\n", card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
}

long credit_card(long card_number)
{
    int sum = 0;
    int second_number = 0;
    int is_second = 0;

    while (card_number > 0)
    {
        int number = card_number % 10;

        if (is_second)
        {
            second_number = number * 2;
            if (second_number > 9)
            {
                sum += (second_number % 10) + (second_number / 10);
            }
            else
            {
                sum += second_number;
            }
        }
        else
        {
            sum += number;
        }
        is_second = !is_second;
        card_number /= 10;
    }
    return (sum % 10 == 0);
}

string card_type(long card_number)
{

    int length = 0;
    long temp_number = card_number;

    while (temp_number > 0)
    {
        temp_number /= 10;
        length++;
    }

    long first_two_digits = card_number;
    while (first_two_digits >= 100)
    {
        first_two_digits /= 10;
    }

    if ((length == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    else if ((length == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && (first_two_digits / 10 == 4))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

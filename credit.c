#include <cs50.h>
#include <stdio.h>

int every_other_number(long credit);
int all_numbers(long credit, int partial_sum);

int main(void)
{
    long credit = get_long("Number: ");
    int sum_of_it_all = every_other_number(credit);
    int final_sum = all_numbers(credit, sum_of_it_all);
    if (final_sum % 10 == 0)
    {
        int length = 0;
        long start = credit;
        while (start >= 100)
        {
            start /= 10;
            length++;
        }
        length += 2;
        int first_digit = start / 10;
        if ((start == 34 || start == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (start >= 51 && start <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (first_digit == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int every_other_number(long credit)
{
    int sum = 0;
    bool isAltDigit = false;
    while (credit > 0)
    {
        if (isAltDigit == true)
        {
            int last_digit = credit % 10;
            last_digit *= 2;
            sum += (last_digit % 10) + (last_digit / 10);
        }
        credit = credit / 10;
        isAltDigit = !isAltDigit;
    }
    return sum;
}

int all_numbers(long credit, int partial_sum)
{
    int total = partial_sum;
    bool isAltDigit = true;
    while (credit > 0)
    {
        if (isAltDigit == true)
        {
            int meow = credit % 10;
            total += meow;
        }
        credit = credit / 10;
        isAltDigit = !isAltDigit;
    }
    return total;
    printf("%i\n", total);
}

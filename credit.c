// Jason Berinsky
// 13 February 2019
// CS 50 Problem Set 1
// Determines if a credit card number is a valid AMEX, MasterCard, or Visa number
#include <stdio.h>
#include <cs50.h>

void amex(long long int);
void mc(long long int);
void visa(long long int);

int totals(long long int, int);
int get_digit(long long int, int);

int main(void)
{
    long long int input = get_long("Number: ");
    if ((input >= 340000000000000 && input <= 349999999999999) || (input >= 370000000000000 && input <=             379999999999999))
    {
        amex(input);
    }  
    else if ((input >= 4000000000000 && input <= 4999999999999) || (input >= 4000000000000000 && input <= 4999999999999999))
    {
        visa(input);
    }
    else if (input >= 5100000000000000 && input <= 5599999999999999)
    {
        mc(input);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Returns the specified digit of a number
int get_digit(long long int input, int digit)
{
    long long int inputa = input;
    long long int inputb = input;
    long long int divider = 10;
    for (int i = 1; i <= digit; i++)
    {
        inputa -= (inputa % divider);
        divider *= 10;
    }
    inputb = inputb % (divider / 100);
    long long int ans = (input - inputa - inputb) / (divider / 100);
    return (ans);
}

// Checks if a credit card number is a valid AMEX number
void amex(long long int input)
{
    int sum = totals(input, 15);
    if (sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Checks if a credit card number is a valid MasterCard number
void mc(long long int input)
{
    int sum = totals(input, 16);
    if (sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Checks if a credit card number is a valid Visa number
void visa(long long int input)
{
    int sum;
    if (input > 10000000000000)
    {
        sum = totals(input, 16);
    }
    else
    {
        sum = totals(input, 13);
    }
    
    if (sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Sums the digits of a credit card number according to Luhn's algorithm
int totals(long long int input, int length)
{
    int suma = 0;
    int sumb = 0;
    int digit;
    for (int i = 2; i <= length; i += 2)
    {
        digit = 2 * get_digit(input, i);
        if (digit >= 10)
        {
            suma = suma + get_digit(digit, 1) + get_digit(digit, 2);
        }
        else
        {
            suma = suma + digit;
        }
    }
    for (int i = 1; i <= length; i += 2)
    {
        digit = get_digit(input, i);
        sumb = sumb + digit;
    }
    return suma + sumb;
}

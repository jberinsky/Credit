# Jason Berinsky
# CS 50 Problem Set 6
# Checks the validity of credit card numbers

from cs50 import get_int


def get_digit(number, digit):
    numbera = number
    numberb = number
    divider = 10
    for i in range(1, digit + 1):
        numbera = numbera - numbera % divider
        divider = divider * 10
    numberb = numberb % (divider / 100)
    ans = (number - numbera - numberb) / (divider / 100)
    return (ans)


def amex(number):
    total = totals(number, 15)
    if total % 10 == 0:
        print("AMEX")
    else:
        print("INVALID")


def mc(number):
    total = totals(number, 16)
    if total % 10 == 0:
        print("MASTERCARD")
    else:
        print("INVALID")


def visa(number):
    if number > 10000000000000:
        total = totals(number, 16)
    else:
        total = totals(number, 13)

    if total % 10 == 0:
        print("VISA")
    else:
        print("INVALID")


def totals(number, length):
    suma = 0
    sumb = 0
    digit = 0
    for i in range(2, length + 1, 2):
        digit = 2 * get_digit(number, i)
        if digit >= 10:
            suma = suma + get_digit(digit, 1) + get_digit(digit, 2)
        else:
            suma = suma + digit

    for i in range(1, length + 1, 2):
        sumb = sumb + get_digit(number, i)

    return suma + sumb


number = get_int("Number: ")
if (number >= 340000000000000 and number <= 349999999999999) or (number >= 370000000000000 and number <= 379999999999999):
    amex(number)
elif (number >= 4000000000000 and number <= 4999999999999) or (number >= 4000000000000000 and number <= 4999999999999999):
    visa(number)
elif number >= 5100000000000000 and number <= 5599999999999999:
    mc(number)
else:
    print("INVALID")
/* 
Stanford's CS50x Pset2 Task2
Vigenere Cipher
It's increase letter's index by keyword's letter's index.
    Ex. keyword: aaaa
    A -> B     b -> c
    y -> z     Z -> A
Using ASCII table for process.

September 2020
*/ 

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int translate(string keyword, int i); // Translate letters to alphabet index 1 to 26
bool check(string keyword); // Creating a check funct (keyword must consist only letters)

int main(int argc, string argv[])
{
    string keyword = argv[1];
    if(check(keyword) == false)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    string mes = get_string("plaintext: ");
    int len = strlen(mes);
    int chip;

    printf("ciphertext: ");
    int j=0;
    for(int i=0; i<len; i++)
    {
        j = i%strlen(keyword); //Keyword can be shorter than text. It turns to back first letter.

        chip = mes[i] + translate(keyword, j);
        if(isupper(mes[i])) // if a letter is upper case, it's ASCII between 65 to 90
                {
                    if(chip > 90) // if ciphed bigger than 90 it isn't upper case
                        printf("%c", chip-26); //turn upper
                    else
                        printf("%c", chip);
                }
                else if(islower(mes[i])) // if a letter is lower case, it's ASCII between 97 to 122
                {
                    if(chip > 122) // if ciphed bigger than 122 it isn't lower case
                        printf("%c", chip-26); //turn lower 
                    else
                        printf("%c", chip);
                } 
                else
                    printf("%c", mes[i]);
            }
            printf("\n");
    return 0;
}

bool check(string keyword)
{
     if(keyword)
     {
        for(int i=0; i<strlen(keyword); i++)
        {
            if(isdigit(keyword[i]))
                return false;
        }
    }
    else
        return false;
    return true;
}

int translate(string keyword, int i)
{
    if(keyword[i] > 90)
       keyword[i] = toupper(keyword[i]); 

    int key = keyword[i] - 64;
    return key;
}

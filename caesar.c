/* 
Stanford's CS50x Pset2 Task1
Caesar Cipher
It's increase letter's index by key number.
    Ex. key number: 2
    A -> C     b -> d
    y -> a     Z -> B
Using ASCII table for process.

September 2020
*/ 

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argv[1])
     {
        int key = atoi(argv[1]);
        printf("Key: %i \n", key);
        
        if(key > 0) // Key must be integer
        {
            string mes; // Message's variable
            mes = get_string("plaintext: ");
            int len = strlen(mes);
            int chip;

            printf("ciphertext: ");
            for(int i=0; i<len; i++)
            {
                chip = mes[i] + (key%26); //encrypting i. letter
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
        }
        else
        {
            printf("Usage: ./caesar key \n");
        return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    return 0;
}

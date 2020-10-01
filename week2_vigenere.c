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

bool check(string keyword);
int translate(string keyword, int index);

int main(int argc, string argv[])
{
    string keyword = argv[1];
    if(check(keyword) == false)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    
    string plain = get_string("Plaintext: ");
    int plen = strlen(plain);
    int chip;

    printf("ciphertext: ");
    int j=0;
    for(int i=0; i<plen; i++)
    {
        if(isalnum(plain[i]))
        {
            chip = plain[i] + translate(keyword, j);
            
               if(isupper(plain[i])) 
                {
                    if(chip > 90)
                        printf("%c", chip-26);
                    else
                        printf("%c", chip);
                }
                else if(islower(plain[i]))
                {
                    if(chip > 122)
                        printf("%c", chip-26);
                    else
                        printf("%c", chip);
                } 
        j++;
        if(j >= strlen(keyword))
            j=0;

        }
        else
            printf("%c", plain[i]);
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

int translate(string keyword, int index)
{
    int key=0;
    if(keyword[index] > 90)
        keyword[index] = toupper(keyword[index]);

    key = keyword[index] - 65;

    return key;
}

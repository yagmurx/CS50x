/*
Stanford's CS50x Pset1 Task1
Enter your name
print "hi, name"

August 2020
*/
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string name = get_string("Hi! What's your name? \n");
    printf("Hi, %s \n", name);
}

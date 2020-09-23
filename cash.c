/* 
Stanford's CS50x Pset1 Task4
Giving minimum coin to customer
September 2020
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float c= 0.0;
    do
    {
        c = get_float("Change owed: ");

    }
    while (c < 0);
    
    int cash=0;
    cash = round(c*100);
    
    int i=0;
    while(cash != 0)
    {
        int buff=0;
        if( cash > 24)
        {
            buff = cash / 25;
            cash = cash - (buff*25); 
        }

        else if(cash < 24 && cash > 9)
        {
            buff = cash / 10;
            cash = cash - (buff*10);
        }
        else if(cash < 9 && cash > 4)
        {
            buff = cash / 5;
            cash = cash - (buff*5);
        }
        else if(cash < 5 && cash > 0) 
        {
            buff = cash / 1;
            cash = cash - (buff*1);
        }
        i = i + buff;
    }
    printf("Unit: %i \n", i);
    return 0;
}

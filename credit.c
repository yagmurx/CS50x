/*
Enter a Credit Card Number 
Using Luhn's Algorithm
Output AMEX, MASTERCARD, VISA or INVALID

September 2020
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int GetNum(int index, long cardnum); //Geting a number from Credit Card
int GetValidLen(long cardnum); // Calculate Credit Card Number's Length
bool Lunh(long cardnum, int len); // Lunh Algorithm
void CardName(long cardnum, int len); // Output Card Service Name

int main (void)
    {
        long cardnum=0;
        cardnum = get_long("Number: "); // Get Credit Card Number
        int len = GetValidLen(cardnum);

        if(Lunh(cardnum, len) == true) // Lunh Algorithm is provided
            CardName(cardnum, len);
        else
            printf("INVALID\n"); 

        return 0;
    }

    int GetNum(int index, long cardnum)
     {
        int num=0; 
        long buff=0.0;                      //Ex. cardnumber: 1453 target: 4 -> index: 2
        buff = cardnum / pow(10,index);     //buff = 1453 / 100 
        cardnum = buff * pow(10,index);     // cardnum = 14 * 100
        buff = cardnum / pow(10, index+1);  // buff = 1400 / 1000
        buff = buff * pow(10, index+1);     // buff = 1 * 1000
        cardnum = cardnum - buff;           // cardnum = 1400 - 1000
        num = cardnum / pow(10,index);      // num = 400 / 100
        return num;                         // 4
    }

    int GetValidLen(long cardnum)
    {
        if(cardnum > pow(10,13) && cardnum < pow(10,14))
            return 14;
        else if(cardnum > pow(10,14) && cardnum < pow(10,15))
            return 15;
        else if(cardnum > pow(10,15) && cardnum < pow(10,16))
            return 16;

            return 99;
    }

    bool Lunh(long cardnum,int len)
    {
        int calc=0;
        for(int i=1; i<len; i+=2)
        {
            int buff=0;
            buff = GetNum(i, cardnum)*2;
               
            if(buff > 9)
            {
                calc = calc + buff % 10;
                calc = calc + 1;
            }
            else
                calc = calc + buff;
                
        }
        for(int i=0; i<len; i+=2)
            calc = calc + GetNum(i, cardnum);
            
        if(calc%10 == 0)
            return true;
        else
            return false;
    }

    void CardName(long cardnum, int len)
    {
        int cardname = GetNum(len-1, cardnum);
        if(cardname == 3)
        {
            cardname = GetNum(len-2, cardnum);
            if(cardname == 4 || cardname == 7)
                printf("AMEX\n");
            else
                printf("INVALID\n");
        }
        else if(cardname == 5)
        {
            cardname = GetNum(len-2, cardnum);
            if(cardname == 1 || cardname == 2 || cardname == 3
                || cardname == 4 || cardname == 5) 
                printf("MASTERCARD\n");
            else
                printf("INVALID\n");
        }
        else if(cardname == 4)
                printf("VISA\n");
        else
            printf("INVALID\n");
    }

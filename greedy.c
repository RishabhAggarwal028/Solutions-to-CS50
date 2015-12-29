#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    
    do
    {
        printf("How much change is owed?");
        change = GetFloat();
    }
    while (change < 0);
    
    int cents = round(change*100);
    int coins = 0;

    
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }    
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }    
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
        }    
        else if (cents >= 1)
        {
            cents = cents - 1;
            coins++;
        }    
            
    }   
    
    
    printf("%d\n", coins);
    return 0;
}

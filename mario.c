#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
    int height;
    int all_rows;
    int space;
    int hash;
 
    do
    {
        printf("Welcome to Mario! Please choose a number from 0 to 23:");
        height = GetInt();
    }
    while ((height < 0) || (height > 23));
 
     for (all_rows = 1; all_rows <= height; all_rows++) 
    {
        for (space = (height - all_rows); space > 0; space--)
        {
            printf(" "); 
        }
 
        for (hash = 1; hash <= (all_rows + 1); hash++)
        {   
            printf("#"); 
        }
 
        printf("\n");
    }
    return 0;
}

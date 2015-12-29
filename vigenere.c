# include<cs50.h>
# include<stdio.h>
# include<string.h>
# include<ctype.h>
#include<stdlib.h>

int checkArguments(int argc, string argv[]);
void vigenere(string plainText, string sequenceKeys);

int main( int argc, string argv[])
{
    int check =  checkArguments(argc,  argv);
    if (check == 1 ) // exit program
        return 1;
   
    string plainText = GetString();
    string sequenceKeys = argv[1];
    
    vigenere( plainText, sequenceKeys);

}
     
void vigenere(string plainText, string sequenceKeys)
{    
    int plainLen =strlen(plainText);
    int sequenceLen =strlen(sequenceKeys);  
    
    int k=0;
    for( int j = 0; j< plainLen ; j++)
    {
        int asc = plainText[j];
        
        if (isalpha (plainText[j]))
        {
            char plain, seq ;
            int  ascP, ascS;
            
            plain = plainText[j];
            
            int i = k % sequenceLen; 
            k++;
            seq = sequenceKeys[i];
           
            
            if(isupper(plain))
            {
                seq = toupper(seq);
                ascS = seq - 65;
            }
            else
            {
                seq = tolower(seq);
                ascS = seq - 97;
            }
            
            ascP = isupper(plain) ? 65 : 97 ;
            
            if (isupper(plain) &&  (asc> 64 && asc <91)) 
            {
                asc = asc + ascS;
                asc = asc - ascP; 
                asc = (asc) % 26 + ascP; 
            }
            else if (islower(plain) &&  (asc> 96 && asc <123))
            {
                asc = asc + ascS;
                asc = asc - ascP; 
                asc = (asc) % 26 + ascP; 
            }
        }
        printf("%c",asc);
    }
    printf("\n");
     
}

int checkArguments(int argc, string argv[])
{
   if (argc != 2)
    {
        printf ("Valid Key is not entered\n");
        return 1;
    }
    string sequenceKeys = argv[1];
    int sequenceLen = strlen(sequenceKeys);
    for(int i=0 ; i < sequenceLen; i++)
    {
        if (! isalpha (sequenceKeys[i]))
        {
            printf ("Key is not alpha\n");
            return 1;
        }
    }
    return 0;
}

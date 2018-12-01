#include <stdio.h>
#include <stdlib.h>

//97 - 122
//65 - 80
//FUNCTIONEAZA
int frequency[26];

int main()
{
    char currentChar;
    int currentIndex;

    FILE*fp=fopen("date.in","r");
    int mx=0;

    while(fscanf(fp,"%c",&currentChar)!=-1)
    {
        //printf("%c",)

        //Case 1: BIG LETTERS
        if(currentChar>=65 && currentChar<=80)
        {
            currentIndex=currentChar-65;
            frequency[currentIndex]++;
            mx=(mx<frequency[currentIndex])?frequency[currentIndex]:mx;
        }
        else
        {
            //Case 2: small letters
            if(currentChar>=97 && currentChar<=122)
            {
                currentIndex=currentChar-97;
                frequency[currentIndex]++;
                mx=(mx<frequency[currentIndex])?frequency[currentIndex]:mx;
            }
        }
    }

    if(mx)
    {
        for(currentIndex=0; currentIndex<26; currentIndex++)
            //printf("%c: %d\n",currentIndex+65,frequency[currentIndex]);//
        if(frequency[currentIndex]==mx)printf("%c",currentIndex+65);
    }
    else printf("Nu s-au gasit litere!!");


    fclose(fp);
    return 0;
}

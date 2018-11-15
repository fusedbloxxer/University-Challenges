#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char nume[30];
    int nr_legitimatie;
};

void readList(struct student *HeadStudent, unsigned int *Size)
{
    scanf("%d",Size);

    unsigned index;
    for(index=0;index<*Size;index++)
    {
        scanf("%d",&((HeadStudent+index)->nr_legitimatie));
        fgets((HeadStudent+index)->nume,29,stdin);
    }
}

void  encrypt(int encryptedData[], struct student *HeadStudent, unsigned int Size, unsigned int Key)
{
    unsigned index;

    for(index=0;index<Size;index++)
    {
        encryptedData[index]=(HeadStudent+index)->nr_legitimatie^Key;
    }
}

void printBinary(char filename[], int *encryptedData, unsigned int Size)
{
    FILE*fp=fopen(filename,"w");
    unsigned index;

    for(index=0;index<Size;index++)
    {
        int binaryIndex;
        for(binaryIndex=sizeof(int)*8-1;binaryIndex>=0;binaryIndex--)
        {
            if((*(encryptedData+index))&(1<<binaryIndex))fprintf(fp,"%d",1);
            else fprintf(fp,"%d",0);
        }

        fprintf(fp,"\n");
    }

    fclose(fp);
}

int decrypt(char FileName[100],unsigned int indexLine,unsigned int Key)
{
    FILE*fp=fopen(FileName,"r+");
    char binaryNumber[33];

    fseek(fp,indexLine*34,SEEK_SET);
    fgets(binaryNumber,33,fp);

    unsigned index;int decrypted=0;
    for(index=0;index<32;index++)
    {
        decrypted+=(binaryNumber[index]-'0')<<(32-index-1);
    }
    printf("%d\n",decrypted^Key);
    fclose(fp);
}

int main()
{
    int EncryptedList[2000];
    struct student BazaDate[2000];
    unsigned Size;

    int index;
    fscanf(stdin,"%d",&index);
    decrypt("out.txt",index,224);

    return 0;
}

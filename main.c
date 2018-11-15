#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char nume[30];
    int nr_legitimatie;
};

///Punctul 1
void readList(struct student *HeadStudent,unsigned int *Size)
{
    scanf("%d",Size);
    printf("Size=%d",*Size);

    unsigned index;
    for(index=0;index<*Size;index++)
    {
        scanf("%d",&((HeadStudent+index)->nr_legitimatie));
        fgets((HeadStudent+index)->nume,29,stdin);
    }
}


///Punctul 2
int*  encrypt(struct student *HeadStudent, unsigned int Size, unsigned int Key)
{
    int encryptedData[Size];
    unsigned index;

    for(index=0;index<Size;index++)
    {
        //encryptedData[index]=(HeadStudent+index)->nr_legitimatie^Key;
        (HeadStudent+index)->nr_legitimatie^=Key;
    }

    return encryptedData;
}

void printBinary(struct student *encryptedData,unsigned int Size)
{
    FILE*fp=fopen("out.txt","w");
    unsigned index;

    for(index=0;index<Size;index++)
    {
        ///& | !  ^
        int binaryIndex;
        for(binaryIndex=sizeof(int)*8-1;binaryIndex>=0;binaryIndex--)
        {
            if((encryptedData+index)->nr_legitimatie&(1<<binaryIndex))fprintf(fp,"%d",1);
            else fprintf(fp,"%d",0);
        }

        fprintf(fp,"\n");
    }
}

///Punctul 4
int decrypt(char FileName[100],unsigned int indexLine,unsigned int Key)
{
    FILE*fp=fopen(FileName,"r+");
    char binaryNumber[33];

    //unsigned int currentLine=0;
    //for(currentLine=0;currentLine<indexLine;currentLine++)
        //fgets(binaryNumber,33,fp);

    fseek(fp,indexLine*34,SEEK_SET);
    //printf("%d\n",ftell(fp));
    fgets(binaryNumber,33,fp);
    //printf("%s",binaryNumber);

    unsigned index;int decrypted=0;
    for(index=0;index<32;index++)
    {
        decrypted+=(binaryNumber[index]-'0')<<(32-index-1);
    }

    fseek(fp,-32,SEEK_CUR);
    fprintf(fp,"%d\n",decrypted^Key);
    //for(index=0;index<(32);index++)
    //    printf(" ");
    fclose(fp);
}

int main()
{
    int EncryptedList[2000];
    struct student BazaDate[2000];
    unsigned Size;

    //readList(BazaDate,&Size);
    //encrypt(BazaDate,Size,224);
    //printBinary(BazaDate,Size);

    decrypt("out.txt",3,224);

    return 0;
}

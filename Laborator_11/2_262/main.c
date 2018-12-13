#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Nu stiu daca este ok
int my_strlen(char *string, int size) {
    int index = 0;
    while(index < size && string[index] != '\0') {
        index++;
    }
    return index;
}
char *my_strcpy(char *string1, char *string2) {
    int N1 = my_strlen(string1, sizeof(string1));
    int N2 = my_strlen(string2, sizeof(string2));
    int index = 0;
    while(index < N1 && index < N2) {
        string1[index] = string2[index];
        index++;
    }
    string1[index] = '\0';
}//Nu stiu daca este ok
char *my_strcat(char *string1, char *string2) {
    int N1 = my_strlen(string1, sizeof(string1));
    int N2 = my_strlen(string2, sizeof(string2));
    int index = N1, index2 = 0;
    while(index < sizeof(string1) && index2 < N2) {
        string1[index] = string2[index2];
        index2++;
        index++;
    }
    string1[index] = '\0';
}
//Nu este ok
void my_strncat(char *dest, char *src, int dest_len) {

}
//Merge
char *my_strcpy_end(char *string) {
    int index =0;
    while(string[index++]!='\0');
    return string + index - 1;
}
//Merge
char *my_strrchr(char const *str, int ch) {
    int index;
    for(index = strlen(str); index>=0; index--) {
        if(str[index]==ch)return str+index;
    }
}
//Merge
char *my_strnchr(char const *str, int ch, int which) {
    int index, N = strlen(str), count = 0;
    for(index = 0; index < N; index++) {
        if(str[index] == ch) {
            count++;
            if(count == which) return str + index;
        }
    }
}
//Merge
int count_chars(char const *str, char const *chars) {
    int N1 = strlen(str), N2 = strlen(chars), index1, index2, count = 0;
    for(index1 = 0; index1 < N1; index1++) {
        for(index2 = 0; index2 < N2; index2++) {
            if(str[index1] == chars[index2]) count++;
        }
    }

    return count;
}
//Merge
int palindrome(char *string) {
    int index, index2, N = strlen(string);
    for(index = 0, index2 = N-1; index<index2 && index<N && index2>=0; index++, index2--)
    {
        while(string[index]<'A' || string[index]>'z' || string[index]>'Z' && string[index]<'a') index++;
        while(string[index2]<'A' || string[index2]>'z' || string[index2]>'Z' && string[index2]<'a') index2--;
        if(string[index]!=string[index2] ) {printf("%c",string[index2]);return 0;}
        // a == A
    }
    return 1;
}
int main()
{
    char s[] = "afbecddddddfd..dd/";
    char s1[] = "ab";
    //printf()
    printf("%d\n", palindrome("a'44A'''''''b531b[[]]A'a"));
    return 0;
}

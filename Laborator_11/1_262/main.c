#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *f = fopen("date.in", "r");
    int count, control_char, whitespace_char, digits, lower, upper, punctuation, non_print;
    count = control_char = whitespace_char = digits = lower = upper = punctuation = non_print =0;
    char c;
    while(fscanf(f, "%c", &c)!=-1) {
        if(iscntrl(c)) control_char++;
        else if(isspace(c)) whitespace_char++;
        else if(isdigit(c)) digits++;
        else if(islower(c)) lower++;
        else if(isupper(c)) upper++;
        else if(ispunct(c)) punctuation++;
        else if(isprint(c)) non_print++;

        count++;
    }

    printf("Control Characters: %.2f%%\n", control_char*100/(float)count);
    printf("Whitespace Characters: %.2f%%\n", whitespace_char*100/(float)count);
    printf("Digits: %.2f%%\n", digits*100/(float)count);
    printf("Lower Case Letters: %.2f%%\n", lower*100/(float)count);
    printf("Upper Case Letters: %.2f%%\n", upper*100/(float)count);
    printf("Punctuation Characters: %.2f%%\n", punctuation*100/(float)count);
    printf("Non-printable Characters: %.2f%%\n", non_print*100/(float)count);
    return 0;
}

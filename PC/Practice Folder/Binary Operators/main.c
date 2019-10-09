#include <stdio.h>
#include <stdlib.h>

float readOperation()
{
    float a, b;
    char c;
    fscanf(stdin, "%f %c %f", &a, &c, &b);
    switch(c)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
    {
        if(b != 0)
            return a/b;
        else
        {
            printf("Cannot divide by 0!");
            return -1;
        }
    }
    break;
    case '%':
    {
        if(b != 0)
            return (int)a%(int)b;
        else
        {
            printf("Cannot divide by 0!");
            return -1;
        }
    }
    break;
    default:
    {
        printf("Wrong operator used!");
        return -1;
    }
    break;
    }
    return -1;
}

int main()
{
    printf("%.2f", readOperation());

    return 0;
}

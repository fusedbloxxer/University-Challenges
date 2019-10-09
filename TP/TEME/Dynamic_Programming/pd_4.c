#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct text_line
{
    int length;
    char *text;
};

void print_lines(struct text_line *lines, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < lines[i].length; j++)
        {
            printf("%d ", lines[i].text[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void my_strcpy(char *arr_dest, char *arr_src)
{
    int i = 0;
    while(1)
    {

        if (arr_src[i] != '\0')
        {
            if (arr_src[i] == ' ')
            {
                arr_dest[i] = 0;

            }
            else
            {
                arr_dest[i] = -1;
            }

        }
        else
        {
            break;

        }
        i++;
    }
    arr_dest[i] = arr_src[i];
}

void dynamic(struct text_line *lines, int n)
{
    int max_length = -1;

    for (int i = 0; i < lines[n - 1].length; i++)
    {
        if (lines[n - 1].text[i] == 0) {
            lines[n - 1].text[i] = 1;
        }
    }


    print_lines(lines, n);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j < lines[i].length - 1; j++)
        {
            if (lines[i].text[j] == 0)
            {
                lines[i].text[j] = -1;

                if (j - 1 < lines[i + 1].length)
                {
                    lines[i].text[j] = lines[i + 1].text[j - 1];
                }
                if (j < lines[i + 1].length)
                {
                    if (lines[i].text[j] < lines[i + 1].text[j])
                    {
                        lines[i].text[j] = lines[i + 1].text[j];
                    }
                }
                if (j + 1 < lines[i + 1].length)
                {
                    if (lines[i].text[j] < lines[i + 1].text[j + 1])
                    {
                        lines[i].text[j] = lines[i + 1].text[j + 1];
                    }
                }

                if (lines[i].text[j] == -1) {
                    lines[i].text[j] = 1;
                } else {
                    lines[i].text[j] += 1;
                }

                if (max_length < lines[i].text[j]) {
                    max_length = lines[i].text[j];
                }
            }
        }
    }


    print_lines(lines, n);

    if (max_length <= 1) {
        printf("NU EXISTA RAU");
    } else {
        printf("Cel mai lung rau este: %d", max_length);
    }
}

int main()
{
    FILE *input = fopen("date.in", "r");
    struct text_line *lines;
    char buffer[1001];
    int n, i = 0;

    fscanf(input, "%d", &n);
    fgetc(input);
    lines = (struct text_line *)malloc(sizeof(struct text_line) * n);

    while(fgets(buffer, 1000, input) != NULL)
    {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
            len--;
        }
        (lines + i)->text = (char *)malloc(sizeof(char) * (len + 1));
        (lines + i)->length = len;
        my_strcpy((lines + i++)->text, buffer);

    }

    print_lines(lines, n);
    dynamic(lines, n);

    for (int i = 0; i < n; i++)
    {
        free(lines[i].text);
    }
    free(lines);
    fclose(input);
    return 0;
}

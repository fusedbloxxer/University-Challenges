#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int value;
    struct node *next;
    struct node *previous;
};

void push(struct node **head, struct node **tail, int value)
{
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->value = value;
        (*head)->next = NULL;
        (*head)->previous = NULL;
        *tail = *head;
    }
    else
    {
        struct node *aux = (struct node *)malloc(sizeof(struct node));
        aux->value = value;
        aux->next = *head;
        aux->previous = (*head)->previous;
        (*head)->previous = aux;

        *head = aux;
    }
}

int poll(struct node **head, struct node **tail)
{
    if ((*tail)->previous != NULL)
    {
        (*tail)->previous->next = NULL;
        struct node *aux = *tail;
        int value = aux->value;
        *tail = (*tail)->previous;
        free(aux);
        return value;
    }
    else
    {
        int value = (*tail)->value;
        free(*tail);
        *tail = NULL;
        *head = NULL;

        return value;
    }
}

int main()
{
    struct node *head = NULL, *tail = NULL;

    FILE *input = fopen("date.in", "r");
    int k, n, i;
    int maxValue = INT_MIN, currentValue = 0, f = 0, g = 0;

    fscanf(stdin, "%d", &k);
    fscanf(input, "%d", &n);

    for(i = 0; i < n; i++)
    {
        int currentElement;
        fscanf(input, "%d", &currentElement);

        push(&head, &tail, currentElement);

        currentValue += currentElement;
        printf("Suma k: %d <-> Elementul curent: %d\n", currentValue, currentElement);

        if (i - g + 1 == k)
        {
            if(maxValue < currentValue)
            {
                maxValue = currentValue;
            }
            currentValue = currentValue - poll(&head, &tail);
            g++;
        }
    }

    printf("value = %d", g, i, maxValue);

    fclose(input);
    return 0;
}

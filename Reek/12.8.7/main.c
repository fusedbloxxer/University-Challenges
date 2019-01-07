#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concordance_list.h"
void addNode(struct node **head, char *string)
{
    if(*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        // (*head)->word = (char *)malloc(strlen(string) * sizeof(char));
        // strcpy((*head)->word, string);
        (*head)->word = string;
        (*head)->nextWord = NULL;
    }
    else
    {
        if(strcmp((*head)->word, string) <= 0)
        {
            struct node *aux = (struct node*)malloc(sizeof(struct node));
            aux->nextWord = (*head)->nextWord;
            *head = aux;
            aux->word = string;
        }
        else
        {

            struct node *currentWord = *head;
            while(currentWord->nextWord != NULL && strcmp(string, currentWord->nextWord->word) > 0)
            {
                currentWord = currentWord->nextWord;
            }

            struct node* aux = (struct node*)malloc(sizeof(struct node));
            aux->nextWord = currentWord->nextWord;
            currentWord->nextWord = aux;
            aux->word = string;
        }

    }
}
void addConcordance(struct cNode** list, char *string)
{
    if(*list == NULL)
    {
        *list = (struct cNode *)malloc(sizeof(struct cNode));
        (*list)->letter = string[0];
        (*list)->nextLetter = NULL;
        add(&((*list)->firstWord), string);
    }
    else
    {
        if((*list)->letter > string[0])
        {
            struct cNode *aux = (struct cNode *)malloc(sizeof(struct cNode));
            aux->nextLetter = *list;
            *list = aux;
            aux->letter = string[0];
            add(&((*list)->firstWord), string);
        }
        else
        {
            struct cNode *currentLetter = *list;
            while(currentLetter->nextLetter != NULL && string[0] > currentLetter->letter)
            {
                currentLetter = currentLetter->nextLetter;
            }

            if(string[0] != currentLetter->nextLetter->letter)
            {
                struct cNode *aux = (struct cNode *)malloc(sizeof(struct cNode));
                aux->letter = string[0];
                aux->
            }
            else
            {

            }
        }
    }
}

int main()
{

    return 0;
}

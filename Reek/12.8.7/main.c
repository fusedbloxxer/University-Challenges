#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concordance_list.h"

// FUNCTIONEAZA!

void addNode(struct node **head, char *string)
{
    if(*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->word = (char *)malloc(sizeof(char) * strlen(string) + 1);
        strcpy((*head)->word, string);
        (*head)->nextWord = NULL;
    }
    else
    {
        if(strcmp((*head)->word, string) == 0) return;
        if(strcmp((*head)->word, string) > 0)
        {
            struct node *aux = (struct node*)malloc(sizeof(struct node));
            aux->nextWord = *head;
            aux->word  = (char *)malloc(sizeof(char) * strlen(string) + 1);
            strcpy(aux->word, string);

            *head = aux;
        }
        else
        {
            struct node *currentWord = *head;
            while(currentWord->nextWord != NULL && strcmp(string, currentWord->nextWord->word) > 0)
            {
                currentWord = currentWord->nextWord;
                if(strcmp(currentWord->word, string) == 0) return;
            }
            if(currentWord->nextWord == NULL)
            {
                struct node* aux = (struct node*)malloc(sizeof(struct node));
                aux->nextWord = currentWord->nextWord;
                aux->word  = (char *)malloc(sizeof(char) * strlen(string) + 1);
                strcpy(aux->word, string);

                currentWord->nextWord = aux;
            }
            /// Insert only if the word is new. Avoiding duplicate words.
            else if(strcmp(string, currentWord->nextWord->word) < 0)
            {
                struct node* aux = (struct node*)malloc(sizeof(struct node));
                aux->nextWord = currentWord->nextWord;
                aux->word  = (char *)malloc(sizeof(char) * strlen(string) + 1);
                strcpy(aux->word, string);

                currentWord->nextWord = aux;
            }
        }
    }
}
void addConcordance(struct cNode** list, char *string)
{
    char c;
    if(string[0] >='A' && string[0]<='Z')
        c = string[0] + 32;
    else
        c = string[0];

    if(*list == NULL)
    {
        *list = (struct cNode *)malloc(sizeof(struct cNode));
        (*list)->nextLetter = NULL;
        (*list)->firstWord =  NULL;
        (*list)->letter = c;

        addNode(&((*list)->firstWord), string);
    }
    else
    {
        if((*list)->letter > c)
        {
            struct cNode *aux = (struct cNode *)malloc(sizeof(struct cNode));
            aux->nextLetter = *list;
            aux->firstWord  = NULL;
            aux->letter = c;

            *list = aux;
            addNode(&((*list)->firstWord), string);
        }
        else if((*list)->letter == c)
        {
            addNode(&((*list)->firstWord), string);
        }
        else
        {
            struct cNode *currentLetter = *list;
            while(currentLetter->nextLetter != NULL && c > currentLetter->nextLetter->letter)
            {
                currentLetter = currentLetter->nextLetter;
            }

            if(currentLetter->nextLetter == NULL || c != currentLetter->nextLetter->letter)
            {
                struct cNode *aux = (struct cNode *)malloc(sizeof(struct cNode));
                aux->nextLetter = currentLetter->nextLetter;
                aux->firstWord = NULL;
                aux->letter = c;

                currentLetter->nextLetter = aux;
                addNode(&(aux->firstWord), string);
            }
            else
            {
                addNode(&(currentLetter->nextLetter->firstWord), string);
            }
        }
    }
}
void printConcordanceList(struct cNode *head)
{
    while(head != NULL)
    {
        printf("->%c", head->letter);
        struct node *subHead = head->firstWord;
        while(subHead != NULL)
        {
            printf("\n   ->%s ", subHead->word);
            subHead = subHead->nextWord;
        }
        printf("\n");
        head = head->nextLetter;
    }
}
void removeJunk_ToLower(char *c) {
    while(*c != '\0') {
        if(*c >= 'A' && *c <= 'Z') *c = *c + 32;
        else if(*c < 'a' || *c > 'z') {
            char *p = c;
            while(*p != '\0') {
               *p = *(p + 1);
                p = p + 1;
            }
            c = c - 1;
        }
        c = c + 1;
    }
}
int main()
{
    struct cNode *list = NULL;
    FILE* f = fopen("date.in", "r");
    char buffer[1000];
    while(fgets(buffer, 1000, f) != NULL)
    {
        char *p = strtok(buffer, " ");
        while(p)
        {
            char *f = (char *)malloc(sizeof(char) * strlen(p));
            strcpy(f, p);
            removeJunk_ToLower(f);
            if(strlen(f) > 0)
            addConcordance(&list, f);
            p = strtok(NULL, " ");

            free(f);
        }
    }
    printConcordanceList(list);
    return 0;
}

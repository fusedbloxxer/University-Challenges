struct node{
    char *word;
    struct node *nextWord;
};
struct cNode{
    char letter;
    struct node *firstWord;
    struct cNode *nextLetter;
};

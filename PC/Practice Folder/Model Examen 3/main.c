#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct TPlayer
{
    int id;
    char * nume;
    int crtLife;
    int victorii;
    void (*action)(struct TPlayer*, ...);
};
struct TFight
{
    struct TPlayer *p1, *p2;
    int dmg, time;
};
struct TGame
{
    int nrCrtPlayers, nrMaxPlayers, nrCrtFights, nrMaxFights, maxLife;
    struct TPlayer* players;
    struct TFight* fights;
};
void action(struct TPlayer* p1, ...)
{
    va_list paramList;
    va_start(paramList, p1);

    if(p1 == NULL)
    {
        struct TPlayer* p2 = va_arg(paramList, struct TPlayer *);
        p2->crtLife = p2->crtLife - va_arg(paramList, int);
    }
    else
    {
        p1->crtLife += va_arg(paramList, int);
    }
    va_end(paramList);
}
int compareTime(void *a, void *b)
{
    struct TFight* al = (struct TFight *)a;
    struct TFight* bl = (struct TFight *)b;

    return al->time - bl->time;
}
void sortByTime(struct TGame* game)
{
    qsort(game->fights, game->nrCrtFights, sizeof(struct TFight), compareTime);
}
struct TPlayer* computeKills(struct TGame *game, int *max)
{
    struct TPlayer* MVP = NULL;
    for(int i = 0; i < game->nrCrtFights; i++)
    {
        game->fights[i].p1->action(NULL, game->fights[i].p2, game->fights[i].dmg);

        if(game->fights[i].p2->crtLife <= 0)
        {
            game->fights[i].p2->crtLife = game->maxLife;
            game->fights[i].p1->victorii++;
        }
        if(i == 0)
        {
            *max = game->fights[i].p1->victorii;
            MVP  = game->fights[i].p1;
        }
        else if(*max < game->fights[i].p1->victorii)
        {
            *max = game->fights[i].p1->victorii;
            MVP  = game->fights[i].p1;
        }
    }
    return MVP;
};
struct TGame* createGame(int nrMaxPlayers, int nrMaxFights, int maxLife)
{
    struct TGame *newGame = (struct TGame *)malloc(sizeof(struct TGame));
    newGame->players = (struct TPlayer *)malloc(sizeof(struct TPlayer) * nrMaxPlayers);
    newGame->fights  = (struct TFight  *)malloc(sizeof(struct TFight)  * nrMaxFights);
    newGame->nrMaxPlayers = nrMaxPlayers;
    newGame->nrCrtPlayers = nrMaxPlayers;
    newGame->nrMaxFights = nrMaxFights;
    newGame->maxLife = maxLife;
    newGame->nrCrtFights = 0;

    FILE* file = fopen("nume.txt", "r");
    for(int i = 0; i < nrMaxPlayers; i++)
    {
        newGame->players[i].nume = (char *)malloc(sizeof(char) * 31);
        fscanf(file, "%s", newGame->players[i].nume);
        newGame->players[i].crtLife = maxLife;
        newGame->players[i].action = action;
        newGame->players[i].victorii = 0;
        newGame->players[i].id = i + 1;
    }
    fclose(file);
    file = fopen("fights.txt", "r");
    int player1, player2, dmg, time;
    while(fscanf(file, "%d", &player1) != -1)
    {
        fscanf(file, "%d", &player2);
        fscanf(file, "%d", &dmg);
        fscanf(file, "%d", &time);

        newGame->fights[newGame->nrCrtFights].p1 = &newGame->players[player1 - 1];
        newGame->fights[newGame->nrCrtFights].p2 = &newGame->players[player2 - 1];
        newGame->fights[newGame->nrCrtFights].time = time;
        newGame->fights[newGame->nrCrtFights].dmg = dmg;
        newGame->nrCrtFights++;
    }
    fclose(file);
    return newGame;
}
void gameSummary(struct TGame *game)
{
    sortByTime(game);

    /// Reset Fights.
    for(int i = 0; i < game->nrMaxPlayers; i++)
    {
        game->players[i].crtLife = game->maxLife;
        game->players[i].victorii = 0;
    }

    FILE *output = fopen("output.txt", "w");
    for(int i = 0; i < game->nrCrtFights; i++)
    {
        game->fights[i].p1->action(NULL, game->fights[i].p2, game->fights[i].dmg);
        fprintf(output, "(%d)(%s) ii provoaca (%d) lui (%s)", game->fights[i].time, game->fights[i].p1->nume, game->fights[i].dmg, game->fights[i].p2->nume);

        if(game->fights[i].p2->crtLife <= 0)
        {
            game->fights[i].p2->crtLife = game->maxLife;
            game->fights[i].p1->victorii++;

            fprintf(output, "(%s este omorat)(%s) are %d %s", game->fights[i].p2->nume, game->fights[i].p1->nume, game->fights[i].p1->victorii, (game->fights[i].p1->victorii == 1)?"victorie":"victorii");
        }
        fprintf(output, "\n");
    }
    fclose(output);
}
int main()
{

    int MAX_KILLS;
    struct TPlayer* MVP;
    struct TGame* GAME = createGame(14, 17, 5);

    MVP = computeKills(GAME, &MAX_KILLS);
    printf("MVP: (%d)%s with %d %s and %d remaining health\n\n", MVP->id, MVP->nume, MVP->victorii, (MVP->victorii == 1)?"kill":"kills", MVP->crtLife);

    gameSummary(GAME);

    return 0;
}

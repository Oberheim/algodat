// Datorn börjar alltid i denna version
// och högarna innehåller 3 4 5 stickor
#include <stdio.h>
//#include <conio.h>
#include <string.h>
#include <limits.h>

#define MAXMOVES 12
#define WHITE 1
#define BLACK 0
#define INFINITY INT_MAX

struct position
{
    int brade[3];
    int color;
};

int makemovelist(struct position p,int lista[][2])
{
    int n=-1,i,j;
    for(i=0; i<3; i++)
        for(j=1; j<=p.brade[i]; j++)
        {
            n++;
            lista[n][0]=i;
            lista[n][1]=j;
        }
    return ++n;
}

void stallningut(struct position p)
{
    int i;
    printf("|");
    for(i=0; i<3; i++)
        printf("| %d ",p.brade[i]);
    printf("||\n");
}

void init(struct position *p)
{
    int i;
    for(i=0; i<3; i++) {
//        p->brade[i]=3+i;
        p->brade[i] = rand()%6+3;
    }
    p->color=WHITE;
}

int checkwin(struct position p)
{
    int ok=1,i;
    for(i=0; i<3; i++)
        if(p.brade[i]!=0)
            ok=0;
    return ok;
}

void domove(int m[],struct position *p)
{
    p->brade[m[0]]-=m[1];
}

void undomove(int m[],struct position *p)
{
    p->brade[m[0]]+=m[1];
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int minimax(struct position p, int d)
{
    int moves[MAXMOVES][2];
    int i,n,bestvalue,value;

    n=makemovelist(p,moves);
    if(n==0)
    {
        if (p.color==WHITE)
            return -INFINITY;
        else
            return INFINITY;
    }

    if(p.color==WHITE)
        bestvalue=-INFINITY;
    else
        bestvalue=INFINITY;

    for(i=0; i<n; i++)
    {
        domove(moves[i],&p);
        if (p.color==WHITE) p.color=BLACK;
        else p.color=WHITE;
        value=minimax(p,d-1);
        if (p.color==WHITE) p.color=BLACK;
        else p.color=WHITE;
        undomove(moves[i],&p);
        if(p.color==WHITE)
            bestvalue=max(value,bestvalue);
        else
            bestvalue=min(value,bestvalue);
    }
    return bestvalue;
}


int main(void)
{
    srand(time(NULL));
    int svar;
    printf("VILL DU BORJA (1 = ja, 0 = nej)? ");
    scanf("%d", &svar);

    int i,n,moves[MAXMOVES][2],poang,max,md;
    int a,h;
    struct position p;
    init(&p);
    stallningut(p);
    while(!checkwin(p))
    {
        // VIT DRAR
        n=makemovelist(p,moves);
        if(svar == 0) {
            if(n>0 && !checkwin(p))
            {
                max=-INFINITY;
                p.color=BLACK;
                for(i=0; i<n; i++)
                {
                    domove(moves[i],&p);
                    poang=minimax(p,100);
                    undomove(moves[i],&p);
                    if (poang>=max)
                    {
                        max=poang;
                        md=i;
                    }
                }
                domove(moves[md],&p);
                stallningut(p);
                svar = 1;
            }
            // SVART DRAR
            if(!checkwin(p))
            {
                printf("Hog  : ");
                scanf("%d",&h);
                printf("Antal: ");
                scanf("%d",&a);
                p.brade[h-1]-=a;
                stallningut(p);
                svar = 0;
            }
        } else if(svar == 1){

            // SVART DRAR
            if(!checkwin(p))
            {
                printf("Hog  : ");
                scanf("%d",&h);
                printf("Antal: ");
                scanf("%d",&a);
                p.brade[h-1]-=a;
                stallningut(p);
                svar = 0;
            }
            if(n>0 && !checkwin(p))
            {
                max=-INFINITY;
                p.color=BLACK;
                for(i=0; i<n; i++)
                {
                    domove(moves[i],&p);
                    poang=minimax(p,100);
                    undomove(moves[i],&p);
                    if (poang>=max)
                    {
                        max=poang;
                        md=i;
                    }
                }
                domove(moves[md],&p);
                stallningut(p);
                svar = 1;
            }
        }
    }
    printf("*** KLAR ***");
//  getch();
}

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#define ANTAL_BARN 8
#define ANTAL_ORD 11

struct barn
{
    char n;
    struct barn *next;
};
typedef struct barn barn;

barn *skapa(int n)
{
    barn *start,*ps,*p;
    int i;
    start=(barn *) malloc(sizeof(barn));
    start->n='A';
    ps=start;
    for(i=2; i<=n; i++)
    {
        p=(barn *) malloc(sizeof(barn));
        p->n='A'+i-1;
        ps->next=p;
        ps=p;
    }
    p->next=start;
    return start;
}

int rakna(barn *p)
{
    barn *slut;
    int m=0;
    slut=p;
    do
    {
        p=p->next;
        m++;
    }
    while(p!=slut);
    return m;
}

barn* raknaut(barn* b, int n)
{
    barn *z, *prev, *after;
    z = b;
    prev = b;
    after = b;
    int k;
    for(k=0;k<n;k++) {
        if(k == 0) {                //Required in order to count the first child as 0
            after = after->next;
        } else if (k==1) {
            z = z->next;
            after = after->next;
        } else {
            z = z->next;
            prev = prev->next;
            after = after->next;
        }
    }
    printf("Ungen som ska ut ar: %c\n",z->n);
//    printf("Ungen innan honom ar: %c\n",prev->n);
//    printf("Ungen efter %c ar: %c\n",z->n,after->n);

    //Removes the unwanted child
    prev->next = after;
    z = NULL;

    return after;
}
// Här är ett lämpligt ställe att placera
// funktionen RAKNAUT

int main(void)
{
    barn *start;
    start=skapa(ANTAL_BARN);
    do
    {
        start=raknaut(start,ANTAL_ORD);
    }
    while(rakna(start)>1);
    printf("%c blev kvar till sist\n",start->n);
    return 1;
//  getch();
}

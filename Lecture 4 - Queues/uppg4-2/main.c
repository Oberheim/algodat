#include <stdio.h>
#include <string.h>
#include "header.h"

void init(bil **liststart)
{
    FILE *fil;
    char op[20];
    char innamn[20];
    int antal=0;
    fil=fopen("Trafik.dat","rt");
    *liststart=NULL;
    if (fil!=NULL)
    {
        while(!feof(fil))
        {
            fscanf(fil,"%s",op);
            if(strcmp(op,"BACKUP")==0 || strcmp(op,"DRIVES")==0)
                fscanf(fil,"%d",&antal);
            else
                fscanf(fil,"%s",&innamn);

            if(strcmp(op,"ARRIVES")==0)
                arrives(liststart,innamn);
            else if(strcmp(op,"DRIVES")==0)
                drives(liststart,antal);
            else if(strcmp(op,"BACKUP")==0)
                backup(*liststart,antal);
//            skrivlista(*liststart);
        }
        fclose(fil);
    }
}

void arrives(bil **liststart, char innamn[])
{
    bil *ny;
    ny=(bil *) malloc(sizeof(bil));
    strcpy(ny->namn,innamn);
    ny->next=NULL;
    if (*liststart==NULL)
    {
       *liststart=ny;
       sist=ny;
    }
    else
    {
       sist->next=ny;
       sist=ny;
    }
}

void drives(bil **liststart, int antal)
{
    int i = 0;
    while(i++<antal)
    {
        bil *tmp = *liststart;
        *liststart = tmp->next;
        free(tmp);
    }
}

void backup(bil *liststart, int antal)
{
    int i=0;
    bil *n = liststart;
    while(i<antal)
    {
        while(n->next != sist)
        {
            n = n->next;
        }
        free(sist);
        sist = n;
        sist->next = NULL;
        n=liststart;
        i++;
    }
}

void skrivlista(bil *p)
{
   int n=0;
   printf("------------------------------\n");
   while(p!=NULL){
      n++;
      printf("%s ",p->namn);
      if (p->next==NULL) printf("\n");
      p=p->next;
   }
}

int main()
{
    bil *bilstart;
    init(&bilstart);
    skrivlista(bilstart);
}

#ifndef HEADER_H_
#define HEADER_H_

typedef struct bil
{
   char namn[20];
   struct bil *next;
}bil;

bil *sist;

void init(bil **);
void drives(bil **,int);
void backup(bil *, int);
void arrives(bil **, char innamn[]);
void skrivlista(bil *);

#endif

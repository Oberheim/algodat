#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct namntyp
{
    char namn[10];
    struct namntyp *nasta;
} namntyp;

void laes_in(namntyp **l1,char filnamn[])
{
    FILE *fil;
    struct namntyp *a,*forra;
    char namn[10];

    fil=fopen(filnamn,"rt");
    *l1=NULL;
    while(!feof(fil))
    {
        fscanf(fil,"%s",namn);
        if (!feof(fil))
        {
            if (*l1!=NULL) forra=a;
            a=(namntyp *)malloc(sizeof(namntyp));
            a->nasta=NULL;
            strcpy(a->namn,namn);
            if (*l1==NULL)
                *l1=a;
            else
                forra->nasta=a;
        }
    }
    fclose(fil);
}

void skriv_ut(namntyp *sl)
{
    namntyp *a;
    while (sl!=NULL)
    {
        printf("%s\n",sl->namn);
        a=sl;
        sl=sl->nasta;
        free(a);
    }
}

void merge(namntyp *l1,namntyp *l2,namntyp **sl)
{
    struct namntyp *z;
    z = NULL;
    *sl = NULL;

    while (l1 != NULL && l2 != NULL) {
        if(*sl == NULL) {
            *sl = (namntyp *)malloc(sizeof(namntyp));
            z = *sl;
        } else {
            z->nasta = (namntyp *)malloc(sizeof(namntyp));
            z = z->nasta;
        }
        if(strcmp(l1->namn,l2->namn) < 0) {
            strcpy(z->namn, l1->namn);
            l1 = l1->nasta;
        } else {
            if(strcmp(l2->namn,l1->namn) < 0){
                strcpy(z->namn, l2->namn);
                l2 = l2->nasta;
            } else if (strcmp(l1->namn, l2->namn) == 0) {
                //They are the same
                strcpy(z->namn,l1->namn);
                l1 = l1->nasta;
                z->nasta = (namntyp *)malloc(sizeof(namntyp));
                z=z->nasta;
                strcpy(z->namn,l2->namn);
                l2 = l2->nasta;
            }
        }
    }
    //If one of them isn't finished
//    while(l1 != NULL) {
//        z -> nasta = (namntyp *)malloc(sizeof(namntyp));
//        z = z->nasta ;
//        strcpy(z->namn, l1->namn);
//        l1 = l1->nasta ;
//    }
//    while(l2 != NULL) {
//        z ->nasta = (namntyp *)malloc(sizeof(namntyp));
//        z = z->nasta;
//        strcpy(z->namn,l2->namn);
//        l2 = l2->nasta;
//    }
}

int main(void)
{
    namntyp *lista1,*lista2,*slutlista;
    laes_in(&lista1,"UPPG3B.DAT");
    laes_in(&lista2,"UPPG3D.DAT");
    merge(lista1,lista2,&slutlista);
    printf("Lista1: \n");
    skriv_ut(lista1);
    printf("\nLista2:\n");
    skriv_ut(lista2);
    printf("\nSLUTLISTA\n");
    skriv_ut(slutlista);

    return 1;
}

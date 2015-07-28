#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct objekt
{
    int nyckel;
    struct objekt *left,*right;
};
typedef struct objekt objekt;

// Rekusiv insättning
objekt *InsertTree(objekt *p,objekt ny)
{
    objekt *z,*q;

    if(p==NULL)
    {
        z=(objekt *) malloc(sizeof(objekt));
        *z=ny;
        z->left=NULL;
        z->right=NULL;
        return z;
    }
    else if(ny.nyckel < p->nyckel)
        p->left=InsertTree(p->left,ny);
    else
        p->right=InsertTree(p->right,ny);
    return p;
}

// Borttagning av hela trädet
void DeleteTree(objekt **x)
{
    objekt *z;

    if(*x!=NULL)
    {
        if((*x)->right==NULL)
        {
            z=*x;
            *x=(*x)->left;
            free(z);
        }
        else if((*x)->left==NULL)
        {
            z=*x;
            *x=(*x)->right;
            free(z);
        }
        else
        {
            z=(*x)->right;
            while(z->left!=NULL)
                z=z->left;
            z->left=(*x)->left;
            z=*x;
            *x=(*x)->right;
            free(z);
        }
    }
}


// Skriv ut trädet
void PrintTree(objekt *x)
{
    if(x!=NULL)
    {
        PrintTree(x->left);
        printf("%d ",x->nyckel);
        PrintTree(x->right);
    }
}

int height(objekt *x)
{
    int hl,hr,h;

    if(x == NULL)
    {
        return -1;
    }
    hl = height(x->left);
    hr = height(x->right);
    if(hl >= hr)
    {
        h = 1 + hl;
    }
    else
    {
        h= 1+ hr;
    }
    return h;
}

int main(void)
{
    objekt *start,ny,*tmp;
    int k;
    int cnt = 0;
    srand(time(NULL));
    int s;
    for(s=0;s<1000;s++) {
        start=NULL;
        for(k=1; k<=1000; k++)
        {
            ny.nyckel = rand()%1000000+1;
            ny.left=NULL;
            ny.right=NULL;
            start=InsertTree(start,ny);
        }
        if(height(start) == 20) {
            cnt++;
        }
        while (start!=NULL)
            DeleteTree(&start);
    }
    printf("\n\nTotal times tree height was 20 (of 1000): %d\n",cnt);
    float perc = ((float)cnt/10.0);
    printf("Percent: %.2f %\n",perc);
}

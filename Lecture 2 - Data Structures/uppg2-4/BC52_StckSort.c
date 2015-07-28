#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "stack.h"

int main(void)
{
    int i,j,*pek,n,*lista;
    FILE *fil;

    InitStack(20,sizeof(int),100);
    fil=fopen("TAL.DAT","rt");
    fscanf(fil,"%d",&n);


    lista=(int *)calloc(n,sizeof(int));
    for(i=0; i<n; i++)
        fscanf(fil,"%d",&lista[i]);
    fclose(fil);

    for(i=0; i<n; i++)
        Push(lista[i]/10,&lista[i]);
    free(lista);

    for(j=0; j<10; j++)
    {
        while(!IsEmpty(j))
        {
            pek=(int *)Pop(j);
            Push(*pek%10+10,pek);
        }
        for(i=10; i<20; i++)
            while(!IsEmpty(i))
            {
                pek=(int *)Pop(i);
                printf("%d ",*pek);
            }
    }
    printf("\n");
    //getch();          //getch funkar ju inte i linux :(
    int zxc;
//    scanf("%d",&zxc);
}

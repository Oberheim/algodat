#include <stdio.h>
#include <math.h>


int MergeSort(int a)
{
    if(a==1)
        return 0;
    return MergeSort((int)ceil(a/2.0))+MergeSort((int)a/2.0)+a-1;
}


int main()
{
    int input;

    printf("Hur m\x86nga tal ska sorteras? ");  scanf("%d",&input);
    printf("F\x94r detta kr\x84vs %d j\x84mf\x94relser",MergeSort(input));
}

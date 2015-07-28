#include <stdio.h>

int valor[8];

int main()
{
    int moneyz, max = 0, maxMoneyz = 0, num, maxn;
    int valorer[8] = {1000,500,100,50,20,10,5,1};
    for(moneyz=1;moneyz<=1000;moneyz++)
    {
        num = greedyChange(valorer,moneyz);
        if(num>=max)
        {
            if(num>max)
                maxn = 0;
            max = num;
            maxn++;
            maxMoneyz = moneyz;
            printf("%d %d\n",moneyz, max);
        }
    }
    printf("%d numbers requieres %d bills/coins\n",maxn,max);
//    printf("%4d\t|\t%d",maxMoneyz,max);
    return 0;
}

int greedyChange(int val[], int n)
{
//    printf("%4d\t|\t",n);
    int i,j, sum = 0;
    for(i=0;i<8;i++)
        valor[i]=0;
    for(i=0;i<8;i++)
    {
        while(n>=val[i])
        {
            n-=val[i];
            sum++;
//            printf("%d ",val[i]);
        }
    }
//    printf("\n");
    return sum;
}

int rakna()
{
    int i, sum = 0;
    for(i=0;i<8;i++)
        sum+=valor[i];
    return sum;
}

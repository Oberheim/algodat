#include<stdio.h>

int bionomkoeff(int n, int m)
{
    if(m==0||m==n)
        return 1;
    if(m==1||m==n-1)
        return n;
    return bionomkoeff(n-1,m-1)+bionomkoeff(n-1,m);
}

int main()
{
    printf("%d",bionomkoeff(13,4));
}

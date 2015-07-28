#include <stdio.h>
#define N 8
#define S -3
#define E 5
#define W -6

int main()
{
    int x,y;
    printf("Start x: ");
    scanf("%d",&x);
    printf("Start y: ");
    scanf("%d",&y);
    printf("Det kravs minst %d promenader\n",go(x,y));
}

int go(int x, int y)
{
    int step = 0;
    if(x>0) {
        if(x+W>=0)
            step = 1 + go(x+W,y);
        else
            step = 1 + go(x+E,y);
    }
    else if(x<0) {
        if(x+E<=0)
            step = 1 + go(x+E,y);
        else
            step = 1 + go(x+W,y);
    }
    if(y>0) {
        if(y+S>=0)
            step = 1 + go(x,y+S);
        else
            step = 1 + go(x,y+N);
    }
    else if(y<0) {
        if(y+N<=0)
            step = 1 + go(x,y+N);
        else
            step = 1 + go(x,y+S);
    }
    return step;
}

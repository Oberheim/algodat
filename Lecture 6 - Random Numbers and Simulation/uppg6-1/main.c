#include <stdio.h>
#define PI 3.1415927

float psuedoRand(float in, int i);

int main()
{
    int found = 0;
    float i = 1;
    int s;
    while(!found && i < 10000)
    {
        s = (int)(psuedoRand(i/10000,0)*10000);
        printf("i: %.4f, s: %d\n",i,s);
        if(i == s)
        {
            printf("%.4f\n",i/10000);
            found = 1;
        }
        i++;
    }
}

float psuedoRand(float in, int i)
{
    float a = PI + in;
    a = a * a * a * a * a;
    a = a-(int)a;
    if(i==4)
        return a;
    return psuedoRand(a, i+1);
}

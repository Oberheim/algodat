#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STORLEK 30
int tab[STORLEK][STORLEK],max=0;

void berakna(int rad,int kol,int s){
  if(rad==STORLEK-1){
    s=s+tab[rad][kol];
    if(s>max) max=s;
  }
  else {
    berakna(rad+1,kol,  s+tab[rad][kol]);
    berakna(rad+1,kol+1,s+tab[rad][kol]);
  }
}

int main(void){
    FILE *infil;
    int i,j;
    for(i=0;i<STORLEK;i++)
        for(j=0;j<=i;j++)
            tab[i][j]=rand()%100;
    berakna(0,0,0);
    float timeElapsed = (float)clock();
    printf("cps: %d\n",CLOCKS_PER_SEC);
    float multi = 30/(timeElapsed/CLOCKS_PER_SEC);
    printf("maxnivaer pa %.2f sek: %d\n",timeElapsed/(1000000), max);
    printf("Tillvagagansatt: man raknar ut time ellapsed, tar kvoten mellan 30 och \n");
    printf("time ellapsed for att fa en konstant som man sedan multiplicerar med \n");
    printf("antalet nivaer o darmed far teoretiskt maxantal\n");
    printf("Pa 30 sekunder hinner den med ca %f nivaer\n",max*multi);
}

//Uppgift 1.17 DAS GAME

#include <stdio.h>

int best = 1000;

int playGame(int b, int v, int r, int nr,int sw) {
	if(sw == 1) {
		b--;
		v+=3;
		r++;
	} else if(sw == 2) {
		v--;
		b+=3;
		r+=4;
	} else if(sw == 3) {
		r--;
		v+=2;
		b+=2;
	}

	if(b == r && b == v) {
		if(nr < best) {
			best = nr;
		}
		//printf("WIN\n");
		return nr;
	}
	nr++;
	if(nr <= 15) {
		playGame(b,v,r,nr,1);
		playGame(b,v,r,nr,2);
		playGame(b,v,r,nr,3);
	}
	return 0;
}


int main(void) {
	int b,v,r;
	printf("Hur många blåa? ");
	scanf("%d",&b);
	printf("Hur många vita? ");
	scanf("%d",&v);
	printf("Hur många röda? ");
	scanf("%d",&r);

	playGame(b,v,r,0,0);

	printf("Det behövs minst %d växlingar för att nå målet\n",best);
}

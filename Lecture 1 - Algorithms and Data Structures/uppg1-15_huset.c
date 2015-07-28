#include <stdio.h>
int best = 1000;

int huset(int v, int u, int n, int m, int cur,int cnt, int dir) {

	//Check if done
	if(cur == m) {
	//printf("Win, cnt: %d, best: %d\n",cnt,best);
 	       if(cnt < best) {
               		best = cnt;
               }
               return 1;
        }
        if(cnt > 25)    {
        	//TTL surpassed
               return 0;
        }
	cnt++;
	if(dir == 1) {
		//Uppåt
		if(cur + u <= v) {
			cur +=u;
		} else {
			cur = v;
		}
	} else if (dir == 2) {
		//Nedåt
		if(cur - n >= 1) {
			cur -= n;
		} else {
			cur = 1;
		}
	}
	huset(v,u,n,m,cur,cnt, 1);
	huset(v,u,n,m,cur,cnt, 2);
}

int main(void) {
	int v,u,n,m;

//	v = 78;
//      u = 15;
//      n = 8;
//	m = 35;file:///home/oberheim/Documents/Programming/Algodat/frl1/uppg1-16_plankan.c


	printf("Hur många våningar har huset: ");
	scanf("%d",&v);
	printf("Förlyttningar uppåt: ");
	scanf("%d", &u);
	printf("Förflyttnignar nedåt: ");
	scanf("%d", &n);
	printf("Till vilken våning ska du: ");
	scanf("%d", &m);
	huset(v,u,n,m,1,0,1);
	//huset(v,u,n,m,1,0,2);
	printf("Best score: %d\n", best);
}

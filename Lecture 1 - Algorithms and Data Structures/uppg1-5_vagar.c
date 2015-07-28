//Uppgift 1.5 (2 points)
#include <stdio.h>

int antalVagar(int m, int n) {
	int v = 0;
	if(m == 0 && n == 0) {
		return 1;
	} else {
		if(m > 0) {
			v += antalVagar(m-1,n);
		}
		if(n > 0) {
			v += antalVagar(m,n-1);
		}
		return v;
	}
}


int main(void) {
	int m,n;
	for (m = 10; m <= 10; m++) {
		for(n = 10; n <= 10; n++) {
			printf("%d,%d: %d\n", m,n,antalVagar(m,n));
		}
	}
}

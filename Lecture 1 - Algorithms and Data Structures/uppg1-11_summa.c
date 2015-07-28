#include <stdio.h>

int part(int n, int m) {
	if( n == 1 && m >= 0 || m == 0 || m == 1) {
		return 1;
	} else if(m < 0) {
		return 0;
	} else {
		return part(n-1,m) + part(n,m-n);
	}
}

int main(void) {
	int n,m;
	printf("n: ");
	scanf("%d", &n);
	printf("m: ");
	scanf("%d", &m);
	printf("%d,%d: %d\n",n,m,part(n,m));
}

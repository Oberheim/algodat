#include <stdio.h>

int phi(int n) {
	int count = 0;
	int v = n-1;
	while(v > 0) {
		if(GCD(n,v) == 1) {
			count++;
		}
		v--;
	}
	return count;

}

int GCD(int a, int b) {
	if(b == 0) {
		return a;
	} else {
		return GCD(b, a%b);
	}
}

int main(void) {
	int tal;
	printf("Tal: ");
	scanf("%d",&tal);

	printf("EULER: %d\n", phi(tal));

	return 0;
}

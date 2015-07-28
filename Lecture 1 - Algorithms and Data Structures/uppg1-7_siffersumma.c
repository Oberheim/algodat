#include <stdio.h>

int ss(int t) {
	int sum=t%10;
	if(t > 10) {
		sum +=ss(t/10); 
	}
	return sum;
}

int main(void) {
	int nr;
	printf("NR: ");
	scanf("%d",&nr);
	printf("SS: %d\n",ss(nr));
}

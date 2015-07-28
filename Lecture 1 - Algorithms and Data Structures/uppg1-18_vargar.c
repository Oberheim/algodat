#include <stdio.h>

int fail = 1;

int vargar(int n, int opt) {
	int success = 0;
	if(n == 42) {
		fail = 0;
		return 1;
	}
	if(n < 42) {
		//Fail, drop
		return 0;
	}
	int p1, p2;
	p1 = n%10;
	p2 = (n%100)/10;

	if(opt == 1 && n%2 == 0) {
		n = n / 2;
		success = 1;
	} 
	if(opt == 2) {
		if(p1*p2 != 0 && n%3 == 0) {
			n = n - p1*p2;
			success = 1;
		} else if(p1*p2 != 0 && n%4 == 0) {
			n = n - p1*p2;
			success = 1;
		}
	}
	if(opt == 3) {
		if(n%5 == 0 && n-42 > 42) {
			n = n - 42;
			success = 1;
		}
	}

	//Kollar om den inte uppfyller några krav
	if(success == 0) {
		return 0;
	}

	//printf("n: %d\n", n);
	vargar(n,1);
	vargar(n,2);
	vargar(n,3);
}

int main(void) {
	int nr;

	printf("Hur många vargar finns nu? ");
	scanf("%d",&nr);
	vargar(nr,1);
	vargar(nr,2);
	vargar(nr,3);

	if(fail == 1) {
		printf("Målet kan inte nås\n");
	} else if(fail == 0) {
		printf("Målet kan nås\n");
	}
}

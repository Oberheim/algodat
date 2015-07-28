// Uppgift 1.12 Kvadratroten
#include <stdio.h>
#include <math.h>

float ROT(float n, float a, float e) {
	if(fabsf(a*a-n) < e) {
		return a;
	} else {
		return ROT(n, (float)((a*a+n)/(2*a)), e);
	}
}

int main(void) {
	float a = 1, n, e = 0.001;
	printf("ROT: ");
	scanf("%f",&n);
	printf("ANSW: %f\n",ROT(n,a,e));

}

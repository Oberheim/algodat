//Uppgift 1.13, för att kompilera:
//gcc uppg1-13_bitstring.c -lm -o 1-13_bitstr

#include <stdio.h>
#include <string.h>
#include <math.h>

char* create_nr(int nr, int n) {
	static char str[1000] = {""};
	int nrleft = 0;
	int current_val = nr;
	//printf("Input nr: %d\n",nr);
	while(n - nrleft != 0 ) {
		int hp = (int)pow(2,n-nrleft-1);
		if(n - nrleft >= 0) {
			//int hp = (int)pow(2,n-nrleft-1);
			//printf("POW: %d\n", hp);
			//Does hp fit in the number?
			if(current_val - hp >= 0) {
				strcat(str,"1");
				current_val -= hp;
			} else {
				strcat(str,"0");
			}
			nrleft++;
		}
	}
	strcat(str,", ");
	printf("B4 create_nr out: %s\n",str);
	return str;
}

char* BitStr(char s[1000], int strl, int nr, int n) {
	strl++;
	printf("strl: %d\n",strl);
	static char s2[64] = {""};
	if(strl <=  pow(2,n)) {
		//char s2[64] = {""};
	//	printf("NR in bitstr: %d\n",nr);
		strcpy(s2,create_nr(nr,n));
		printf("create_nr output: %s\n",s2);
	//	strcat(s,s2);
		nr++;
		BitStr(s, strl,nr,n);
	} else {
		return s2;
	}
}

int main(void) {

	int n;
	printf("Which power do you want? ");
	scanf("%d",&n);
	char s2[1000];
	char s[1000] = {""};
	strcpy(s2,BitStr(s,0,0,n));
	printf("DONE: %s\n",s2);
}


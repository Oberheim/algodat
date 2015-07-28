//Uppgift 1.13, för att kompilera:
//gcc uppg1-13_bitstring.c -lm -o 1-13_bitstr


/**
* Felet p� uppgiften under redovisningen var helt enkelt att charsen inte kunde lagra tillr�ckligt stora str�ngar f�r alla siffror.
* S� om du vill testa h�gre potens s� f�r du �ndra STRSIZE (3000 r�cker inte f�r 9)
**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define STRSIZE 3000

/**
* Tar som input vilken siffra som ska g�ras till bin�rt och vilken potens den ska vara.
* Returnar en str�ng med alla siffror hittils inklussive den nya.
* Inser nu att det hade r�ckt f�r uppgiften att bara printa ut siffrorna en i taget ist�llet f�r att g�ra en fet str�ng som skrivs ut i slutet, doh.
**/
char* create_nr(int nr, int n) {
	static char str[STRSIZE] = {""};
	int nrleft = 0;
	int current_val = nr;
	while(n - nrleft != 0 ) {
		int hp = (int)pow(2,n-nrleft-1);
		if(n - nrleft >= 0) {
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
	return str;
}

/**
* Loopar igenom alla tal och l�gger in dem i str�ngen
**/
char* BitStr(char s[STRSIZE], int strl, int nr, int n) {
	strl++;
	static char s2[STRSIZE] = {""};
	if(strl <=  pow(2,n)) {
		strcpy(s2,create_nr(nr,n));
		nr++;
		BitStr(s, strl,nr,n);
	} else {
		return s2;
	}
}

int main(void)
{
	int n;
	printf("Which power do you want? ");
	scanf("%d",&n);
	char s2[STRSIZE];
	char s[STRSIZE] = {""};
	strcpy(s2,BitStr(s,0,0,n));
	printf("DONE:\n%s\n",s2);
}


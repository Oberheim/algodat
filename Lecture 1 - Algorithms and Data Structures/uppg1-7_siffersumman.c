/* Siffersumman (2 poäng). Om t = 1765 så är ss = 19 och om t = 128956 så är ss = 31, eller hur?
Efter en stunds funderande hade du förstås kommit på att ss är siffersumman till t (summan av de
i talet ingående siffrorna).
Skriv nu en rekursiv funktion SIFFER SUMMA ( T ) som bestämmer ss för ett heltal t > 0. */

#include<stdio.h>
int main(void) {

    int tal = 2102;
    printf("\nSIFFERSUMMA av %d\n",tal);
    printf("Svar: %d \n", SifferSumma(tal));

}

int SifferSumma(int t) {
    int n = 10;
    static int m = 0;

    if(t > 0) {
        if(t == 0)
            return 1;
        else {
            m = m + t%10;
            return SifferSumma(t/10);
        }
    } else
        return m;
}

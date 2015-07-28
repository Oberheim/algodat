/**
* Uppgift 1.14 i AlgoDat HI1029
* Author: Alexander Heimonen
* Last modified: 2012-06-08
**/

#include <stdio.h>
#include <String.h>

int best = 1000;
//För att korta ner tiden det tar att köra programmet, dock vågar jag inte sätta det jättehögt, man vet aldrig med dina
//exempel... (se rad 69 och 73)
int limit = 30;

/**
* funcB byter plats på första och andra bokstaven, det går till ganska enkelt genom att ursprungssträngen
* kopieras över till en ny temporär sträng, str2, en char plockar ut första bokstaven, sedan sätts str2[1] till
* str2[0] och str[1] blir då a.
* Strängen returnas
**/
char *funcB(char str[6])
{
    char str2[6];
    strcpy(str2,str);
    char a;

    a = str2[1];
    str2[1] = str2[0];
    str2[0]=a;
    strcpy(str,str2);

    return str;
}

/**
* Fungerar på exakt samma sätt som funcB, men sista platsen sätts längst fram och så steppas alla bokstäver en plats uppåt.
**/
char *funcS(char str[6])
{
    char str2[6];
    strcpy(str2,str);
    char a;

    a = str2[4];
    int i;
    for(i=3;i>=0;i--)
    {
        str2[i+1] = str2[i];
    }
    str2[0] = a;
    strcpy(str,str2);
    return str;
}

/**
* En ganska standard rekursiv funktion, alla möjliga sätt att lösa det på testas.
* När strängen blir abcde eller ABCDE har en lösning hittats och sedan kollas om det är bästa lösningen.
**/
int robocop(char s[5],int nrofmoves)
{
    char str[6];
    strcpy(str,s);
    if(strcmp(str,"abcde") == 0 || strcmp(str,"ABCDE") == 0)
    {
        if(best > nrofmoves)
        {
            printf("%s nr: %d\n",str,nrofmoves);
            best = nrofmoves;
            limit = best;
            return 0;
        }
    }
    if(nrofmoves < limit)
    {
        robocop(funcB(str),nrofmoves+1);
        robocop(funcS(str),nrofmoves+1);
    }
    return 0;
}

/**
* Input av användaren och den rekursiva funktionen sätts igång, resultat printas.
**/
int main()
{
    char input[6];
    printf("Input: ");      scanf("%s",&input);
    robocop(input,0);
    printf("%d antal moves",best);
}

/**
* Uppgift 1.14 i AlgoDat HI1029
* Author: Alexander Heimonen
* Last modified: 2012-06-08
**/

#include <stdio.h>
#include <String.h>

int best = 1000;
//F�r att korta ner tiden det tar att k�ra programmet, dock v�gar jag inte s�tta det j�tteh�gt, man vet aldrig med dina
//exempel... (se rad 69 och 73)
int limit = 30;

/**
* funcB byter plats p� f�rsta och andra bokstaven, det g�r till ganska enkelt genom att ursprungsstr�ngen
* kopieras �ver till en ny tempor�r str�ng, str2, en char plockar ut f�rsta bokstaven, sedan s�tts str2[1] till
* str2[0] och str[1] blir d� a.
* Str�ngen returnas
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
* Fungerar p� exakt samma s�tt som funcB, men sista platsen s�tts l�ngst fram och s� steppas alla bokst�ver en plats upp�t.
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
* En ganska standard rekursiv funktion, alla m�jliga s�tt att l�sa det p� testas.
* N�r str�ngen blir abcde eller ABCDE har en l�sning hittats och sedan kollas om det �r b�sta l�sningen.
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
* Input av anv�ndaren och den rekursiva funktionen s�tts ig�ng, resultat printas.
**/
int main()
{
    char input[6];
    printf("Input: ");      scanf("%s",&input);
    robocop(input,0);
    printf("%d antal moves",best);
}

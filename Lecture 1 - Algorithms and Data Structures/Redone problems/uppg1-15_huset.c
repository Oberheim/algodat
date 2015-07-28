#include <stdio.h>
int best = 1000;
// TTL limit är satt till 50, om programmet tar orimligt lång tid på sig att hitta en lösning så dra ner TTL, eller om lösningen har högre
// antal moves än 50 så är det bara att öka den.
int limit = 50;


/**
* En ganska enkel rekursion där alla möjliga fall testas fram till en TTL eller resultat. Om hissen försöker röra sig någonstans där den inte kan
* åka (t.ex. 11 våningar uppåt från våning 19 när det bara finns 20) så returnas den (från varje fall startas en rörelse både uppåt och nedåt).
* u: uppåt
* n: nedåt
* v: antalet våningar
* m: destinationsvåning
* cnt: antal förflyttningar
* dir: riktning
**/
int huset(int v, int u, int n, int m, int cur,int cnt, int dir)
{
    //Check if done
    if(cur == m)
    {
        if(cnt < best)
        {
            best = cnt;
            limit = best;
        }
        return 1;
    }
    if(cnt > limit)
    {
        //TTL surpassed
        return 0;
    }
    //Alla krav färdigtestade, nu ökas countern och läget för hissen ändras (beroende på om den ska uppåt eller nedåt)
    cnt++;
    if(dir == 1)
    {
        //Uppåt
        if(cur + u <= v)
        {
            cur +=u;
        }
        else
        {
            return 0;
        }
    }
    else if (dir == 2)
    {
        //Nedåt
        if(cur - n >= 1)
        {
            cur -= n;
        }
        else
        {
            return 0;
        }
    }
    huset(v,u,n,m,cur,cnt, 1);
    huset(v,u,n,m,cur,cnt, 2);
}

/**
* main, alla scans till behövd data, rekursionfunktionen startas o resultat printas.
**/
int main(void)
{
    int v,u,n,m;

    printf("Hur många våningar har huset: ");
    scanf("%d",&v);
    printf("Förlyttningar uppåt: ");
    scanf("%d", &u);
    printf("Förflyttnignar nedåt: ");
    scanf("%d", &n);
    printf("Till vilken våning ska du: ");
    scanf("%d", &m);
    huset(v,u,n,m,1,0,1);
    //huset(v,u,n,m,1,0,2);
    printf("Best score: %d\n", best);
}

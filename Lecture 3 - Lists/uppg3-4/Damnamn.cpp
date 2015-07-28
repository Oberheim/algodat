#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct dam{
   char namn[15];
   struct dam *next;
}dam;

void init(dam **liststart){
   FILE *fil;
   char innamn[15];
   dam *ny,*sist;
   fil=fopen("DAMNAMN.DAT","rt");
   *liststart=NULL;
   if (fil!=NULL){
      while(!feof(fil)){
         fscanf(fil,"%s",innamn);
         if (!feof(fil)){
            ny=(dam *) malloc(sizeof(dam));
            strcpy(ny->namn,innamn);
            ny->next=NULL;
            if (*liststart==NULL){
               *liststart=ny;
               sist=ny;
            }
            else{
               sist->next=ny;
               sist=ny;
            }
         }
      }
      fclose(fil);
   }
}

void skrivlista(dam *p){
   int n=0;
   printf("\n------------------------------\n");
   while(p!=NULL){
      n++;
      printf("%s ",p->namn);
      if (n%7==0) printf("\n");
      p=p->next;
   }
}

int tabortnamn(dam **p,char n[]){
    if(*p == NULL)
        return 0;

    dam *tmp = *p, *prev = *p, *after = *p;


    while(tmp != NULL) {
        if(strcmp(tmp->namn,n) == 0) {
            if(tmp->next == NULL) {
                prev->next = NULL;
                free(tmp);
            } else {
                if(prev->next == tmp->next) {
                    (*p) = tmp->next;
                    free(tmp);
                } else {
                    prev->next = tmp->next;
                    free(tmp);
                }
            }
        }

        prev = tmp;
        tmp = tmp->next;
    }

}

int tabortplats(dam **p,int n){
    if(*p == NULL) {
        return 0;
    }
    dam *tmp = *p, *before = *p, *after = *p;
    int k;

    if(n == 1) {
        (*p) = (*p)->next;
        free(tmp);
        return 1;
    }

    for(k = 0;k <= n;k++) {
        if(k == 0) {

        } else {

            if(k == n) {
                before->next = after;
                tmp = NULL;
                free(tmp);
                return 1;

            } else {

                before = tmp;
                tmp = tmp->next;
                if(tmp->next != NULL) {
                    after = tmp->next;
                } else {
                    after = NULL;
                }
            }
        }

    }
    return 0;
}

int antal(dam *p){

    if(p == NULL) {
        return 0;
    }
    dam *tmp = p;
    int nr = 0;
    while(tmp != NULL) {
        tmp = tmp->next;
        nr++;
    }

    return nr;
}

void placeraforst(dam **p,char n[]){
    if(*p == NULL) {
        return;
    }
    dam *tmp;
    tmp = (dam *)malloc(sizeof(dam));
    strcpy(tmp->namn, n);
    tmp->next = (*p);
    (*p) = tmp;
}

void placerasist(dam **p,char n[]){
    if(*p == NULL) {
        return;
    }

    dam *tmp,*tmp2 = *p;

    tmp = (dam *)malloc(sizeof(dam));
    strcpy(tmp->namn,n);
    tmp->next = NULL;

    while(tmp2 != NULL) {
        if(tmp2->next == NULL) {
            tmp2->next = tmp;
            return;
        }
        tmp2 = tmp2->next;
    }

}

int placeraefter(dam *p,char nytt[],char gam[]){
    if(p == NULL) {
        return 0;
    }
    dam *ny;

    ny = (dam *)malloc(sizeof(dam));
    strcpy(ny->namn, nytt);
    ny->next = NULL;

    dam *fore = p,*efter = p,*tmp = p;
    int k = 0, found = 0;
    while(tmp != NULL && efter != NULL) {
        if(k == 0) {
            efter = efter->next;
        } else if(k == 1) {
            efter = efter->next;
            tmp = tmp->next;
        } else {
            if(tmp->next != NULL) {
                efter = efter->next;
            } else {
                efter = NULL;
            }
            tmp = tmp->next;
            fore = fore->next;
        }
        if(strcmp(tmp->namn, gam) == 0) {

            tmp->next = ny;
            ny->next = efter;
            found = 1;
        }
        k++;
    }
    if(found == 1) {
        return 1;
    } else {
        return 0;
    }
}

int placerafore(dam **p,char nytt[],char gam[]){
    if(*p == NULL) {
        return 0;
    }
    dam *ny;

    ny = (dam *)malloc(sizeof(dam));
    strcpy(ny->namn, nytt);
    ny->next = NULL;

    dam *fore = *p,*efter = *p,*tmp = *p;
    int k = 0, found = 0;
    while(tmp != NULL && efter != NULL) {
        if(k == 0) {
            efter = efter->next;
        } else if(k == 1) {
            efter = efter->next;
            tmp = tmp->next;
        } else {
            if(tmp->next != NULL) {
                efter = efter->next;
            } else {
                efter = NULL;
            }
            tmp = tmp->next;
            fore = fore->next;
        }
        if(strcmp(tmp->namn, gam) == 0) {

            if(fore->next == tmp ->next) {
                ny->next = (*p);
                (*p) = ny;
                found = 1;
            } else {
                fore->next = ny;
                ny-> next = tmp;
                found = 1;
            }
        }
        k++;
    }
    if(found == 1) {
        return 1;
    } else {
        return 0;
    }
}

int finns(dam *aktuell,char n[]){
    if(aktuell == NULL) {
        return 0;
    }

    dam *tmp = aktuell;
    int flag = 0;
    while(tmp != NULL) {
        if(strcmp(tmp->namn,n) == 0) {
            flag = 1;
        }
        tmp = tmp->next;
    }
    return flag;
}

dam* fore(dam *p,char n[]){
    if(p == NULL) {
        return NULL;
    }
    dam *tmp = p,*fore = p;
    int k = 0;
    while(tmp != NULL) {
        if(k == 0) {
            tmp = tmp->next;
        } else {
            if(strcmp(tmp->namn,n) == 0) {
                return fore;
            }

            tmp = tmp->next;
            fore = fore->next;
        }
        k++;
    }
    return NULL;
}

dam* efter(dam *p,char n[]){
    if(p == NULL) {
        return NULL;
    }

    dam *tmp = p;
    while(tmp != NULL) {

        if(strcmp(tmp->namn,n) == 0) {
            return tmp->next;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main(void){
   dam *liststart,*p;
   int r;
   init(&liststart);
   skrivlista(liststart);
   r=tabortnamn(&liststart,"Daniella");
   skrivlista(liststart);
   r=tabortplats(&liststart,8);
   skrivlista(liststart);
   printf("\nAntal namn i listan ar %d\n",antal(liststart));
   placeraforst(&liststart,"Ann");
   skrivlista(liststart);
   placerasist(&liststart,"Asa");
   skrivlista(liststart);
   r=placeraefter(liststart,"Karin","Gun");
   skrivlista(liststart);
   r=placerafore(&liststart,"Nelly","Ann");
   skrivlista(liststart);
   r=finns(liststart,"Ulla");
   if(r==1)
      printf("\nPersonen finns\n");
   else
      printf("\nPersonen finns inte\n");
   p=fore(liststart,"Jenny");
   printf("\n%s finns före Jenny\n",p->namn);
   skrivlista(liststart);
   p=efter(liststart,"Kristina");
   printf("\n%s finns efter Kristina\n",p->namn);
   skrivlista(liststart);

   return 1;
}

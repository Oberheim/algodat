#include <stdio.h>
//#include <conio.h>
#include "list.h"

void skrivut(person *start)
{
    person *top = start;
    person *down;
    while(top!=NULL)
    {
        down = top;
        while(down->down!=NULL)
            down = down->down;
        printf("%s\n",down->namn);
        top = top->right;
    }
}

void main(void){
  person *start;
  start=laesin();
  skrivut(start);
  tabort(start);
//  getch();
}
